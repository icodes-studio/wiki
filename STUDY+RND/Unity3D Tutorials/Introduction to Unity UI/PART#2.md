# [Introduction to Unity UI – Part 2](https://www.kodeco.com/6569-introduction-to-unity-ui-part-2)
    ● In this second part of a three-part tutorial,
    ● you’ll learn how to incorporate animations into your user interfaces. By Ben MacKinnon.
    ● Apr 24 2019, C# 6, Unity 2018.3, Unity
[***Download materials***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/Introduction-to-Unity-UI-Part-2.zip)



*Update February 2019: This tutorial was updated to Unity 2018.3 by Ben MacKinnon. Original post by [**Kirill Muzykov**](https://twitter.com/kmuzykov).*

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

- 1\) A keyframe was inserted automatically at the **0:00** mark. At this point, the button is at its starting position, where you positioned it in the previous tutorial.
- 2\) Although the anchors’ visual representation didn’t turn red, you can see the numeric values changed and turned red, indicating that you’ve also animated the anchors.

Make both the Animation view and Scene view visible and play the animation. You’ll see something like this:

![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20Tutorials/Introduction%20to%20Unity%20UI/Assets/06.gif)

Did you notice the animation on the anchors? You may be wondering why you need to reposition the anchors.

Here’s why: The position of the button is the distance to its anchors. In the case of StartButton, it was the distance from the bottom edge. Right now, you’re only working with vertical movement, so only the bottom edge matters. To make sure the button leaves the screen, move it up until it’s no longer visible.

What if you don’t know the height of the screen? How do you make sure the button stops right after it’s no longer visible?

Answer: Change its anchors.

Setting the anchors to the top edge of the screen means you set the distance from the top edge of the screen. Thus, the button will always be above the edge and independent from the height of the screen, since it’s positioned relative to the screen’s top edge.