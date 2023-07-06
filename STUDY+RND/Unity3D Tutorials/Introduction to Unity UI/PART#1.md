# [Introduction to Unity UI – Part 1](https://www.kodeco.com/6570-introduction-to-unity-ui-part-1)
    ● In this first part of a three-part tutorial series,
    ● you’ll get acquainted with the Unity UI, enabling you to add custom user interfaces to your games.
    ● Apr 24 2019, C# 6, Unity 2018.3, Unity
    ● By Ben MacKinnon.
[***Download materials***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-1.zip)



*Update February 2019: This tutorial was updated to Unity 2018.3 by Ben MacKinnon. Original post by [**Kirill Muzykov**](https://twitter.com/kmuzykov).*

　

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
    > 　　![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/buildPlatform-529x500.png)
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

　

## Custom Anchors

You can manually move anchors to a custom position. The presets are just for your convenience.

- ***Note:***
    > - *You might find yourself in a situation where the translation gizmo covers the anchor icon, making it impossible to select the anchor.*
    > - *This is where another Unity UI tool comes in handy. If you are familiar with Unity, you’ll know that the keyboard shortcuts Q, W, E and R toggle the Hand, Move, Rotate and Scale tools respectively. With the new UI system, the RectTool was added under the shortcut T. With the RectTool selected, the Gizmo changes to a 2D scale/move box that acts as you would expect from any graphics editing software.*
    >
    > 　　![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/rectTool.png)


Now you can grab the anchors and move them around.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/25.gif)

See how the image moves to the right when you resize the Canvas? It moves only a little in relation to the right edge of the Canvas because these anchors are set to 25% width of the Canvas.

　

## Splitting Anchors

You can split anchors to make them stretch a UI Element horizontally, vertically or both.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/26.gif)

- ***Note:***
    > - *You’re not actually resizing the Canvas when dragging one if its edges.*
    > - *In fact, you can’t resize the Canvas this way.*
    > - *Look for the word Preview next to the cursor when you try to resize it.*
    > - *Use this technique to experiment and see how your UI elements adapt to different screen sizes.*
    >
    > 　　![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/27.png)

　

## Rect Transform Depends on the Current Anchors Setting

Depending on the anchors setting, the Rect Transform provides different ways to control the size and position of your UI element.

If you set anchors to a single point without stretching, you’ll see the **Pos X, Pos Y, Width** and **Height** properties.

However, if you set anchors in a way that stretches your UI element, you’ll get **Left** and **Right** instead of Pos X and Width if you set it to stretch horizontally. You’ll get **Top** and **Bottom** instead of Pos Y and Height if you set it to stretch vertically.

In this screenshot, **Header**’s Anchors are set to **middle-stretch**. This means the image stays in the middle of the Canvas vertically and stretches horizontally.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/28-650x236.png)

　

## Pivot

The final property to discuss in the Rect Transform component is **Pivot**.

The pivot is the point around which all transformations are made. In other words, if you change your UI element position, you also change the pivot point position. If you rotate your UI element, it’ll rotate around that point.

The pivot uses normalized coordinates. This means that it goes from 0 to 1 for both height and width, where **(0, 0)** is the bottom left corner and **(1, 1)** is the top right corner.

- ***Note:***
    > - *You can also set Pivot outside the UI Element bounds.*
    > - *In this case, Pivot will be outside the (0, 0) – (1, 1) range.*
    > - *This can be useful. For example, you might want to rotate your object around some point in the scene.*
    > - *To alter the pivot, you must make sure the Pivot/Center button is toggled to Pivot like so:*
    >
    > 　　![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/29.png)

You can change pivot in the Rect Transform component in the Inspector, or you can use the **Rect Tool**.

The following two images demonstrate a UI element with the same Pos X and Pos Y values, yet each shows different placement in the scene.

The first image shows the pivot at its default value of (0.5, 0.5), which is the center of the UI element. The position is set to (0, 0) and the anchors are set to **top-left**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/31-650x216.png)

