# [Introduction to Unity UI](https://www.kodeco.com/6570-introduction-to-unity-ui-part-1)

*Update February 2019: This tutorial was updated to Unity 2018.3 by Ben MacKinnon. Original post by [**Kirill Muzykov**](https://twitter.com/kmuzykov).*

[***Download materials***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-1.zip)

　

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

　

## Creating Animation and Animator

Animating buttons is just like animating any other Unity object. You’ll need to add an **Animator** component, create a few animations and set up states and transitions between them.

Here are the steps to success:

- 1\) Select **StartButton** in the Hierarchy.
- 2\) Open the **Animation view** by selecting **Window ▸ Animation ▸ Animation** from the menu.
- 3\) Click on the **Create** button in the Animation view. This will create the Animator and an animation clip.
- 4\) Name the animation **StartButtonSlideOut** and save it in **RW ▸ Animations**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/022.png)

　

## Animating a Button Sliding Out of the Screen

Although you’ll technically make two animations — the button slides out and then back in — you’re a savvy developer! You’ll create one animation and then reverse it.

To create the slide-out animation, follow these steps:

- 1\) Select **StartButton** in the Hierarchy.
- 2\) Make sure the **Animation view** is visible.
- 3\) **Click** on the **1:00** mark in the **timeline** and then click the **Record button**.
- 4\) Change **Anchors** to **top-stretch**.
- 5\) Change **Pos Y** to **60** in the Inspector.
- 6\) Stop the recording by clicking the **red circle button**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/buttonAnimationSetup-650x136.png)

　

## Animating Button Slide In

First, disable the animation looping, since the button should move either up or down and then stop instead of moving back and forth.

To disable looping, open **RW ▸ Animations** in the Project window and select the **StartButtonSlideOut** animation. In the Inspector, uncheck **Loop Time**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/071.png)

Then, select **StartButton** in the Hierarchy and open the **Animator view** by selecting **Window ▸ Animation ▸ Animator**. Right-click on the **StartButtonSlideOut** state and select **Copy**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/copyAnimationState.png)

Then right-click anywhere in the free space inside the Animator view and select **Paste**. This duplicates the `StartButtonSlideOut` state.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/pasteAnimationState.png)

Now, select this duplicated state, which should be something like `StartButtonSlideOut 0`, and rename it to **StartButtonSlideIn** in the Inspector. Additionally, set **Speed** to -1.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/buttonSlideIn.png)

Then, inside the Animator view, right-click on **StartButtonSlideIn** and select **Set as Layer Default State**, since you want the button to start its lifecycle by sliding into the screen and not vice-versa.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/setDefaultAnimation.png)

Next, you need a parameter to control the state of the button. In the left-hand column of the Animator window, click the **Parameters** tab. Next, click the + button and add a new **Bool** parameter named **isHidden**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/animationParameter.png)

Finally, add two transitions between the states. To do this, right-click on the **StartButtonSlideOut** state and select **Make Transition**. Click on the **StartButtonSlideIn** to make a transition.

After that, create a reverse transition by right-clicking **StartButtonSlideIn**, selecting **Make Transition** and clicking on the **StartButtonSlideOut**. This is what you should get in the end:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/animationTransitions.png)

You’re close, but you still need to assign a value to **isHidden** based on which transition is occurring.

Select the transition from `StartButtonSlideOut` to `StartButtonSlideIn`. In the Inspector, click the + in the Conditions panel. Set `isHidden` to **false**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/parameterIn-650x387.png)

Then select the transition that goes in opposite direction, from `StartButtonSlideIn` to `StartButtonSlideOut` and set its **Conditions** to be `isHidden` equals **true**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/parameterOut-650x387.png)

Select **File ▸ Save** to save your work so far and run the scene. You should see your button slide in. Then change `isHidden` manually to make the button slide back.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/play4.gif)

　

## Animating the Settings Button

The Settings button should slide down the screen to make some space in the center for the dialog.

You can animate the settings button yourself! All you need to know is:

- Offscreen **Pos Y** should be **-80**.
- You don’t need to change anchors, since the button is already positioned relative to the bottom edge of the screen.

Give it a try on your own. Feel free to sneak a peek into the spoiler below.

To create the slide down and slide up animation, as well as setup Animator states, follow these steps:

