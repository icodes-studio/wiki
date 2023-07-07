# [Introduction to Unity UI – Part 2](https://www.kodeco.com/6569-introduction-to-unity-ui-part-2)
    ● In this second part of a three-part tutorial,
    ● you’ll learn how to incorporate animations into your user interfaces.
    ● Apr 24 2019, C# 6, Unity 2018.3, Unity
    ● By Ben MacKinnon.
*Update February 2019: This tutorial was updated to Unity 2018.3 by Ben MacKinnon. Original post by [**Kirill Muzykov**](https://twitter.com/kmuzykov).*

[***Download materials***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-2.zip)

　

Welcome back! In [**part one**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/PART%231.md) of this three-part tutorial series, you created a scene with two buttons. You learned how to use the Image, Button and Text UI controls, and you learned core concepts such as RectTransform, Anchors and Pivots. That’s a lot of skills to learn in one tutorial! However, the scene itself is pretty simple.

In this tutorial, you’ll spruce up the scene by adding animations, a settings dialog and more UI controls like Slider and Toggle.

　

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/featured_image_unityrm.gif)

　

You’ll be picking up the project from the end of part one. If you don’t have it already, download the project by clicking the [**Download materials**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-2.zip) button at either the top or bottom of this tutorial.

Open the project in Unity. Open the **MenuScene**, grab an invigorating beverage and start -drinking- thinking UI! :]

　

# # Animating Buttons

You’re going to jump right in by adding some cool animations. Why? First, animations are cool! Second, they’re practical for this project. You need the buttons to exit from the scene so there’ll be enough space to display the new dialog you’ll create later.

　

## Creating Animation and Animator

Animating buttons is just like animating any other Unity object. You’ll need to add an **Animator** component, create a few animations and set up states and transitions between them.

Here are the steps to success:

- 1\) Select **StartButton** in the Hierarchy.
- 2\) Open the **Animation view** by selecting **Window ▸ Animation ▸ Animation** from the menu.
- 3\) Click on the **Create** button in the Animation view. This will create the Animator and an animation clip.
- 4\) Name the animation **StartButtonSlideOut** and save it in **RW ▸ Animations**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/022.png)

In addition to creating the animation itself, Unity also adds an **Animator** component to **StartButton** and creates an **Animator Controller**. Ready to get started?

　

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

Two things happened:

- A keyframe was inserted automatically at the **0:00** mark. At this point, the button is at its starting position, where you positioned it in the previous tutorial.
- Although the anchors’ visual representation didn’t turn red, you can see the numeric values changed and turned red, indicating that you’ve also animated the anchors.

Make both the Animation view and Scene view visible and play the animation. You’ll see something like this:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/06.gif)

Did you notice the animation on the anchors? You may be wondering why you need to reposition the anchors.

Here’s why: The position of the button is the distance to its anchors. In the case of StartButton, it was the distance from the bottom edge. Right now, you’re only working with vertical movement, so only the bottom edge matters. To make sure the button leaves the screen, move it up until it’s no longer visible.

What if you don’t know the height of the screen? How do you make sure the button stops right after it’s no longer visible?

Answer: Change its anchors.

Setting the anchors to the top edge of the screen means you set the distance from the top edge of the screen. Thus, the button will always be above the edge and independent from the height of the screen, since it’s positioned relative to the screen’s top edge.

　

## Animating Button Slide In

Nice work! You have a button that slides out of the screen. Now you need a reverse animation. You’ll use it in two cases:

- When the scene loads, you want the button to slide into position instead of simply appearing.
- When you close the settings dialog, the buttons should return to their initial positions.

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

　

# # Animating the Settings Button

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

It’s nice to see the Settings button going up and down, but shouldn’t both buttons slide out simultaneously, just as they slide in at the start?

Yes! You’ll make that happen next.

　

# # Triggering Buttons Animation From the Script

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

Look at all that gorgeous free space you created! That seems like the perfect place for a dialog.

　

## Creating the Panel

Usually, dialogs contain some other controls that appear and move with dialog. For that reason, it’s effective to create the dialog as a panel and set other UI Elements as child objects.

To create a panel, select **GameObject ▸ UI ▸ Panel** in the menu. This will create a full-screen panel that uses a white, semi-transparent image as a background. As a result, you should see some kind of full-screen veil.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/211.png)

However, this dialog won’t be full-screen; in fact, it’ll be relatively small. Follow these steps to set the dialog’s size and position:

