# [Introduction to Unity UI – Part 1](https://www.kodeco.com/6570-introduction-to-unity-ui-part-1)
    ● In this first part of a three-part tutorial series,
    ● you’ll get acquainted with the Unity UI, enabling you to add custom user interfaces to your games.
    ● Apr 24 2019, C# 6, Unity 2018.3, Unity
[*Download materials*](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-1.zip)



*Update February 2019: This tutorial was updated to Unity 2018.3 by Ben MacKinnon. Original post by [Kirill Muzykov](https://twitter.com/kmuzykov).*

　

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/rmouse_ui_50.gif)

　

You will love getting gooey with Unity’s new GUI!

Do you remember the old Unity UI system? It required you to write all your GUI code in OnGUI. It was slow, inefficient and programmer-centric, going against the visual nature of Unity. Many developers chose instead to use third party tools such as NGUI.

Thankfully, Unity Technologies listened to community feedback and worked out a new system, released in Unity 4.6.

In this three-part series, you’ll explore Unity’s new UI system by adding an interactive UI to a game called Rocket Mouse.

To satisfy users’ cravings for an engaging UI, you’ll also learn to:

- Animate buttons
- Create a settings dialog that slides into a scene
- Use more GUI controls like Text, Slider, Panel and Mask

　

# # Getting Started

This tutorial is aimed at those familiar with the Unity Editor. Go check out our [**Introduction to Unity**](https://www.raywenderlich.com/772-introduction-to-unity-getting-started-part-1-2?__hstc=149040233.c1ed3c16c256a3843203b44947edda4e.1688513289263.1688513289263.1688513289263.1&__hssc=149040233.46.1688513289263&__hsfp=1152682960) series if this is your first rodeo. The great news is that as this tutorial focuses on the UI system, it is 95% script free!

- ***Note:***
    > - *Keep in mind that this tutorial does not cover the creation of the game itself.*
    > - *The goal here is to provide an introduction to Unity’s UI system and familiarize you with its components.*

You’ll need some images for backgrounds, buttons and other UI elements, as well as a few fonts for the labels and buttons. Don’t worry, you won’t have to draw anything yourself or scour the web for the right assets. I’ve prepared a special package that has everything you need. You’re welcome. :]

To get the package, and the starter project files, click on the [**Download Materials**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-1.zip) button at the top or bottom of this tutorial.

This is all you need!

　

# # Creating MenuScene

**Open** the **Introduction to Unity UI Part 1 Starter** project in Unity.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/starter_editor-1.png)

The RocketMouse game is already set up, and all the assets for it are in its own folder. You’ll be working out of the **RW** folder, which contains a **Scenes** folder. Now, you’ll create a new scene to work with. From the menu bar, Select **File ‣ New Scene** to create a new empty scene.

It’s best to save the scene right away. Open the **Save Scenes** dialog by choosing **File ‣ Save Scenes**. Then, enter **MenuScene** as the scene name and save it to the **RW / Scenes** folder, right next to the RocketMouse scene.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/save_scene.png)

　

# # Importing Images and Fonts

First on your to do list is to add assets to the scene, so unpack the UI Assets package in your file explorer. There you’ll find two folders: **Menu** and **Fonts**.

- ***Note:***
    > - *The **Menu** folder contains background images, buttons, icons and other game art.*
    > - *The game art is provided by [**Game Art Guppy**](http://www.gameartguppy.com/), where you can find a lot of other game art for your practice games.*
    > - *In addition, two fonts from [**DaFont**](http://dafont.com/). are in the **Fonts** folder.*
    > - *You can thank Rodrigo Fuenzalida for the [**Titan One**](http://www.dafont.com/titan-one.font) font and Draghia Cornel for the [**DCC Dreamer**](http://www.dafont.com/dcc-dreamer.font) font.*


It’s nice to keep a tidy folder structure, so in the **Project window**, create a new folder inside **RW** named **UI**.

From your file explorer, drag the **Menu** and **Fonts** folders into the **UI** folder in the Project window:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/DragFolders.gif)

Once the assets are in the project, check their import settings. Make sure all the assets in **UI / Menu** are set to the **Sprite (2D and UI)** texture setting.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/import_settings.png)

Woo-hoo! You’ve finished the setup and you’re ready to create your first UI element using the Unity UI system.

　

# # Adding Your First UI Element

The first element you’ll make is the background image for the menu scene.

From the top bar, select **GameObject ‣ UI ‣ Image**. This adds an object named **Image** to the scene. You should see it in the Hierarchy as a child of **Canvas**. All elements must be placed on a Canvas. If you don’t have one, Unity will create one for you automatically.

Select the Image and set its position to **(X:0, Y:0)**. You’ve just discovered the **Rect Transform**:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/06.png)