- 1\) Select **SettingsButton** in the Hierarchy.
- 2\) Open the **Animation view**.
- 3\) Click on the **Create** button.
- 4\) Name the animation **SettingsButtonSlideOut** and save it in **RW ▸ Animations**. This will also create the Animation Controller and will add the Animator component to the SettingsButton.
- 5\) In the Animation view, click on the **1:00** mark of the **timeline** and make sure recording is on by clicking on the red circle.
- 6\) In the Inspector, change `SettingsButton` **Pos Y** to **-80**. You don’t need to change anchors this time.
- 7\) **Stop recording** by clicking the red circle button again.
- 8\) Open the **Animations** folder in the Project window. Select **SettingsButtonSlideOut**, and uncheck **Loop Time** in the Inspector.
- 9\) Select **SettingsButton** in the Hierarchy.
- 10\) Now open the **Animator** view.
- 11\) **Copy and paste** the **SettingsButtonSlideOut** state to duplicate it.
- 12\) **Select the duplicated state**, which should be named `SettingsButtonSlideOut 0`. In the Inspector, change its name to **SettingsButtonSlideIn**, and change its **Speed** to **-1**.
- 13\) **Right-click** on the **SettingsButtonSlideIn** state and select **Set as Layer Default State**.
- 14\) **Create a transition** from **SettingsButtonSlideIn to SettingsButtonSlideOut** and then **create a reverse transition**.
- 15\) Add a new **Bool** parameter named `isHidden`.
- 16\) Select the transition from **SettingsButtonSlideOut to SettingsButtonSlideIn**, and in the Inspector, change **Conditions** to contain `isHidden` equals **false**.
- 17\) Select the transition from **SettingsButtonSlideIn to SettingsButtonSlideOut** and change Conditions to contain `isHidden` equals **true**.
- 18\) Select **File ▸ Save** to save your work so far and **run the scene**.

This is what you should get in the end:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/settingsfly.gif)

　

## Triggering Buttons Animation From the Script

Open the **UIManagerScript** that you created in the first tutorial, and add the following instance variables just inside the class definition:

```
public Animator startButton;
public Animator settingsButton;
```

After that, add the following method:

```
public void OpenSettings() 
{
    startButton.SetBool("isHidden", true);
    settingsButton.SetBool("isHidden", true);
}
```

That’s all the code you need. Save the script and switch back to Unity.

In Unity, select **UIManager** in the Hierarchy. Drag **StartButton** from the Hierarchy to the **Start Button** field in the Inspector and drag **SettingsButton** to the **Settings Button** field.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/181.png)

Then select **SettingsButton** in the Hierarchy and click + in the **On Click ()** list. Drag **UIManager** from the Hierarchy to the new item in the list. After that, open the function selection menu and select **UIManagerScript ▸ OpenSettings()**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/191.png)

Select **File ▸ Save** to save your work so far and then run the scene. Wait for the buttons to stop moving and click on the **Settings** button. You should see both buttons move out of the screen in opposite directions simultaneously.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/20.gif)

　

# # Adding the Settings Dialog

Usually, dialogs contain some other controls that appear and move with dialog. For that reason, it’s effective to create the dialog as a panel and set other UI Elements as child objects.

To create a panel, select **GameObject ▸ UI ▸ Panel** in the menu. This will create a full-screen panel that uses a white, semi-transparent image as a background. As a result, you should see some kind of full-screen veil.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/211.png)

However, this dialog won’t be full-screen; in fact, it’ll be relatively small. Follow these steps to set the dialog’s size and position:

- 1\) Select **Panel** in the Hierarchy and rename it to **SettingsDialog**.
- 2\) Set its **anchors** to **middle-right**, since you’ll position the dialog beyond the right edge and off the screen, so that it’s not visible when you run the scene.
- 3\) Set **Width** to **400** and **Height** to **150**.
- 4\) Set **Pos X** to **220** and **Pos Y** to **0**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/221-650x152.png)

　

## Setting the Dialog’s Background Image

You’re going to use a **9-slice image** as the dialog’s background. You need to set the border in the Import Settings first.

Open **RW ‣ UI ‣ Menu** in the Project window and select **settings_panel_bg_9slice**. In the Inspector, click **Sprite Editor** to open the Sprite Editor view.

Set all **Border** values to **20** and click **Apply** at the top.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/23.png)

Now you can use this image as the dialog background.

Select **SettingsDialog** in the Hierarchy and drag **settings_panel_bg_9slice** to the **Source Image** field in the Inspector. Double-click on **Color** next to the **Source Image** field, and set **A** to **255** (or **1** depending on your color picker settings) to remove transparency.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/241-650x395.png)

This is what the dialog should look like after you set the background image:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/25-650x279.png)

　

## Adding the Label

Right-click on **SettingsDialog** and choose **UI ▸ Text** to create a new Text UI element as a child of SettingsDialog. Select **Text** in the Hierarchy and rename it to **SettingsLabel**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/26.png)