- ***Note:***
    > - *It’s important to understand that the position of a UI element is set relative to the anchors.*
    > - *A (0, 0) position means the distance from anchors, which are set to the top-left corner of the Canvas.*

Now, take a look at the second image. As you can see, the position is still at (0, 0), but since the pivot is set to the bottom-left corner (0, 0) you can see that the image’s bottom corner, and not the center, is now at the Canvas’s top-left.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/32-650x228.png)

It’s harder to show how pivot affects rotation and size using a still image, so here are a few animations:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/33.gif)

Notice how the image rotates around the pivot point, indicated by a blue circle, which is an element you can freely move.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/34.gif)

- ***Note:*** *Hold down the Option / ALT key while scaling to scale around the pivot point.*

As you can see, the pivot also affects how your UI Element resizes.

- ***Note:***
    > - *When you change the size of a UI element, you don’t change its scale.*
    > - *Instead, you change its size using Width and Height or Top, Right, Left, and Bottom paddings.*
    > - *Be aware that there are a few differences between size and scale.*
    > - *For example, size can’t be negative, but scale can be. Also, using a negative scale value will flip your UI element.*
    > - *In most cases, you should only change the size of your UI elements.*


　

# # Placing a Header Image

Phew! That was a lot of information about Rect Transform, Anchors and Pivot. Believe me, you’ll be grateful you spent the time working through the exercise, as these concepts are essential to creating awesome UI in your games.

Going forward, you’ll concentrate on creating the menu scene. The rest of this tutorial will go by in the blink of an eye!

All those manipulations exhausted the poor little header. It’s time to place it where it should be and leave it alone to recover.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/35.png)

Before you continue, re-enable **Background** if you disabled it to see the Canvas border.

Select **Header** in the Hierarchy and set its properties in the Inspector as follows:

- 1\) Click **Set Native Size** to reset the size, as you probably messed with it while playing around with the pivot.
- 2\) Set **Anchors** to **top-center**.
- 3\) Set **Pos X** to **0** and **Pos Y** to **-100**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/36-400x500.png)

You should see something like this in your Scene view:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/37.png)

That’s it! Now, leave the header image alone. It’s a little tired, too. :]

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/38.png)

Now that you know about anchors and pivots, go back to the background image. Did you notice that when you added the aspect ratio fitter, some of the floor texture is now cropped off screen? We can use the **Aspect Ratio Fitter** in combination with the pivot to fix this:

- 1\) Disable the **Aspect Ratio Fitter**
- 2\) Set the **Pivot** to **(X:0.5, Y:0)**
- 3\) Re-enable the **Aspect Ratio Fitter**

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/aspectPivot.gif)

Now, not only does the background always fit the size of the phone, the floor part will always stay in view!

　

# # Adding the Start Button

Now, that your game has a nice background with a label, it’s time to add some buttons.

From the top bar, choose **GameObject ‣ UI ‣ Button**. This will add a **Button** object to the scene. You should see it in the Hierarchy. If you expand it in the Hierarchy, you’ll see that the button contains a Text child — you’ll learn about these later.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/39.png)

Look at the button in the Inspector, and you’ll see it has the same Image component you used to add the background and the header label.

Additionally, there’s a Button component. In other words, a button is just an image with a child Text element and an attached button script.

- ***Note:*** *The Text element is optional, so if you have a button image with text drawn right into the image, you can delete it.*

　

## Positioning the Button

Now it’s all about positioning and resizing the button. Follow these steps:

- 1\) Select **Button** in the Hierarchy view and **rename it** to **StartButton**.
- 2\) Set its **Anchors** to bottom-stretch, since you want it to stretch horizontally if the screen size changes. Tip: Hold Alt/Cmd and Shift when selecting the anchor to also set the position and pivot.
- 3\) To further customize the anchors, set the X to **(Min:0.2, Max:0.8)**
- 4\) Set both **Left** and **Right** to **123**.
- 5\) Set the **Pivot** to **(X:0.5, Y:0)**
- 6\) Set **Height** to **80**.
- 7\) Set **Pos Y** to **300**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/40-600x500.png)

