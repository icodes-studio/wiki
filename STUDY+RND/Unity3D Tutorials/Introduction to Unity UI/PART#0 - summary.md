# [Introduction to Unity UI](https://www.kodeco.com/6570-introduction-to-unity-ui-part-1)

[***Download materials***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-1.zip)

*Update February 2019: This tutorial was updated to Unity 2018.3 by Ben MacKinnon. Original post by [**Kirill Muzykov**](https://twitter.com/kmuzykov).*

　

## Getting Started

You’ll need some images for backgrounds, buttons and other UI elements, as well as a few fonts for the labels and buttons. Don’t worry, you won’t have to draw anything yourself or scour the web for the right assets. I’ve prepared a special package that has everything you need. You’re welcome. :]

To get the package, and the starter project files, click on the [**Download Materials**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-1.zip) button at the top or bottom of this tutorial.

This is all you need!

　

## Creating MenuScene

**Open** the **Introduction to Unity UI Part 1 Starter** project in Unity.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/starter_editor-1.png)

The RocketMouse game is already set up, and all the assets for it are in its own folder. You’ll be working out of the **RW** folder, which contains a **Scenes** folder. Now, you’ll create a new scene to work with. From the menu bar, Select **File ‣ New Scene** to create a new empty scene.

It’s best to save the scene right away. Open the **Save Scenes** dialog by choosing **File ‣ Save Scenes**. Then, enter **MenuScene** as the scene name and save it to the **RW / Scenes** folder, right next to the RocketMouse scene.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/save_scene.png)

　

## Importing Images and Fonts

First on your to do list is to add assets to the scene, so unpack the UI Assets package in your file explorer. There you’ll find two folders: **Menu** and **Fonts**.

It’s nice to keep a tidy folder structure, so in the **Project window**, create a new folder inside **RW** named **UI**.

From your file explorer, drag the **Menu** and **Fonts** folders into the **UI** folder in the Project window:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/DragFolders.gif)

Once the assets are in the project, check their import settings. Make sure all the assets in **UI / Menu** are set to the **Sprite (2D and UI)** texture setting.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/import_settings.png)

Woo-hoo! You’ve finished the setup and you’re ready to create your first UI element using the Unity UI system.

　

## Adding Your First UI Element

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

　

## Setting Up the Menu Background Image

The first thing to do is rename your image. In the Hierarchy, select **Image** and rename it to **Background**.

Next, open **RW ‣ UI ‣ Menu** in the Project window and find the **menu_background** image. Drag it to the **Source Image** field of the Image component in **Background** in the Inspector:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/08-650x212.png)

Now you have a background image instead of the default white image. However, it’s not great! It’s too small and the aspect ratio is incorrect.

To fix this, find the **Set Native Size** button in the Inspector and **click** it to set the size to **1136 x 640**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/09.png)

Now it looks like a proper background.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/10.png)

　

## Using the Canvas Scaler

Select **Canvas** in the Hierarchy. Change the component mode to **Scale With Screen Size** and set its **Reference Resolution** to **(X:1136, Y:640)**. Also, slide the **Match Width or Height** all the way to the right, or simply enter 1 in the input field.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/13.png)

After making those changes, you’ll see the full background image, even in a small Game view window.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/14-650x472.png)

select the **Background** and add an **Aspect Ratio Fitter** component. It will automatically set the **Aspect Ratio** value to the current ratio of the image’s Rect Transform. Switch the **Aspect Mode** to **Envelope Parent**. The image will automatically resize to once again fill the whole screen.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/aspectRatio-650x247.png)

　

## Adding a Header Image

Before moving on to buttons and other UI controls, you’ll add the header image. For this exercise, you’ll use a non-fullscreen image to demonstrate a few other important concepts of Unity’s new UI system.

Open the Scene view, and from the top bar, select **GameObject ‣ UI ‣ Image**. This will add another image as a child of Canvas:

- ***Note:*** *If you can’t see the image in the Scene view, set its Pos X and Pos Y properties to 0 to center it.*

Now, turn that white rectangle into an actual image by following these steps:

