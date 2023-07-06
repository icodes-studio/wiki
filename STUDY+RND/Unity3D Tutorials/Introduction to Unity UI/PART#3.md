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

- 1\) Rename it MaskPanel.
- 2\) Drag it over SlideMenuButton to add it as a child object.
- 3\) Set Anchors to top-center.
- 4\) Set Pivot to (X:0.5, Y:0)
- 5\) Set both Pos X and Pos Y to 0.
- 6\) Set Width to 64 and Height to 192.
- 7\) Add the mask component by clicking the Add Component button and selecting UI ▸ Mask.
- 8\) Uncheck Show Mask Graphic inside the mask component dialog.

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/MaskPanel.png)

- ***Note:*** *You don’t have to add the panel with a mask as a child of the button, but it makes it easier to position when using anchors. It also ensures that when the button moves, the masking panel moves with it.*

　

## Adding the Content Panel

Add another panel by selecting **GameObject ▸ UI ▸ Panel** and following these steps:

- 1) Rename it **ContentPanel**.
- 2) Add it as a child of **MaskPanel**.

- ***Note:*** *Did you notice you can see only a small portion of the white panel although its size didn’t change? After adding it as a child of the panel with a mask, you now only see the portion of ContentPanel that is inside the rect of MaskPanel.*

- 3) Set the **Anchors** to **stretch-stretch**.
- 4) Set **Left, Top, Right** and **Bottom** to **0**.
- 5) Set **Pivot** to **(X:0.5, Y:1)**

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/ContentPanel.png)

Now, change the background image for the content panel.

Open **RW ▸ UI ▸ Menu** in the Project window and select the **slide_menu_panel_9slice** image. Open **sprite editor** in the Inspector and set all **border** values to **8**. Click **Apply**!

After that, select **ContentPanel** in the Hierarchy, and then drag **slide_menu_panel_9slice** from the Project window to the **Source Image** field in the Inspector.

In the following GIF, you can see both the content panel should look and how the mask component works. Now you see it, now you don’t!

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/061.gif)

- ***Note:***
    > - A mask works like a window.
    > - If someone is walking along a wall, you can only see him when he passes by a window.
    > - Or, think of it as a cloaking device that only allows a portion of the image to show through.