- ***Note:***
    > - *The **Rect Transform** is the UI equivalent to Transform.*
    > - *It positions, rotates and scales UI elements within a Canvas.*
    > - *You’ll use it often in this tutorial.*

You’ll set the correct position and size in a moment. Right now, there are three things to be aware of. In the Hierarchy, you’ll see three new objects in the scene:

- 1\) Image
- 2\) Canvas
- 3\) EventSystem

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/07.png)

The **Image** is a non-interactive control that displays a **sprite**, with many options for customization.

For instance, you can apply color to the image, assign a material to it, control how much of the image displays or even animate it on the screen using a clockwise wipe.

The **Canvas** is the root object for all your UI elements. Remember, Unity creates this for you when you add your first UI element. It has multiple properties that allow you to control how your UI renders.

The **EventSystem** processes and routes input events to objects within a scene. It’s also responsible for managing raycasting. As with the Canvas, The UI requires the Event System, so Unity automatically adds it.

　

# # Setting Up the Menu Background Image

The first thing to do is rename your image. In the Hierarchy, select **Image** and rename it to **Background**.

Next, open **RW ‣ UI ‣ Menu** in the Project window and find the **menu_background** image. Drag it to the **Source Image** field of the Image component in **Background** in the Inspector:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/08-650x212.png)

Now you have a background image instead of the default white image. However, it’s not great! It’s too small and the aspect ratio is incorrect.

To fix this, find the **Set Native Size** button in the Inspector and **click** it to set the size to **1136 x 640**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/09.png)

Now it looks like a proper background.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/10.png)

Uh-oh. There’s still one problem.

**Shrink** your Scene view, and you’ll see that the white rectangle of the Canvas covers only part of the image. If you switch to the Game view, you’ll see only a part of the background image, as if the camera is too close to the image to capture it completely.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/11-650x244.png)

- ***Note:***
    > - *The original game design was for iPhones with 3.5- and 4-inch displays.*
    > - *This is why all the game art supports 1136 x 640 and 960 x 640 resolutions.*
    > - *You’ll soon see how the UI can adapt to different game resolutions.*

You’ll tackle this issue by using a **Canvas Scaler**.

　

# # Using the Canvas Scaler

You’ll use the **Canvas Scaler** to adjust the background image display.

First, you need to know that the display is not the result of a bug. From Unity’s point of view, you have the Game view — or viewport — set to such a small size that it displays only the portion of the image that fits within the Game view.

If you were to run the game on a device with a large enough resolution or stretch the Game view to fit the whole image, you would see the entire background image.

Although Unity’s settings make sense in most scenarios, there are times when you need different behavior. An example is when you have a small monitor that doesn’t fit your target device’s resolution.

Additionally, many games support only one resolution. Designers use this reference resolution to dictate sizes, positions and other data. When you develop a game based on a single reference resolution, make sure to enter the designer’s specifications without additional calculations so that the user sees everything as intended.

If you’ve ever ignored your designer’s directions, you know there’s a price to pay. The user experience and varying resolutions are important, but try to keep your designer happy, too. :]

**Canvas Scaler** to the rescue! By default, every Canvas includes Canvas Scaler.

Select **Canvas** in the Hierarchy, and in the Inspector, you should see the Canvas Scaler component:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/12.png)

The Canvas Scaler has three scale modes:

- **Constant Pixel Size:** Makes UI elements retain the same pixel size, regardless of the screen size. This is the default value of the Canvas.
- **Scale With Screen Size:** Sizes and positions UI elements according to a referenced resolution. If the current resolution is larger than the referenced resolution, the Canvas will maintain the reference resolution, while scaling up the elements to match the target resolution.
- **Constant Physical Size:** Positions of the UI elements are specified in physical units such as millimeters or points. This requires the correct reporting of the screen DPI.

Change the component mode to **Scale With Screen Size** and set its **Reference Resolution** to **(X:1136, Y:640)**. Also, slide the **Match Width or Height** all the way to the right, or simply enter 1 in the input field.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/13.png)

After making those changes, you’ll see the full background image, even in a small Game view window.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/14-650x472.png)

Change the Game view resolution to see how your game might look in a different resolution, for example, on iPhone Wide 480×320. You’ll notice it still looks good!

- ***Note:***
    > - *If you don’t see any of the iPhone options, chances are you’re building for a different platform.*
    > - *From the menu bar, select File ‣ Build Settings.*
    > - *In the build settings dialog underneath the platform settings, make sure to select iOS.*
    >
    > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/buildPlatform-529x500.png)
    > - *Unity will reprocess all your assets, and it may take a while.*
    > - *At the end, you should have access to the various iOS screen sizes.*