- 1\) Select **Image** in the Hierarchy and rename it to **Header**.
- 2\) Open the **Menu** folder in the Project window and search for the **header_label** image.
- 3\) Drag the image to the **Source Image** field on the Inspector.
- 4\) Click **Set Native Size** in the Inspector.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/17-650x211.png)

　

## Placing a Header Image

Select **Header** in the Hierarchy and set its properties in the Inspector as follows:

- 1\) Click **Set Native Size** to reset the size, as you probably messed with it while playing around with the pivot.
- 2\) Set **Anchors** to **top-center**.
- 3\) Set **Pos X** to **0** and **Pos Y** to **-100**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/36-400x500.png)

You should see something like this in your Scene view:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/37.png)

Did you notice that when you added the aspect ratio fitter, some of the floor texture is now cropped off screen? We can use the **Aspect Ratio Fitter** in combination with the pivot to fix this:

- 1\) Disable the **Aspect Ratio Fitter**
- 2\) Set the **Pivot** to **(X:0.5, Y:0)**
- 3\) Re-enable the **Aspect Ratio Fitter**

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/aspectPivot.gif)

Now, not only does the background always fit the size of the phone, the floor part will always stay in view!

　

## Adding the Start Button

Now, that your game has a nice background with a label, it’s time to add some buttons.

From the top bar, choose **GameObject ‣ UI ‣ Button**. This will add a **Button** object to the scene. You should see it in the Hierarchy. If you expand it in the Hierarchy, you’ll see that the button contains a Text child — you’ll learn about these later.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/39.png)

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

　

## Preparing Button Images

Before you can use a sliced image, you need to set its nine zones. To do this, open the **Menu** folder in the Project window and select **btn_9slice_normal** image.

In the Inspector’s **Import Settings**, set **Texture Type** to **Sprite (2D and UI)** and apply the change. Next, click on the **Sprite Editor** button to open the Sprite Editor view.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/spriteEditor-433x500.png)

In the **Sprite Editor**, set the **Border** values to **L:14, R:14, B:16, T:16**. Remember to click **Apply**!

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/45-309x500.png)

Repeat the same process for the **btn_9slice_highlighted** and **btn_9slice_pressed** images, which you’ll use for different button states.

　

## Setting Button Images

After preparing all your images, drag them to the corresponding fields in the Inspector. Select **StartButton** in the Hierarchy and follow these steps:

- 1\) Change **Image Type** to **Sliced** in the Image component.
- 2\) Change the **Transition** property in the Button component to **SpriteSwap**.
- 3\) Drag **btn_9slice_normal** to **Source Image** in the Image component.
- 4\) Drag **btn_9slice_highlighted** to **Highlighted Sprite** in the Button component.
- 5\) Drag **btn_9slice_pressed** to **Pressed Sprite** in the Button component.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/buttonSettings-483x500.png)

　

## Setting a Custom Font for the Button

Select the **Text** element nested within **StartButton** in the Hierarchy. Then open the **Fonts** folder in the Project window and drag the **TitanOne-Regular** font into the **Font** field. Also set the **Color** to white.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/buttonText-554x500.png)

Now run the scene and enjoy your new mega-awesome button! :]

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/startButtonComplete-650x360.png)

　

## Adding the Settings Button

There are a few things left to do. First, add the Settings button.

You can probably do this yourself, so you’re only getting the size and position of the button to start. The rest is almost identical to they way you created the Start Game button.

- ***Note:*** *The easiest way is to duplicate the button and adjust some properties, but try creating the button from scratch this time.*

These properties of the Settings button are different:
- **Name**: **SettingsButton**
- **Rect Transform**: Left and Right are **173**, Height is **70** and Pos Y is **180**
- **Text**: **Settings**
- **Fontsize**: **24**

This is what you should see in the Scene view after adding the Settings button:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/settingsButtonComplete-650x364.png)

　

## Adding Scenes to Build

Before you can run different scenes, you need to add them to the **Scenes in Build** list in the Project Settings.

To do this, on the menu select **File ‣ Build Settings**. This will open the **Build Settings** dialog. Then open the **Scenes** folder in the Project browser. First, drag the **MenuScene** and then the **RocketMouse** scene to the **Scenes in Build** list.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/buildSettings.png)

Finally, close the Build Settings dialog.

　

## Creating UIManager

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

　

