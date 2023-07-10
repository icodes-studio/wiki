# # CHAPTER 8 - TextMesh Pro
    ● Introduction to TextMesh Pro in Unity
    ● Learn about TextMesh Pro in Unity by creating a spooky text-based adventure game.
    ● Aug 4 2021, C# 7.3, Unity 2020.3, Unity
*https://www.kodeco.com/22175776-introduction-to-textmesh-pro-in-unity*


　

## In this tutorial...

- You’ll create a spooky text-based adventure game where the text style and format change based on what’s happening in the story.
- As you go on this adventure, you’ll learn about:
    - TextMesh Pro’s basic use and styling options.
    - Using ***Rich Text*** tags.
    - How to create ***Font Assets***.
    - How to customize ***Material Presets***.


　

## Getting Started

- Download the starter project by clicking the [***Download Materials***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/Using-TextMesh-Pro-Project-Files-2.zip) button.
- Open the project in ***Unity 2020.3*** or later.
- Browse **Assets/RW** to find the assets used in this project.
- The subfolders contain the following:
    - ***Fonts:*** Standard font files, TextMesh Pro Font Assets and Font Presets.
    - ***Scenes:*** Starter scene for the text-based adventure game.
    - ***Scripts:*** Helper script to advance the screens in the text-based adventure game.
    - ***Sprites:*** Images and an icon used in the text-based adventure game.
    - ***Textures:*** A cardboard texture you’ll apply to a font in the tutorial.


　

## Installing TextMesh Pro

- If you don’t see the TextMesh Pro tools and components, try enabling the package in the Package Manager.
- To do this, navigate to ***Window ▸ Package Manager*** and follow these steps:
    - On the ***Packages*** drop-down, select ***Unity Registry***.
    - Scroll down to ***TextMeshPro*** and select it.
    - With the package selected, click ***Install*** to install the package to your project.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/InstallTMP-650x422.png)
- Import the ***TextMesh Pro Essential Resources*** into your project by selecting ***Window ▸ TextMeshPro ▸ Import TMP Essential Resources***.
- Finally, import all the files in the Unity Package into your project.
- You’ll now see a subfolder called TextMesh Pro under Assets.


　

## What Is TextMesh Pro?

- **AS-IS: TextMesh**
    - Used bitmap fonts to display text on the screen.
    - Basic styling and configuration options.
    - Very limited regarding what you could create with it.
    - It began to appear fuzzy when enlarged.
    - The game’s frame rate dropped when you had many TextMesh objects on the screen at once.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/BitmapVsSDF-650x366.jpg)
- **TO-BE: TextMesh Pro**
    - ***It looks great:*** The text looks good at any size.
    - ***It’s infinitely configurable:*** You can make your text look exactly how you want it to.
    - ***It’s easy to use:*** TextMesh Pro is built right into the Unity game engine. The styling options are intuitive, so you can learn them quickly.


　

## How Does TextMesh Pro Work?

- **Font Asset**
    - At the core of TextMesh Pro is the ***Font Asset***.
    - You create a Font Asset from a standard font file.
    - All TextMesh Pro objects using that font will reference that Font Asset.
- **Texture Atlas**    
    - Each Font Asset generates a ***Texture Atlas*** that contains all the characters in each font.
    - ***Material Presets*** you create and text you draw to the screen both reference the single ***Texture Atlas***.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/FontAtlasFull-650x468.png)
- **Signed Distance Field**
    - TextMesh Pro uses a ***Signed Distance Field*** to render text on the screen.
    - Text appears sharp regardless of its relative size and distance from the camera.
    - Traditional bitmap textures appear blurry at close draw distances and large sizes.
- **TextMeshPro vs TextMeshProUGUI**
    - There are two types of TextMesh Pro components, TextMeshPro and TextMeshProUGUI.
    - ***TextMeshPro*** works with the ***MeshRenderer***. 
    - It’s best used with text that should exist in world space, like an in-game sign that could be added to a scene.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/TextMeshProSurfaceOptimized.gif)
    - ***TextMeshProUGUI*** works with the ***CanvasRenderer*** and the ***Canvas*** system, and is best for text that exists in screen space.
    - It replaces the built-in Unity UI.Text component.
    - There are no differences between the two types of components — they share the same configuration options.
