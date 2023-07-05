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

　

# Getting Started

This tutorial is aimed at those familiar with the Unity Editor. Go check out our [**Introduction to Unity**](https://www.raywenderlich.com/772-introduction-to-unity-getting-started-part-1-2?__hstc=149040233.c1ed3c16c256a3843203b44947edda4e.1688513289263.1688513289263.1688513289263.1&__hssc=149040233.46.1688513289263&__hsfp=1152682960) series if this is your first rodeo. The great news is that as this tutorial focuses on the UI system, it is 95% script free!

- ***Note:***
    > - *Keep in mind that this tutorial does not cover the creation of the game itself.*
    > - *The goal here is to provide an introduction to Unity’s UI system and familiarize you with its components.*

You’ll need some images for backgrounds, buttons and other UI elements, as well as a few fonts for the labels and buttons. Don’t worry, you won’t have to draw anything yourself or scour the web for the right assets. I’ve prepared a special package that has everything you need. You’re welcome. :]

To get the package, and the starter project files, click on the [**Download Materials**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-1.zip) button at the top or bottom of this tutorial.

This is all you need!

　

# Creating MenuScene

**Open** the **Introduction to Unity UI Part 1 Starter** project in Unity.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/starter_editor-1.png)

The RocketMouse game is already set up, and all the assets for it are in its own folder. You’ll be working out of the **RW** folder, which contains a **Scenes** folder. Now, you’ll create a new scene to work with. From the menu bar, Select **File ‣ New Scene** to create a new empty scene.

It’s best to save the scene right away. Open the **Save Scenes** dialog by choosing **File ‣ Save Scenes**. Then, enter **MenuScene** as the scene name and save it to the **RW / Scenes** folder, right next to the RocketMouse scene.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/save_scene.png)

　

# Importing Images and Fonts

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

　

# Adding Your First UI Element

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

　

# Setting Up the Menu Background Image

The first thing to do is rename your image. In the Hierarchy, select Image and rename it to Background.

Next, open RW ‣ UI ‣ Menu in the Project window and find the menu_background image. Drag it to the Source Image field of the Image component in Background in the Inspector:



Now you have a background image instead of the default white image. However, it’s not great! It’s too small and the aspect ratio is incorrect.

To fix this, find the Set Native Size button in the Inspector and click it to set the size to 1136 x 640.



Now it looks like a proper background.



Uh-oh. There’s still one problem.

Shrink your Scene view, and you’ll see that the white rectangle of the Canvas covers only part of the image. If you switch to the Game view, you’ll see only a part of the background image, as if the camera is too close to the image to capture it completely.



Note: The original game design was for iPhones with 3.5- and 4-inch displays. This is why all the game art supports 1136 x 640 and 960 x 640 resolutions. You’ll soon see how the UI can adapt to different game resolutions.
You’ll tackle this issue by using a Canvas Scaler.