After that, select **SettingsLabel** in the Hierarchy and make the following changes:

- 1\) Set **Anchors** to **top-center**.
- 2\) Set **Pos X** to **0** and **Pos Y** to **-40**.
- 3\) Change **Text** to **Settings**.
- 4\) Open the **Fonts** folder in the Project window and drag the **DCC – Dreamer** font to the **Font** field in the Inspector.
- 5\) Set **Font Size** to **30**.
- 6\) Set **Alignment** to **Center Align**.
- 7\) Set **Color** to White, with **A** (Alpha) **255** to remove transparency.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/271-259x500.png)

　

## Animating the Settings Dialog

Select **SettingsDialog** in the Hierarchy and open the **Animation** view. Then create a new animation by clicking **Create**.

Name the animation **SettingsDialogSlideIn** and save it in **RW ‣ Animations**.

Then click on the **1:00** mark in the **timeline** and make sure recording is started, or start it manually by clicking the record button.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/newAnimation-650x79.png)

In the Inspector, set **Anchors** to middle-center and **Pos X** to 0.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/311.png)

Stop recording the animation. Open the **Animations** folder in the Project window and select **SettingsDialogSlideIn** in the Inspector. Finally, uncheck **Loop Time**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/33.png)

Select **SettingsDialog** in the Hierarchy and open the **Animator** view. **Copy and paste** the **SettingsDialogSlideIn** state to duplicate it. **Rename** the duplicate to **SettlingsDialogSlideOut**, and set its **Speed** to **-1**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/dialogSlideOut.png)

- ***Note:*** *This time, don’t change the default state! The dialog’s default state should stay `SettingsDialogSlideIn`.*

Click the + button and add a new **bool** parameter named **isHidden**.

**Create two transitions** between the states, just as you did for the buttons. Then add the **isHidden** parameter of type bool.

Change the condition of the **SettingsDialogSlideOut => SettingsDialogSlideIn** transition to be **isHidden** equals **false**. For the **SettingsDialogeSlideIn => SettingsDialogSlideOut** transition, change the condition to **isHidden** equals **true**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/dialogAnimationStates-650x233.png)

Next, right-click in the Animator and select **Create State** and then choose **Empty**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/createEmpty-650x233.png)

In the Inspector, name the state **Idle**. Next, right-click the state and choose **Set as Layer Default State**. Finally, create a **transition** between `Idle` to `SettingsDialogSlideIn`. Set the Condition as **isHidden** is equal to **false**.

It should look as follows:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/dialogStates.png)

Select **File ▸ Save** to save your work so far and then run the scene. You’ll see the dialog sliding in at the start and overlapping the buttons.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/361.png)

This is getting there, but it’s still not what you want. You need to disable the Animator component so it won’t play the animation at the start. You want the dialog to appear on demand, which you’ll do next.

　

## Displaying Dialog on Button Click

Disable the Animator component so it won’t play the animation at the start by setting the default value for the **isHidden** to **true**. Click on some empty space in the Animator window and set **isHidden** to **true**:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/ishidden-650x207.png)

Now when you run the scene, the dialog doesn’t appear straight away, which is good; however, it won’t show up even when you click the settings button. This is not good.

Open the **UIManagerScript** and add the following instance variable:

```
public Animator dialog;
```

Then add the following line to the end of `OpenSettings`:

```
public void OpenSettings() 
{
    //..skipped..

    dialog.SetBool("isHidden", false);
}
```

This enables the Animator component and sets the correct value to the `isHidden` parameter.

Finally, add a new method called `CloseSettings`, as follows:

```
public void CloseSettings() 
{
    startButton.SetBool("isHidden", false);
    settingsButton.SetBool("isHidden", false);
    dialog.SetBool("isHidden", true);
}
```

This returns the buttons and hides the dialog. You’ll add the UI element that calls this method in a moment.

**Save** the **UIManagerScript** and switch back to the Unity editor.

Select **UIManager** in the Hierarchy and drag **SettingsDialog** to the **Dialog** field in the Inspector.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/381.png)

Run the scene. Then click the **Settings** button and see how the buttons slide out as the dialog slides in.

　

## Adding a Close Button

Create a new button as a child of the **SettingsDialog** by right-clicking on it in the Hierarchy and selecting **UI ▸ Button**. Rename this new button to **CloseSettingsButton**. Also, this button won’t have text on it, so remove the **Text object** nested in **CloseSettingsButton**.

This is what you should have in the Hierarchy at this point:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/391.png)

Now, select **CloseSettingsButton** and follow these steps:

