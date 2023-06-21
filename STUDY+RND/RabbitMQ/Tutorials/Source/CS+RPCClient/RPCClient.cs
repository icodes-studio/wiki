using RabbitMQ.Client;
using RabbitMQ.Client.Events;
using System;
using System.Collections.Concurrent;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

public class RPCClient
{
    private const string QUEUE_NAME = "rpc_queue";
    private readonly IConnection connection;
    private readonly IModel channel;
    private readonly string replyQueueName;
    private readonly EventingBasicConsumer consumer;
    private readonly ConcurrentDictionary<string, TaskCompletionSource<string>> callbacks = new ConcurrentDictionary<string, TaskCompletionSource<string>>();

    public RPCClient()
    {
        var factory = new ConnectionFactory() { HostName = "localhost" };
        connection = factory.CreateConnection();
        channel = connection.CreateModel();

        replyQueueName = channel.QueueDeclare().QueueName;
        consumer = new EventingBasicConsumer(channel);
        consumer.Received += (model, ea) =>
        {
            if (!callbacks.TryRemove(ea.BasicProperties.CorrelationId, out TaskCompletionSource<string>? tcs))
                return;

            var body = ea.Body.ToArray();
            var response = Encoding.UTF8.GetString(body);
            tcs.TrySetResult(response);
        };

        channel.BasicConsume(
          consumer: consumer,
          queue: replyQueueName,
          autoAck: true);
    }

    public Task<string> CallAsync(string message, CancellationToken cancellationToken = default(CancellationToken))
    {
        var body = Encoding.UTF8.GetBytes(message);
        var correlationId = Guid.NewGuid().ToString();
        var tcs = new TaskCompletionSource<string>();

        callbacks.TryAdd(correlationId, tcs);

        IBasicProperties props = channel.CreateBasicProperties();
        props.CorrelationId = correlationId;
        props.ReplyTo = replyQueueName;

        channel.BasicPublish(
            exchange: "",
            routingKey: QUEUE_NAME,
            basicProperties: props,
            body: body);

        cancellationToken.Register(() => callbacks.TryRemove(correlationId, out var tmp));
        return tcs.Task;
    }

    public void Close()
    {
        channel.Close();
        connection.Close();
    }
}

public class RPC
{
    public static void Main(string[] args)
    {
        Console.WriteLine("RPC Client");

        InvokeAsync(args.Length > 0 ? args[0] : "30").Wait();

        Console.WriteLine(" Press [enter] to exit.");
        Console.ReadLine();
    }

    private static async Task InvokeAsync(string number)
    {
        var rpc = new RPCClient();

        Console.WriteLine(" [x] Requesting fib({0})", number);
        var response = await rpc.CallAsync(number.ToString());
        Console.WriteLine(" [.] Got '{0}'", response);

        rpc.Close();
    }
}