Then select the nested **Text element** and set its **Text** to **Start Game**. Change the **Font Size** to **32** to make the text of the button larger.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/41-618x500.png)

This is what you should see in the Scene view:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/startButton-650x402.png)

Now you have a button, but it needs a facelift! To make the button look good, you’ll set an image as its background and then use a fancier font.

　

# # 9-Slice Scaling

You set the image for buttons and images in the same way. After all, they use the same component. However, images rarely scale, especially non-uniformly. Buttons, on the other hand, often come in different sizes.

You could create a background image for every single button size in your game, but why waste all that space? You’ll use a technique called **9-Slice scaling**, which allows you to provide one small image that scales to fit all sizes.

There’s no magic involved here. This technique works by creating different images for each of nine zones, all of which scale differently.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/43.png)

This ensures the image will look good at any scale.

　

# # Preparing Button Images

Before you can use a sliced image, you need to set its nine zones. To do this, open the **Menu** folder in the Project window and select **btn_9slice_normal** image.

In the Inspector’s **Import Settings**, set **Texture Type** to **Sprite (2D and UI)** and apply the change. Next, click on the **Sprite Editor** button to open the Sprite Editor view.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/spriteEditor-433x500.png)

In the **Sprite Editor**, set the **Border** values to **L:14, R:14, B:16, T:16**. Remember to click **Apply**!

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/45-309x500.png)

Repeat the same process for the **btn_9slice_highlighted** and **btn_9slice_pressed** images, which you’ll use for different button states.

　

# # Setting Button Images

After preparing all your images, drag them to the corresponding fields in the Inspector. Select **StartButton** in the Hierarchy and follow these steps:

- 1\) Change **Image Type** to **Sliced** in the Image component.
- 2\) Change the **Transition** property in the Button component to **SpriteSwap**.
- 3\) Drag **btn_9slice_normal** to **Source Image** in the Image component.
- 4\) Drag **btn_9slice_highlighted** to **Highlighted Sprite** in the Button component.
- 5\) Drag **btn_9slice_pressed** to **Pressed Sprite** in the Button component.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/buttonSettings-483x500.png)

- ***Note:***
    > - *If you encounter this error message, you probably forgot to set the Border in the Sprite Editor in the Import Settings.*
    >
    > 　　![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/47.png)

Before running the scene and enjoying your cool buttons, you’re going to change the font used by the nested Text label. This will make the button mega-awesome.

　

# # Setting a Custom Font for the Button

Using a custom font is easy. Remember the **Fonts** folder in the package you downloaded and added to the project? Now it’s time to break it out and use one of those fonts.

Select the **Text** element nested within **StartButton** in the Hierarchy. Then open the **Fonts** folder in the Project window and drag the **TitanOne-Regular** font into the **Font** field. Also set the **Color** to white.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/buttonText-554x500.png)

Now run the scene and enjoy your new mega-awesome button! :]

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/startButtonComplete-650x360.png)

　

# # Adding the Settings Button

There are a few things left to do. First, add the Settings button.

You can probably do this yourself, so you’re only getting the size and position of the button to start. The rest is almost identical to they way you created the Start Game button.

- ***Note:*** *The easiest way is to duplicate the button and adjust some properties, but try creating the button from scratch this time.*

These properties of the Settings button are different:
- **Name**: **SettingsButton**
- **Rect Transform**: Left and Right are **173**, Height is **70** and Pos Y is **180**
- **Text**: **Settings**
- **Fontsize**: **24**

If you couldn’t quite do it, just follow these steps:

