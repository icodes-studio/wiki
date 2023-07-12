# # CHAPTER 8 - TextMesh Pro
    ● Introduction to TextMesh Pro in Unity
    ● Learn about TextMesh Pro in Unity by creating a spooky text-based adventure game.
    ● 한글 사용법
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
- On each screen, you’ll learn a new way to style text.
    - To edit another screen, disable the current one then enable the desired screen.
    - Make sure you leave both ***ScreenFader*** and ***Background*** active.
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
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/BoldColor-624x500.png)
- ***Note:*** 
    - *You can also specify the color by hex code.*
    - *For example, red would use `<color=#ff0000>` or `<color=#ff0000ff>` to specify the alpha value.*


　

## Indenting Lines

- ***Line-indent***
    - Activate screen ***8-DownTheHall***.
    - Put the `<line-indent=15%>` tag at the beginning of the text.
    - This will indent each line by 15% of the width of the text area.
    - In this case, you don’t need a closing tag because you want to indent both lines.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/LineIndent-615x500.png)


　

## Using Overflow Settings

- ***Wrapping & Overflow***
    - Activate screen ***9-Vase***.
    - The ***Overflow*** setting is set to ***Overflow***.
    - The ***Wrapping*** is set to ***Enabled***.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/OverflowDefault-650x492.png)
- ***Linked*** *mode*
    - This mode overflows extra text into a second ***TextMeshProUGUI*** component.
    - Right-click ***Text (TMP)*** and select duplicate.
    - Select the new object and name it ***Text (TMP) Overflow***.
    - Set ***Top*** to ***1200*** and ***Bottom*** to ***350*** on the ***Rect Transform***.
    - Clear the Text Input field.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/Duplicate2.gif)
    - Select the original ***Text (TMP)***, set ***Overflow*** to ***Linked*** and drag the new ***Text (TMP) Overflow*** into the open field.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/OverflowText.gif)
    - The text will now overflow from the top ***Text (TMP)*** to the lower ***Text (TMP) Overflow***.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/OverflowFinal-281x500.png)


　

## Adding Inline Images to Text

- ***To add an icon of a flashlight after the word flashlight.***
    - Start by setting ***13-Stumble*** as the active screen, 
    - then select the icon at ***Assets/RW/Sprites/FlashlightIcon.png***.
    - In Import Settings, change ***Texture Type*** to ***Sprite (2D and UI)***.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/FlashlightImportSettings-367x500.png)
    - Right-click on ***FlashlightIcon.png*** and select ***Create ▸ TextMeshPro ▸ Sprite Asset*** to create a ***Sprite Asset*** in the same folder.
    - Select ***Text (TMP)*** and click the ***Extra Settings*** header to expand the additional settings.
    - Drag the ***FlashlightIcon Sprite Asset*** into the ***Sprite Asset*** field.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/SpriteAsset-608x500.png)
    - Insert the `<sprite index=0>` tag after the word flashlight in Text Input. 
    - The flashlight icon now displays inline.
- ***Note:*** *When you use a sprite sheet with multiple sprites, set the index value in the tag to the index of the sprite you want to reference.*


　

## Adding Color to Inline Sprites

- ***To color the word “flashlight” and the flashlight icon yellow***
    - Place the `<color=#FFEB04>` tag before the word ***flashlight*** and the `</color>` tag after the flashlight icon tag.
    - You’ll see that the word flashlight is yellow, but the icon is still white.
    - Update the sprite tag to `<sprite index=0 color=#FFEB04>`.
    - The sprite now displays a yellow color.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/ColoredFlashlight-602x500.png)


　

## Using Additional Rich Text Tags

- ***The align tag***
    - On screen ***14-Knock***, 
    - use the align tag to align each line left, center, and right. 
    - Each new tag overrides the previous one, so you don’t need any closing tags.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/AlignTag-597x500.png)
- ***Strike & Underline***
    - On screen ***15-WhosThere***,
    - Use the `<s>` tag to strike through and `<u>` tag to underline the text.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/StrikethroughUnderline-604x500.png)