- In this tutorial, you’ll learn how to create and work with the ***TextMeshProUGUI*** component.
- You can find information about using the TextMeshPro component in Unity’s [***TextMesh Pro User Guide***](https://docs.unity3d.com/Packages/com.unity.textmeshpro@3.0/manual/index.html).


　

## Setting up the Starter Project

- Open the starter scene at ***Assets/RW/Scenes/IntoTheAttic-Starter***.
- Change the aspect ratio of the ***Game View*** to ***9:16***. 
    - Enter a width of 9 and height of 16
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/PortraitAspectRatio.gif)
- The sample project, ***Into the Attic***...
    - Text-based adventure game.
    - Each screen of dialog has a ***TextMeshProUGUI*** component to display the text and a button to advance to the next screen.
    - These screens are child objects of the ***Screens*** GameObject in the scene.
    - The screens’ names have incrementing numbers indicating the order they appear in the story.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/ChangeScreens2.gif)


　

## Getting Started With TextMesh Pro

- Switch from the Game view to the Scene view so you can see the Text and RectTransform areas on your screen.
- Set ***2-Intro*** as the active screen.
- To add a new ***TextMeshProUGUI*** object
    - Right-click ***2-Intro*** and select ***UI ▸ Text – TextMeshPro***.
    - This gives ***2-Intro*** a child object called ***Text (TMP)***.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/AddTMPUGUI.gif)
- Select ***Text (TMP)*** and make the text area larger
    - Changing the ***Anchor Presets*** on the ***Rect Transform*** component to stretch ***horizontally*** and ***vertically***.
    - Set ***left, right*** and ***top*** to ***50***, then ***bottom*** to ***350***.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/TMPTransform.gif)
- To add text to the TextMeshProUGUI component, 
    - You need to type in the ***Text Input*** field. 
    - Add some introduction text to set the scene for the game: “One rainy night in the middle of January…”
    - The text now displays in the text area in the scene.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/PlainText.png)
- To Change the standard styling options in ***Main Settings***.
    - Change the font by clicking the ***bullseye*** icon next to the existing Font Asset.
    - Select ***NewTegomin-Regular SDF***.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/ChangeFontAsset.gif)
- Next, perform the following steps:
    - Make the text larger by changing ***Font Size*** to ***150***.
    - Set ***Line Spacing*** to ***-50*** to decrease the spacing between each line.
    - Finally, center the text by selecting the ***Center*** and ***Middle*** alignment options.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/FormattedText-588x500_v2.png)


　

## Setting Font Color and Gradient

- Moving on, disable ***2-Intro***, then enable ***3-Bang***.
- Select the child ***Text (TMP)*** and make the text stand out by:
    - Changing the ***Font Style*** to ***bold*** and ***uppercase***.
    - Increasing ***Font Size*** to ***300***.
    - Changing ***Vertex Color*** to ***yellow*** by clicking the field and choosing yellow in the color selector window.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/Bang_v2-591x500.png)
- Next, set ***5-Wind*** as the active screen.
    - Select ***Text (TMP)*** and make the text feel cold by adding a color gradient. 
    - Check ***Color Gradient***, then change ***Color Mode*** to ***Four Corners Gradient***.
    - Set the top two corners to ***white***, the bottom left to ***cyan***, and the bottom right to ***blue***.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/Gradient-650x486.png)


　

## Adding Rich Text in TextMesh Pro

- **Italic**
    - Test this out on screen ***6-Crash***.
    - Place an italic opening tag `<i>` before the word ***sharp*** and a closing tag `</i>` after the word ***crash***.
    - The words ***sharp crash*** are now italicized, putting emphasis on those words.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/ItalicTag-618x500.png)
- **Color** 
    - On screen ***7-Broken***, 
    - Make the words ***need to see*** red by adding the `<color=red>` and `</color>` tags around those words.
    - Rich Text tags is that they support nesting.
    - Try this out by putting the bold <b> </b> tags around the word ***need***. 
    - Once complete, your text should look like this:
        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/BoldColor-624x500.png)
- ***Note:*** 
    - *You can also specify the color by hex code.*
    - *For example, red would use `<color=#ff0000>` or `<color=#ff0000ff>` to specify the alpha value.*


　

## Indenting Lines

Activate screen 8-DownTheHall.

Put the <line-indent=15%> tag at the beginning of the text. This will indent each line by 15% of the width of the text area. In this case, you don’t need a closing tag because you want to indent both lines.


　

　

　

# # 유니티(Unity) - Textmesh Pro(텍스트 메쉬 프로) 한글 사용법 

- https://m.blog.naver.com/cdw0424/221641217203