- 1\) Select **Panel** in the Hierarchy and rename it to **SettingsDialog**.
- 2\) Set its **anchors** to **middle-right**, since you’ll position the dialog beyond the right edge and off the screen, so that it’s not visible when you run the scene.
- 3\) Set **Width** to **400** and **Height** to **150**.
- 4\) Set **Pos X** to **220** and **Pos Y** to **0**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/221-650x152.png)

You should see a semi-transparent rectangle to the right of the canvas rectangle. All UI elements outside this rectangle are not visible on the screen. This is precisely what you want for the dialog!

　

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

In its present state, it’s difficult to argue that the nondescript, green rectangle is actually a settings dialog, but there’s an easy way to fix this. All you need to do is to write Settings on it. Poof! Magic. :]

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

Now you’ve got a legitimate Settings dialog. The next step is to make it appear when the user clicks the Settings button.

You’re going to use almost exactly the same technique as you did to make the buttons slide in and out, the only difference being that the dialog won’t slide in automatically after the scene starts.

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

That’s better, but you can’t close the dialog. To fix this, you need to add a close button to the dialog.

　

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

- ***Note:***
    > - *This time, you’re going to use another method to highlight the button’s image (Transition property, in the Button script) called Color Tint, which is the default transition type.*
    > - *You’ll do this instead of adding two more images to represent highlighted and pressed button states.*

The button looks great, but it does nothing. Fortunately, you’ve already added the method this button needs to call.

Select **CloseSettingsButton** in the Hierarchy. Scroll down to the **On Click ()** list and **click +**. Drag **UIManager** from the Hierarchy to the new item, and then select **UIManagerScript ▸ CloseSettings ()** method in the dropdown.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/421-352x500.png)

Select **File ▸ Save** to save your work so far and then run the scene. Click the **Settings** button and close the scene by clicking **Close** after the dialog slides into the scene.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/43.gif)

Hey, you’ve done well. That looks nice! :]

　

# # Adding Sound Settings

There’s not much sense in keeping a meaningless settings dialog, so it’s time to add some settings to it. In this dialog, the player will have control over the music’s volume in the menu scene.

Music? Yes, what fun is a game without a rockin’ soundtrack?

　

## Adding Music to the Menu Scene

You’re welcome to rummage around your files for a suitable clip, but you don’t have to because the project already contains a snappy music track. All you need to do is to play it.

Select **Main Camera** in the Hierarchy and add the **Audio Source** component. Then, in the Project window, open **RocketMouse ‣ Audio** and drag **Music** to the **Audio Clip** field in the Inspector.

Enable **Play On Awake**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/441.png)

　

## Toggling Music On and Off

To toggle music on and off you’re going to use a — wait for it — toggle control. Right-click on **SettingsDialog** and select **UI ▸ Toggle** to add a toggle UI element as a child of the dialog.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/451.png)

The toggle controls consist of the **root object**, which has a toggle component attached, and several child objects:

- **Background**: An image that is always visible (i.e. in both on and off states)
- **Checkmark**: An image that is only visible when the toggle is active (ON)
- **Label**: A label displayed next to the toggle

You don’t need a label this time, so remove the nested **Label**. Then rename **Toggle** to **SoundToggle**. This is what you should see in the Hierarchy after you’re done:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/461.png)

Select **SoundToggle** in the Hierarchy. Set its **Anchors** to middle-left, **Pos X** to **115** and **Pos Y** to **-10**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/471.png)

- **Note:** 
    > - *Remember how anchors and position are set relative to the parent?*
    > - *This is why it’s important to add **SoundToggle** as a child of **SettingsDialog** first before setting its position.*

Keep in mind, changing the Anchors and Pivot won’t change the UI element position. Instead, they update position fields (e.g., Pos X, Pos Y, Left, Right) to values that position the element at the same place by using the new anchors and pivot. Set these first and play with them to set the correct position.

Also, under the **Toggle component**, uncheck the **Is On** checkbox.

Now you need to specify images for the Background and Checkmark child objects. Just as you’ve done with the other images, you will take them from **RW ‣ UI ‣ Menu**, so open that folder in the Project window.

You’re going to need two images:

- **settings_btn_sound** for Background
- **settings_btn_sound_checkmark** for Checkmark

Select the **Background** child of **SoundToggle** in the Hierarchy and drag **settings_btn_sound** from the Project window to **Source Image** in the Inspector. Then click **Set Native Size**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/481-470x500.png)

Select **Checkmark** and repeat the previous steps, but this time use the **settings_btn_sound_checkmark** image from the Project window.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/49-470x500.png)