- ***Uppercase & Smallcaps***
    - On screen ***17-Investigate***,
    - Use the `<uppercase>` tag to make all the letters uppercase. 
    - Use the `<smallcaps>` tag to make everything uppercase, but the letters that were previously in lowercase will be a bit smaller.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/Caps-603x500.png)
- ***Offset***
    - On screen ***19-Climb***, 
    - Use the `<voffset>` tag to set a vertical offset. 
    - The numerical value you set is in font units and the closing tag ends all vertical offset.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/VerticalOffset-610x500.png)
- ***See Also***
    - These are just a few of the Rich Text tags you can use with TextMesh Pro.
    - Be sure to check out the [***TextMesh Pro documentation***](http://digitalnativestudios.com/textmeshpro/docs/rich-text/) for the full list of over 30 available Rich Text tags.


　

## Creating Font Assets

- Create a new Font Asset at ***Window ▸ TextMeshPro ▸ Font Asset Creator***. 
- Set the ***Source Font File*** to ***DelaGothicOne-Regular***.
- To get the best results from your Font Asset, pay attention to these properties:
    - ***Padding:***
        > - The spacing between each character in the Font Atlas Texture.
        > - A value of 5 will give you great results for most text in your project.
        > - Here, though, you need large and detailed title text, so set ***Padding*** to ***7***.
    - ***Atlas Resolution:***
        > - The pixel size of the Font Atlas Texture that you’re generating.
        > - For most English character sets, a size of 512×512 is plenty, but you can increase it for higher resolution results.
        > - Set the ***Atlas Resolution*** to ***1024×1024*** for this font.
    - ***Character Set:***
        > - Set to ***ASCII***, unless you’re using another character set.
    - ***Redner Mode:***
        > - For most applications, the default of ***SDFAA*** (Signed Distance Field Anti-Aliasing) will give you the best results.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/FontSettings.png)
- Once you’ve set these properties, click ***Generate Font Atlas***
    - You’ll see a preview of the Font Atlas.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/FontAtlasFull-650x468.png)
- ***SP/PD Ratio***
    - The generator calculates this by dividing the Sampling Point Size by the Padding Value.
    - For best results, this value should be under 10%.
    - If it’s above 10%, either increase the Atlas Resolution or decrease the Padding value, then regenerate the font until the value is below 10%.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/FontOutput-423x320.png)
- ***It's time to use***
    - Click ***Save as…*** and save the Font Asset to ***Assets/RW/Fonts/Font Assets***.
    - Activate screen ***21-UpHere***, 
    - Select ***Text (TMP)*** and set ***Font Asset*** to ***DelaGothicOne-Regular SDF***.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/ChangeFont.gif)


　

## Customizing TextMesh Pro Font Assets

- ***Using TextMesh Pro Material***
    - Set screen ***22-Crawl*** as the active screen in the sample project.
    - Select ***Text (TMP) Top*** and ***Text (TMP) Bottom*** and set Font Asset to ***DelaGothicOne-Regular SDF***.
    - Now, select only ***Text (TMP) Top*** and scroll down to its ***Material*** settings.
    - Go to the ***Outline*** section and use the slider to increase the Thickness.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/DefaultOutline.gif)
- ***But something else interesting is happening.***
    - Although you only modified the Material Properties for ***Text (TMP) Top***, the effect also applies to ***Text (TMP) Bottom***.
    - That’s because both objects reference the ***Default Material***.
    - It’s not a good idea to modify the Default Material.
    - Instead, you’ll create separate ***Material Presets*** for each of the text effects you want.


　

## Creating Material Presets

- ***Material Presets*** are associated with one font.
- You can easily swap between any Material Presets you create for that font.
- ***Creating Material Presets***
    - Select ***Text (TMP) Top*** object.
    - Click the ***three vertical dots*** icon on the Material.
    - Select ***Create Material Preset*** to create a new Material Preset in the directory of the current Font Asset.
    - Set the ***Outline Thickness*** to ***0.25*** for a subtle outline that makes the text stand out from the background.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/CreatePreset.gif)
    - Name this Material Preset ***DelaGothicOne-Regular SDF — Black Outline***.
    - select ***Text (TMP) Bottom*** and create a new Material Preset for it.
    - Set the ***Face Color*** to ***brown*** and the ***Outline Color*** to ***light gray*** with a ***Thickness*** of ***0.25*** to make the text look like dusty boxes.
    - Name the Material Preset ***DelaGothicOne-Regular SDF — Dusty Boxes***.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/DustyBoxes-594x500.png)
    - You can toggle between them and the ***Default Material*** using the Material Preset drop-down on the ***TextMeshProUGUI*** component.
        >![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/CyclePresets.gif)