Now switch to the Scene view, and you’ll see the Canvas’s size doesn’t change when you resize the Scene view. The side edges of the screen are neatly cropped while the central part is fully visible. This is the result of setting **Match Width or Height** to **1**. It works perfectly for your target resolutions.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/15.gif)

These designs are old! Modern phone screens are much wider in Landscape mode. Switch to iPhoneX Landscape mode and we have a whole new problem.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/iphoneX.png)

If you change the **Match Width or Height** value back to zero, it works for iPhone 5 and iPhoneX, but appears letterboxed on iPhone 4.

Fortunately, there are other solutions for this. While the **Canvas Scaler** has two other scaling modes, **Expand** and **Shrink**, there’s another useful component that we can use specifically for background images.

Put the **Canvas Scaler** back to **Match Width or Height** with the value **1**, and set the Game view to iPhoneX. It should like the image above again.

Now, select the **Background** and add an **Aspect Ratio Fitter** component. It will automatically set the **Aspect Ratio** value to the current ratio of the image’s Rect Transform. Switch the **Aspect Mode** to **Envelope Parent**. The image will automatically resize to once again fill the whole screen.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/aspectRatio-650x247.png)

Phew, that was a lot of work. And we’ve only added the background image! But getting the Canvas Scaler and background set up in the proper way is going to make everything easier going forward. After doing this a couple of times ,you’ll find the setup so fast and easy that you’ll barely have time to blink before you’re done.

What about the buttons? What happens when they’re too close to the left or right edge of the screen? You don’t want to crop or hide them.

Fortunately, Unity has a feature that will help you sidestep this rookie mistake. You’ll learn about it soon.

　

# # Adding a Header Image

Before moving on to buttons and other UI controls, you’ll add the header image. For this exercise, you’ll use a non-fullscreen image to demonstrate a few other important concepts of Unity’s new UI system.

Open the Scene view, and from the top bar, select **GameObject ‣ UI ‣ Image**. This will add another image as a child of Canvas:

- ***Note:*** *If you can’t see the image in the Scene view, set its Pos X and Pos Y properties to 0 to center it.*

Now, turn that white rectangle into an actual image by following these steps:

- 1\) Select **Image** in the Hierarchy and rename it to **Header**.
- 2\) Open the **Menu** folder in the Project window and search for the **header_label** image.
- 3\) Drag the image to the **Source Image** field on the Inspector.
- 4\) Click **Set Native Size** in the Inspector.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/17-650x211.png)

Now, you’ll work with the **Rect Transform** component to position the image.

　

# # Rect Transform, Anchors, Pivot and You

If you’ve worked with Unity before or completed [**other Unity tutorials on this website**](http://www.raywenderlich.com/category/unity?__hstc=149040233.c1ed3c16c256a3843203b44947edda4e.1688513289263.1688513289263.1688513289263.1&__hssc=149040233.46.1688513289263&__hsfp=1152682960), you may have had some exposure to the Transform component. If not, that’s fine. Transform is a tool that can position, rotate and scale objects in a scene. Here’s what it looks like:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/18.png)

You’ll see the **Transform** component when you select any type of non-UI **GameObject** in your Hierarchy view. However, if you select any UI element, for example, Header, you’ll see a different component named **Rect Transform**.

As you can see, Transform and Rect Transform look different. Additionally, the **Rect Transform** can change the way it looks, depending on its anchor settings. For example, it can look like this:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/20-612x500.png)

Here, instead of Pos X, Pos Y, Width and Height, you have Left, Top, Right and Bottom.

Are you wondering about the anchor setting that changes the look of **Rect Transform** so dramatically? Keep reading!

　

## Anchors

Setting anchors is a simple, elegant and powerful way to control the position and size of your UI elements relative to their parent. It’s especially handy when you have to resize the parents.

When you set anchors, you specify several positions in the parent, usually one in each corner of the parent’s UI element Rect. When this happens, your UI element will try to maintain a uniform distance to the anchor points, forcing it to move or resize along with its parent.

To see different **Anchors Presets**, select **Header** in the Hierarchy and click on the rectangle above the **Anchors** field in the Rect Transform component.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/22-341x500.png)

After clicking, you’ll see various Anchors Presets. These are the most common settings for anchors, but you can customize them. You can also select different horizontal and vertical behavior for your UI element.

This will all make more sense once you work with it. If you look at the next image, which has the background image disabled, you’ll be able to see the Canvas size changes a bit better.

As you can see, the anchors settings control how your UI element adapts to screen size changes.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/23.gif)

The four triangular handles representing anchors resemble a flower. Here’s how it looks with anchors set to the **top-center** preset:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/24.png)

Before you start experimenting with different settings, read through the next section. It’ll help you understand anchors a little better, and you’ll get more out of your experimentation.