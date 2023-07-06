# [Introduction to Unity UI – Part 3](https://www.kodeco.com/6569-introduction-to-unity-ui-part-3)
    ● In the final part of our three-part tutorial series,
    ● you’ll learn how to integrate Unity UI into a working game.
    ● Apr 24 2019, C# 6, Unity 2018.3, Unity
    ● By Ben MacKinnon.    
[***Download materials***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-3.zip)

　

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/rmouse_ui_146.gif)

　

Creating sliding menus in Unity is now a snap!

Welcome to the third and final part of this series about Unity’s UI.

In [**Part 1**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/PART%231.md), you used anchors, pivot and other cool tricks to create a menu scene complete with an adaptive background and neatly controlled graphical elements.

[**Part 2**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/PART%232.md) was all about animating buttons and actions to make your game uber-interactive.

Now you’re going to build on these skills to round out your understanding of Unity’s UI. First, you’ll make a fancy new menu. Then, you’ll migrate the RocketMouse game scene from the old legacy GUI system to the new UI system!

　

# # Getting Started

Start by opening the Unity project at the point where you left it at the end of Part 2. If you tinkered with your old project file to a point beyond recognition, you can find the starter project by clicking the [**Download materials**](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-3.zip) button at the top or bottom of this tutorial. Open it in Unity.

Strap yourself in. This tutorial is about to get real.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/012.png)

　

# # Creating a Sliding Menu

Often, you want to provide users easy access to game options or features without wasting screen space, especially on mobile devices. This is a job for a sliding menu.

You’ve seen these before. They’re a control comprised of a small button that is always visible and a menu that slides out to reveal options. The first step is adding that button.

　

## Adding an Open Button

You learned to add a button during the first two parts of this series, but follow these directions if you need a refresher.

Select **GameObject ▸ UI ▸ Button** in the menu. Rename the newly added button to **SlideMenuButton** and delete the nested **Text** object since the button won’t need a label.

Select **SlideMenuButton** in the Hierarchy. Open **RW ▸ UI ▸ Menu** in the Project window. Drag the **btn_9slice_normal** image to the **Source Image** field in the Inspector.

Set the button position and size as follows:

- 1\) Set **Anchors** to **bottom-left**.
- 2\) Set both **Pos X** and **Pos Y** to **80**.
- 3\) Set **Width** and **Height** to **64**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/023-650x208.png)

Nice work! That’s step one.

　

## Adding the Masking Panel

To create this control, you’ll need two panels. One will define the mask, and the other will move within the mask.

- ***Note:*** *If you’re not sure what a mask is, don’t sweat it. Just follow the steps, and you’ll see how it works in real time. You’ll need to have both panels to see it in action.*

Select **GameObject ▸ UI ▸ Panel** to create the first panel. This will add a **Panel**, which will be the mask, to the Hierarchy. Select it and follow these steps:

- 1\) Rename it **MaskPanel**.
- 2\) Drag it over **SlideMenuButton** to add it as a child object.
- 3\) Set **Anchors** to **top-center**.
- 4\) Set **Pivot** to **(X:0.5, Y:0)**
- 5\) Set both **Pos X** and **Pos Y** to **0**.
- 6\) Set **Width** to **64** and **Height** to **192**.
- 7\) Add the mask component by clicking the **Add Component** button and selecting **UI ▸ Mask**.
- 8\) Uncheck **Show Mask Graphic** inside the mask component dialog.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/MaskPanel.png)

- ***Note:*** *You don’t have to add the panel with a mask as a child of the button, but it makes it easier to position when using anchors. It also ensures that when the button moves, the masking panel moves with it.*

　

## Adding the Content Panel

Add another panel by selecting **GameObject ▸ UI ▸ Panel** and following these steps:

- 1\) Rename it **ContentPanel**.
- 2\) Add it as a child of **MaskPanel**.

- ***Note:*** *Did you notice you can see only a small portion of the white panel although its size didn’t change? After adding it as a child of the panel with a mask, you now only see the portion of ContentPanel that is inside the rect of MaskPanel.*

- 3\) Set the **Anchors** to **stretch-stretch**.
- 4\) Set **Left, Top, Right** and **Bottom** to **0**.
- 5\) Set **Pivot** to **(X:0.5, Y:1)**

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/ContentPanel.png)

Now, change the background image for the content panel.

Open **RW ▸ UI ▸ Menu** in the Project window and select the **slide_menu_panel_9slice** image. Open **sprite editor** in the Inspector and set all **border** values to **8**. Click **Apply**!