This is what you should see in the Scene view:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/501-650x277.png)

- ***Note:***
    > - *You’ll notice the size of the root object (wide rectangle) doesn’t match the background images.*
    > - *You can adjust its size, but it’s not important.*
    > - *The rect of the child objects will act as the collider boxes for interaction.*
    > - *Also, the checked state may still be showing, but when you press play in the editor,*
    > - *the Toggle will refresh its state based on the **Is On** option you set earlier.*

　

## Muting the Music

The good thing about UI elements’ event handlers is that sometimes you can get away without writing any code at all! Instead, you can set the UI element to change the property or directly call a function of the component attached to the object using only Unity’s interface.

Here’s how you can change the **mute** property of the **Audio Source** component attached to MainCamera.

Select **SoundToggle** in the Hierarchy, and in the Inspector, find the **On Value Changed (Boolean)** list. Click + to add a new item.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/511.png)

Drag **MainCamera** from the Hierarchy to the newly added item. Open the function selection dropdown and select **AudioSource ▸ mute** from the **Dynamic bool** section at the top.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/521-482x500.png)

- ***Note:*** *When you look closely at the function selection options, you’ll see two **mute** properties, one in the **Dynamic bool** section and the other in **Static Parameters**.*

The difference is trivial. If you select mute in the Dynamic bool section, its value will be set to the current value of the toggle’s Active property each time you toggle it.

If you select the mute property from the Static Parameters section, a new input field will appear and you’ll be able to set its value in the Inspector to a constant value.

Of course, in the Dynamic bool section, there are only properties and methods that take bool values because Toggle’s active property type is bool. Since you can specify any value as the static parameter, the Static Parameters section contains all public properties and methods.

Hence, when the toggle is active (e.g. active equals true), it sets the mute property of AudioSource to true and mutes the music.

Select **File ▸ Save** to save your work so far and then run the scene. Open the settings dialog and try switching music ON and OFF.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/mute.gif)

　

## Using Slider to Regulate the Volume

It’s really cool that Toggle can synchronize its On and Off states with some other component’s field, but what if you have a range of values? In this case, you can use the Slider UI element.

Again, right-click on **SettingsDialog** to add a child object, but this time add a **UI ▸ Slider**. **Rename** it **VolumeSlider**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/531.png)

Select **VolumeSlider** in the Hierarchy and set its **anchors** to **middle-right**. Then set its **Pivot** to **(1, 0.5)** so that you can position it using the middle point of its right edge.

Finally, set its **RectTransform** to **(Pos X:-20, Pos Y:-10, Width:270, Height:35)**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/541.png)

This is how the Settings dialog should look now:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/volumeSlider-650x271.png)

The Hierarchy should show that the slider control has more parts than a toggle or button. Here are the main parts:

- **Background**: Image that shows the bounds of the slider and its inner area when it’s not filled (i.e., when the handle is all the way to the left).
- **Handle**: Image for the handle. You drag it to change the slider’s value.
- **Fill**: Image that stretches to show the value of the slider.

The fill image is not the only part that can stretch, so normally it’s better to use 9-scale images for all three parts. You have such images! Lucky you! :]

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

Changing the music volume using the slider is similar to what you did with the toggle.

Select **VolumeSlider** in the Hierarchy. In the Inspector, scroll down to see the **On Value Changed (Single)** list and **click +** to add a new item.

Drag **MainCamera** from the Hierarchy to that new item in the list, open the function selection dropdown and select **AudioSource ▸ volume** in the **Dynamic float** section.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/59-444x500.png)

In addition, set the **Slider component‘s Value to 1**. This will set the slider to the same value as the volume of the music when the scene starts.

Select **File ▸ Save** to save your work so far and then run the scene. Open the Settings dialog and change the slider’s value. You should hear the volume go up and down as you drag the slider handle. What a great feature! :]

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/volume.gif)

　

# # Where to Go From Here?

As promised in the end of [**Part 1**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/PART%231.md), in this tutorial, you’ve added more controls, learned how to animate them and made a fully functioning menu scene. You’ve now explored most of the UI controls!

If you’d like to see its final, perfect form, find the final project by using the [**Download materials**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-2.zip) button at the top or bottom of this tutorial.

In [**Part 3**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/PART%233.md), the final tutorial in this series, you’ll learn advanced techniques, including using the mask component to create a sliding menu. You’ll also create more animations and learn how to migrate legacy GUI code to the Unity UI.

If you have any questions, comments or discoveries to share, please join the conversation below.