- ***Note:***
    - *If the Material Preset’s name doesn’t have the Font Asset as a prefix, it won’t show up in this list.*
    - *You must keep the full Font Asset name as the prefix for the Material Preset name.*
    - *You can append any details to the name after that prefix.*


　

## Using Cardboard Presets

- Set screen ***24-LargeBox*** as the active screen.
    - Select ***Text (TMP)*** and set ***Font Asset*** to ***DelaGothicOne-Regular SDF***.
    - Set ***Horizontal*** and ***Vertical Mapping*** to ***Paragraph***.
    - This stretches the texture across all the characters in each paragraph of text.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/CardboardFontSettings-332x500.png)
- Create a new Material Preset named ***Dela Gothic One-Regular SDF – Cardboard*** and set:
    - ***Face Texture*** to ***Assets/RW/Textures/Cardboard***.
    - ***Speed X*** to ***0.1***.
    - ***Outline Color*** to ***Brown***.
    - ***Outline Thickness*** to ***0.15***.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/CardboardMaterialPreset-405x500.png)
    - Now, enter Play Mode and preview the effect.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/Move2.gif)


　

## Using Bevel Presets

- Start by setting ***26-Stopped*** as the active screen.
    - Select ***Text (TMP)*** and set ***Font Asset*** to ***DelaGothicOne-Regular SDF***.
    - Create a new Material Preset named ***Dela Gothic One-Regular SDF – Stopped***.
    - Set the ***Face*** color to ***red***.
    - In the ***Underlay*** section, set ***Offset X*** to ***1***, ***Offset Y*** to ***-1***, and ***Dilate*** to ***1***.
    - In the ***Lighting*** section, under ***Bevel***, set ***Amount*** to ***1*** and ***Width*** to ***0.5***.
    - Tweak the values under ***Local Lighting*** to your artistic liking.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/StoppedSolution-251x500.png)
    - Well done!
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/StoppedResult-650x464.png)


　

## Using Glow Presets

- Start by setting ***28-Skull*** as the active screen.
    - Now, on your own, recreate the glowing outline effect.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/GoldTextResult-398x500.png)
    - Select ***Text (TMP)*** and set ***Font Asset*** to ***DelaGothicOne-Regular SDF***.
    - Create a new Material Preset named ***Dela Gothic One-Regular SDF – Golden***.
    - In the ***Face*** section, set the ***Color*** to a nice gold and ***Dilate*** to ***-0.75***.
    - Check the ***Glow*** section and set the ***Color*** to a similar gold, the ***Offset*** to ***1***, and ***Outer*** to ***0.25***.
    - Also note the ***Face Dilate*** setting can be turned down to shrink the text.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/GoldTextSolution-467x500.png)
    - You can use the image below as a reference for the colors of the Face and the Glow.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/ColourSwatches-1-419x500.png)
    - Now, finish the story by adding the Font Assets and Material Preset to the remaining screens.
    - Then click Play and enjoy your very own text-based adventure game!
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/TheEnd-282x500.png)


　

　

# # 한글 사용법
    ● 텍스트 메쉬 프로 한글 사용법
*https://m.blog.naver.com/cdw0424/221641217203*


　

## 한글 폰트 애셋 만들기 - using Custom Characters

- ***한글 문자셋 준비***
    - 폰트 애셋 아틀라스를 만드는데 사용할 한글 문자셋 데이터가 필요한다.
    - 한글 전체 문자는 1만 자가 넘어가는데 보통 일상에서 쓰는 문자는 2000개 정도 되므로 그 정도만 있어도 사실상 크게 문제될 건 없다.
    - 암튼, 여기 [***상용한글 2350자 다운로드***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/Hangul2350.txt) 항목을 클릭해서 TXT 파일을 받아두자.