- 1\) From the top bar, select **GameObject ► UI ► Button**. This will create a Button object in the scene.
- 2\) Select **Button** in the Hierarchy view and **rename it** to **SettingsButton**.
- 3\) Set the button **Anchors** to **bottom-stretch**. Then update the X to **(Min:0.2, Max:0.8)**
- 4\) Set the **Pivot** to **(X:0.5, Y:0)**
- 5\) Set both **Left** and **Right** in **Rect Transform** to **173**.
- 6\) Set **Height** to **70** and **Pos Y** to **180**.
- 7\) Set **Transition** in the Button component to **Sprite Swap**.
- 8\) Make sure to set **Image Type** in the Image component to **Sliced**.
- 9\) Open the **Menu** folder in the Project Browser and drag **btn_9slice_normal** to **Source Image**.
- 10\) Then drag **btn_9slice_highlighted** to **Highlighted Sprite**.
- 11\) And finally, drag **btn_9slice_pressed** to **Pressed Sprite**.
- 12\) Double-click on **Color** inside the Image component and check if **A** is set to **255** to remove any transparency.
    ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/settingsButton-514x500.png)
- 13\) Select the nested **Text** label.
- 14\) Change **Text** to **Settings**.
- 15\) Set **Font Size** to **24**.
- 16\) Change **Color** to **White**.
- 17\) Open the **Fonts** folder in the Project window and drag the **TitanOne-Regular** font into the **Font** field in the Inspector view.
    ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/settingsButtonText-479x500.png)

This is what you should see in the Scene view after adding the Settings button:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/settingsButtonComplete-650x364.png)

Now **Save** your scene.

　

# # Starting the Game

The final task for this part is to click the **Start Game** button and run the second scene in the game itself.

　

## Adding Scenes to Build

Before you can run different scenes, you need to add them to the **Scenes in Build** list in the Project Settings.

To do this, on the menu select **File ‣ Build Settings**. This will open the **Build Settings** dialog. Then open the **Scenes** folder in the Project browser. First, drag the **MenuScene** and then the **RocketMouse** scene to the **Scenes in Build** list.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/buildSettings.png)

Finally, close the Build Settings dialog.

　

## Creating UIManager

Here comes the 5% code part of the tutorial!

When you add an event handler to the button, you need to specify which method to call when you click the button. Since you can’t use static methods, you’ll need to select a public method from a script attached to a GameObject.

From the top bar, choose **GameObject ‣ Create Empty**. Then select **GameObject** in the Hierarchy view and rename it to **UIManager**.

Create a **Scripts** folder inside **RW** and then create a new C# script in it named **UIManager**. Once Unity compiles it, attach it as a component to your **UIManager** GameObject.

This is what you should see in the Hierarchy view and the Inspector view:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/uiManager-650x265.png)

**Double-click** on the **UIManagerScript** in the Inspector to open the script in MonoDevelop. Once the script loads, remove both `Start()` and `Update()`.

Next add the following statement underneath the previous `using` statements.

```
using UnityEngine.SceneManagement;
```

This allows you to load other scenes. Now, add the following:

```
public void StartGame() 
{
    SceneManager.LoadScene("RocketMouse");
}
```

Save the script and move on to the next step:

　

## Calling StartGame When the Button is Clicked

Switch back to Unity and follow these steps:

- 1\) Select **StartButton** in the Hierarchy and scroll down in the Inspector to the **On Click ()** list.
- 2\) Click the + button to add a new item.
- 3\) Drag **UIManager** from the Hierarchy to the newly added item in the list.
- 4\) Click on the dropdown to select the function. Right now, it’s set to **No Function**.
- 5\) In the opened menu, select **UIManagerScript** and the select **StartGame()** in the menu that opens next.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/UIManager.gif)

**Save** the scene and then click the **Play** button to run the game. Click the **Start Game** button in the menu. This should open the game scene.

　

# # Where to Go From Here?

Stuck on any issues? Feel free to download the completed project for this part using the [**Download materials**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-1.zip) button at the top or bottom of this tutorial.

It might feel like you didn’t do much in this last section, but take another look: You set up the UI, added images and buttons, and even wrote the code that starts the game when you click on the button!

In many games, that’s all that comprises the UI.

You also learned a lot about Rect Transform, Anchors and Pivot. Now that you understand them, you’ll be able to move much faster when you apply these skills to your own projects.

In part two of this series, you’ll learn how to animate UI elements, create dialogs, and use controls like Slider and Toggle. By the end of the series, you’ll have a working menu scene.

If you have any questions or comments please leave them below! See you in [**Part 2**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/PART%232.md)!