After that, select **ContentPanel** in the Hierarchy, and then drag **slide_menu_panel_9slice** from the Project window to the **Source Image** field in the Inspector.

In the following GIF, you can see both the content panel should look and how the mask component works. Now you see it, now you don’t!

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/061.gif)

- ***Note:***
    > - *A mask works like a window.*
    > - *If someone is walking along a wall, you can only see him when he passes by a window.*
    > - *Or, think of it as a cloaking device that only allows a portion of the image to show through.*

　

## Adding Buttons

Next, you’ll add three buttons to the sliding menu.

To create the first button, select **GameObject ▸ UI ▸ Button**. Rename it to **AboutButton** and delete the **Text** child.

Drag the **AboutButton** button onto **ContentPanel** in the Hierarchy to add it as a child. Open **RW ▸ UI ▸ Menu** in the Project window and drag **slide_menu_btn_about** to the **Source Image** in the Inspector. Click **Set Native Size**. Don’t worry about the position for now.

Right-click on **AboutButton** and select **Duplicate** (Ctrl/Cmd + D) to create another button. rename the duplicate to **AchievementsButton** and use the **slide_menu_btn_achievements** from **RW ▸ UI ▸ Menu** in the Project window as **Source Image**.

After that, duplicate the button again. Name it **LeaderboardsButton** and use **slide_menu_btn_leaderboards** as the source image.

Great! Now, you have three buttons, but what about positioning them? Time to use a shortcut!

**Select ContentPanel** in the Hierarchy. Add a **Vertical Layout Group** component and voilà! You should see three buttons stacked neatly in the space. :]

Here’s what it should look like:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/ButtonStack.png)

- ***Note:***
    > - *The Vertical Layout Group just spaced your buttons evenly in the panel.*
    > - *You can edit the way the Vertical Layout Group does this,*
    > - *but the defaults work in your case as the height of the three buttons equals the height of the panel.*

　

## Making the Panel Slide Up and Down

To make the panel slide up and down, use the same technique you’ve already employed for buttons and the settings dialog.

Follow these steps:

- 1\) Select **ContentPanel** in the Hierarchy and open the **Animation** view.
- 2\) Create a new clip by clicking on the **Create** button.
- 3\) Name the animation **SlidingMenuDown** and save it to **RW ▸ Animations**.
- 4\) Click on the **1:00** mark in the **timeline** and enable recording in the Animation view. Turn it on by pressing the red circle button, and then look for the playback controls to turn red.
- 5\) Set the **Top** to **192** in the Inspector and then **stop recording**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/PanelAnimation.png)

- 6\) Open **RW ▸ Animations** in Project window and select **SlidingMenuDown**. Uncheck **Loop Time** in the Inspector.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/NoLoop.png)

- 7\) Select **ContentPanel** in the Hierarchy and open the **Animator** view. Copy and paste the **SlidingMenuDown** state to create a duplicate.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/StateCopy.png)

- 8\) Rename the duplicate **SlidingMenuUp** and set its **Speed** to **-1** in the Inspector.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/SlidingUpState.png)

- 9\) **Create two transitions**: one from **SlidingMenuUp** to **SlidingMenuDown**, and one the opposite direction.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/animationTransitions2.png)

- 10\) Add a new **Bool** parameter named **isHidden** and set its default value to **true**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/animationParameter2.png)

- 11\) Select the transition from **SlidingMenuUp** to **SlidingMenuDown**, and in the list of conditions, set **isHidden** to **true**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/transitionCondition.png)

- 12\) Select the transition from **SlidingMenuDown** to **SlidingMenuUp**, and this time set conditions to be **isHidden** equals **false**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/transitionCondition_2.png)

- 13\) Next, right-click in the Animator, select **Create State** and then choose **Empty**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/emptyState.png)

- 14\) In the Inspector, name the state **Idle**. Next, right-click the state and choose **Set as Layer Default State**. Create a transition between **Idle** to **SlidingMenuUp**. Set the condition so that **isHidden** is equal to **false**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/idleAnimationState.png)

- 15\) Select **ContentPanel** in the Hierarchy and open the Animation view. Create a **new animation clip** and call it **Idle**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/newAnimation.png)

- 16\) In the first keyframe, set the **Top** to be **192**. Then stop the recording.

That’s it! Save your work again. Unfortunately, when you run your game, nothing happens. You’ll make things move in code.

　

## Adding Code to Toggle the Menu

Open the **UIManagerScript** in a code editor and add the following instance variable:

```
public Animator contentPanel;
```

After that, add the following method:

```
public void ToggleMenu() 
{
    bool isHidden = contentPanel.GetBool("isHidden");
    contentPanel.SetBool("isHidden", !isHidden);
}
```