- ***폰트 애셋 만들고 적용하기***
    - ***Window ▸ TextMeshPro ▸ Font Asset Creator*** 항목을 선택해서 ***Font Asset Creator*** 창을 열어보자
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/fontassetcreator.png)
    - 여기서 중요한 건 아래 네 가지이다.
    - 1번 ***Character Set*** 항목을 ***Custom Characters*** 항목으로 변경하면 2, 3번이 생긴다.
    - 2번은 여기서 사용하지 않는다. 그냥 비워두자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/fontassetcreator2.png)
    - 3번 ***Custom Character List*** 항목에 아까 다운로드한 파일을 열어서 텍스트를 복사하고 붙여 넣는다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/fontassetcreator3.png)
    - 나머지는 파일 사이즈, 해상도 등에 관한 내용이라 필요에 따라 알아서 입력하고...
    - 4번 ***Generate Font Atlas*** 버튼을 클릭해서 아틀라스를 생성한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/fontassetcreator4.png)
    - ***Save*** 버튼을 클릭해서 완성된 아틀라스를 파일로 저장한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/fontassetcreator5.png)
    - 폰트 애셋 완성!
    - 필요한 TMP 컴포넌트의 ***Font Asset*** 필드에 넣어주면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/fontassetcreator6.png)


　

## 한글 폰트 애셋 만들기 - using Custom Range

- Character Set 필드를 Custom Range 모드로 선택
    - 44032-55203 내용을 입력하면 한글이 모두 적용된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/fontassetcreator7.png)


　

## 한글 폰트 애셋 만들기 - using Dynamic Atlas Population Mode

- 가장 간단하게 TMP 폰트 생성하는 법
    - 먼저 원하는 폰트를 임포트 한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tmp-dynamic1.png)
    - 폰트 우 클릭 Create - Textmeshpro - FontAsset 클릭
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tmp-dynamic2.png)
    - 폰트 생성됨.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tmp-dynamic3.png)
    - 인스펙터 창에서 ***Generation Settings ▸ Atlas Population*** 모드를 ***Dynamic*** 선택
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tmp-dynamic4.png)
    - 폰트 적용 후 내용 입력할 때마다 동시에 이미지로 생성됨
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tmp-dynamic5.png)
    - ***Atlas Population*** 모드가 ***Static*** 이면...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tmp-dynamic6.png)
    - 이미지 생성 안됨
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tmp-dynamic7.png)
    - 왜냐하면 썼다 지워도 이미 생성된 이미지는 그대로 남아 있기 때문
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tmp-dynamic8.png)
    - SDF 같은 용도는 입력 후 ***Static*** 모드로 변경하는 것을 추천


　

## Font Asset Creator 속성 살펴보기

- **Font Asset Creator**
    - **Font Settings**
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/fontassetcreator-property1.png)
    - ***Sampling Point Size***
        > - 아틀라스 텍스쳐에서 한 글자가 차지할 크기이다.
        > - 아래 그림은, 2048x2048 아틀라스 텍스쳐에서 한 글자당 50픽셀을 사용한다는 의미.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/fontassetcreator-property2.png)
        > - 만약 Custom Size가 아니라 ***Auto Sizing*** 모드를 선택했다면, 글자 수만큼 거의 n 등분한 값이 각각의 텍스트 크기로 정해진다.
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/fontassetcreator-property3.png)
    - ***Packing Method***
        > - 빠르게 만들 것인지 (이 방식을 추천하지만 중복된 글자가 패키징 됨)
        > - 그냥 좀 걸리더라도 최적화할 것인지 선택한다.
    - ***Render Mode***
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/fontassetcreator-property4.png)
        > - ***SMOOTH_HINTED:*** 힌팅, 안티 앨리어싱이 된 글꼴 렌더링. 
        > - ***SMOOTH:*** 힌팅없이 안티 앨리어싱된 글꼴 렌더링.
        > - ***RASTER_HINTED:*** 힌팅만하고 안티앨리어싱이 안된 글꼴 렌더링.
        > - ***RASTER:*** 힌팅도 안티앨리어싱도 안된 글꼴 렌더링.
        > - ***SDF(Signed distance field):*** 위의 비트맵 방식과는 다르게 거리에 따라 선명도를 계산하여 보여주는 방식.