- 1\) Set **Anchors** to **top-right**.
- 2\) Set both **Pos X** and **Pos Y** to **0**.
- 3\) Open **RW ‣ UI ‣ Menu** in the Project window and drag **settings_btn_close** to the **Source Image** field in the Inspector.
- 4\) Click **Set Native Size**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/401-453x500.png)

This is how the dialog should look in the Scene view now:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/411-650x279.png)

Select **CloseSettingsButton** in the Hierarchy. Scroll down to the **On Click ()** list and **click +**. Drag **UIManager** from the Hierarchy to the new item, and then select **UIManagerScript ▸ CloseSettings ()** method in the dropdown.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/421-352x500.png)

Select **File ▸ Save** to save your work so far and then run the scene. Click the **Settings** button and close the scene by clicking **Close** after the dialog slides into the scene.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/43.gif)

　

## Adding Sound Settings

Select **Main Camera** in the Hierarchy and add the **Audio Source** component. Then, in the Project window, open **RocketMouse ‣ Audio** and drag **Music** to the **Audio Clip** field in the Inspector.

Enable **Play On Awake**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/441.png)

　

## Toggling Music On and Off

Right-click on **SettingsDialog** and select **UI ▸ Toggle** to add a toggle UI element as a child of the dialog.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/451.png)

You don’t need a label this time, so remove the nested **Label**. Then rename **Toggle** to **SoundToggle**. This is what you should see in the Hierarchy after you’re done:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/461.png)

Select **SoundToggle** in the Hierarchy. Set its **Anchors** to middle-left, **Pos X** to **115** and **Pos Y** to **-10**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/471.png)

Also, under the **Toggle component**, uncheck the **Is On** checkbox.

Select the **Background** child of **SoundToggle** in the Hierarchy and drag **settings_btn_sound** from the Project window to **Source Image** in the Inspector. Then click **Set Native Size**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/481-470x500.png)

Select **Checkmark** and repeat the previous steps, but this time use the **settings_btn_sound_checkmark** image from the Project window.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/49-470x500.png)

This is what you should see in the Scene view:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/501-650x277.png)

　

## Muting the Music

Select **SoundToggle** in the Hierarchy, and in the Inspector, find the **On Value Changed (Boolean)** list. Click + to add a new item.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/511.png)

Drag **MainCamera** from the Hierarchy to the newly added item. Open the function selection dropdown and select **AudioSource ▸ mute** from the **Dynamic bool** section at the top.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/521-482x500.png)

Select **File ▸ Save** to save your work so far and then run the scene. Open the settings dialog and try switching music ON and OFF.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/mute.gif)

　

## Using Slider to Regulate the Volume

Again, right-click on **SettingsDialog** to add a child object, but this time add a **UI ▸ Slider**. **Rename** it **VolumeSlider**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/531.png)

Select **VolumeSlider** in the Hierarchy and set its **anchors** to **middle-right**. Then set its **Pivot** to **(1, 0.5)** so that you can position it using the middle point of its right edge.

Finally, set its **RectTransform** to **(Pos X:-20, Pos Y:-10, Width:270, Height:35)**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/541.png)

This is how the Settings dialog should look now:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/volumeSlider-650x271.png)

Open **RW ‣ UI ‣ Menu** in the Project window and find three images corresponding to each part of the slider: **slider_background**, **slider_fill** and **slider_handle**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/56.png)

For each image, open the **Sprite editor** in the Inspector and set all values for **Border** to **8**. Click **Apply**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/57-454x500.png)

Now, set the corresponding image for each part of the slider:

- 1\) Select **Background** and drag **slider_background** to **Source Image** in the Inspector.
- 2\) Select **Fill** (not Fill Area) and drag **slider_fill** to Source Image.
- 3\) Select **Handle** and drag **slider_handle** to Source image.

If you run the scene now and open the Settings dialog, you should see something like this:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/58.png)

　

## Changing the Volume of the AudioSource Component

Select **VolumeSlider** in the Hierarchy. In the Inspector, scroll down to see the **On Value Changed (Single)** list and **click +** to add a new item.

Drag **MainCamera** from the Hierarchy to that new item in the list, open the function selection dropdown and select **AudioSource ▸ volume** in the **Dynamic float** section.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/59-444x500.png)

In addition, set the **Slider component‘s Value to 1**. This will set the slider to the same value as the volume of the music when the scene starts.

Select **File ▸ Save** to save your work so far and then run the scene. Open the Settings dialog and change the slider’s value. You should hear the volume go up and down as you drag the slider handle. What a great feature! :]

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/volume.gif)

　