This enables the animator component when you open the sliding menu and sets the correct `isHidden` parameter value.

Save the script and switch back to Unity. In Unity, select **UIManager** in the Hierarchy and drag **ContentPanel** from the Hierarchy to the **Content Panel** field in the Inspector.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/201.png)

Now, select **SlideMenuButton** in the Hierarchy. In the Inspector, find a list of On Click () event handlers and add a new one by clicking the + button.

After that, drag **UIManager** from the Hierarchy to that new handler. Then, in the function selection dropdown menu, select **UIManagerScript ▸ ToggleMenu ()**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/212-650x337.png)

Save your work, run the scene and relish in your cool sliding menu.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/menuSlide.gif)

　

# # Adding a Rotating Gear Icon

Don’t you think something is missing? Of course! The rotating gear icon on the opening button itself — the one shown in the animated GIF image at the start of this part.

　

## Adding the Gear Image

First, add an image as a child object of SlideMenuButton, and set it to animate during the menu opening and closing animations.

Right-click on **SlideMenuButton** and select **UI ▸ Image** to create a new image as a child object.

After that, follow these steps:

- 1\) Rename the image **GearImage**.
- 2\) Open **RW ▸ UI ▸ Menu** in the Project window and drag the **slide_menu_gear** image to the **Source Image** field in the Inspector.
- 3\) Click **Set Native Size**.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/gearImage-650x401.png)

　

## Animating the Gear Image

By now, creating two animation states and a parameter to switch between them is probably second nature. You may be able to create a left-rotating gear and reverse the animation to make a right-rotating gear on your own.

Here are the need-to-know details:

- The **Animation duration** should be identical to the sliding panel animation. All animations in this tutorial are exactly one second long.
- The gear should rotate **360 degrees** around the **Z axis** (Rotation Z).
- Use the same name **isHidden** for the parameter name and set its **default value** to true.
- Remember to disable looping and the Animator component.

If need more detailed directions, open the spoiler below.

Select **GearImage** in the Hierarchy and open the Animation view. Create a new clip by clicking on the **Create** button and name it **GearRotateOpen**. Save it in **RW ‣ Animations**.

Then, click on the **1:00** mark in the **timeline** and enable recording. After that, in the Inspector, change **Rotation Z** to 360.

**Stop recording** by clicking the button with a red circle.

Now, open the **Animations** folder in the Project window and select **GearRotateOpen**. In the Inspector, uncheck **Loop Time**.

Now, set up states. Select **GearImage** in the Hierarchy, open the **Animator view** and do the following:

- 1\) Right-click the Animator and choose **Create State**. Then choose **Empty**.
- 2\) In the Inspector, name the state **GearIdle**.
- 3\) Right-click **GearIdle** and select **Set as Layer Default State**.
- 4\) Duplicate the **GearRotateOpen** state by copying and pasting it.
- 5\) Rename the duplicate to **GearRotateClose** and change its **Speed** to **-1** in the Inspector.
- 6\) Add a new **Bool** parameter named **isHidden**, and set its default value to **true**.
- 7\) Create two transitions between states. Under conditions, set **isHidden** to **true** for the transition from **GearRotateOpen** to **GearRotateClose**, and **isHidden** to **false** for the reverse transition.
- 8\) Create a transition from **GearIdle** to **GearRotateOpen**. Set the **isHidden** condition to **false**.

　

## Triggering the Gear Animation from Code

To complete the sliding menu control, you need to trigger the gear animation with code, but you only need to write a few lines.

Open the **UIManagerScript** in a code editor and add the following instance variable:

```
public Animator gearImage;
```

Then, scroll down and find `ToggleMenu`. Add the following to the bottom of the method’s body:

```
public void ToggleMenu() 
{
    //..skipped..

    gearImage.SetBool("isHidden", !isHidden);
}
```

This enables the Animator component and sets its `isHidden` parameter to the same value as the `contentPanel` animator’s `isHidden` parameter.

Save the script file and switch back to Unity.

In Unity, select **UIManager** in the Hierarchy. Drag **GearImage** to the **Gear Image** field in the Inspector.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/231.png)

Save your work, run the scene and enjoy your fancy rotating gear icon.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/24.gif)

Good job! The sliding menu is complete, and your scene is coming together.

For the purposes of this tutorial, you’re not going to handle clicks on the buttons in the menu. You should be familiar with handling UI events, and integrating Game Center would send this tutorial down a rabbit hole. Instead, you’ll update the old GUI-based RocketMouse scene so that it uses the new GUI system.