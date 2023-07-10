# CHAPTER 7 - Addition

- [***Sprite Atlas***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/CHAPTER%207%20-%20Addition.md#sprite-atlas)
- [***TextMesh Pro***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/CHAPTER%207%20-%20Addition.md#textmesh-pro)


　

　

# # Sprite Atlas
    ● Project Settings 살펴보기
    ● Sprite Atlas 생성하기
    ● Sprite Atlas 속성 살펴보기
    ● Tight Packing 자세히 살펴보기
    ● 스크립트로 스프라이트 아틀라스 사용하기


　

- ***References***    
    - ***https://docs.unity3d.com/2023.2/Documentation/Manual/class-SpriteAtlas.html***
    - ***https://skuld2000.tistory.com/28***
    - ***https://youtu.be/PEMsZDb3yPs***
    - ***https://everyday-devup.tistory.com/62***
    - ***https://young-94.tistory.com/85***
    - [***https://maintaining.tistory.com/***](https://maintaining.tistory.com/entry/Unity-%EC%8A%A4%ED%94%84%EB%9D%BC%EC%9D%B4%ED%8A%B8-%EC%95%84%ED%8B%80%EB%9D%BC%EC%8A%A4Sprite-Atlas-%EC%82%AC%EC%9A%A9-%EB%B0%A9%EB%B2%95)


　

## Overview

- 렌더링 할 때 텍스쳐 별로 한 번의 ***드로우 콜(DrawCall)*** 작업이 발생한다.
- 많은 드로우 콜은 렌더링 성능에 안좋은 영향을 미치는 비싼 작업.
- 게임 내 n개의 UI 요소가 각기 다른 텍스쳐 스프라이트를 사용한다면 n번의 드로우 콜이 발생.
- 이들 각각의 스프라이트들을 ***한장의 텍스쳐에*** 모아놓고 사용한다면 ***드로우 콜을 1회로*** 줄일 수 있다.
- 이렇게 여러 개의 ***스프라이트(Sprite)*** 텍스쳐를 한 장의 큰 텍스쳐에 모아놓은 것을 ***아틀라스(Atlas)*** 라고 한다.
- 유니티에서는 예전부터 [*Sprite Packer*](https://learnandcreate.tistory.com/131) 라는 툴을 통해 아틀라스를 제작하고 사용할 수 있었다.
- 하지만 2019 이상부터 레거시라는 꼬리표가 달리고 [***Sprite Atlas***](https://skuld2000.tistory.com/28)가 사용되더니 2020 이상부터는 ***Sprite Atlas***만 사용 가능하다.


　

## Getting Started

- ***메뉴 ‣ Edit ‣ Project Settings*** 창을 열고 ***Edit ‣ Sprite Packer*** 항목을 확인
- ***Project Settings - Sprite Packer***
    - ***Unity 2019.2.10*** 버전을 기준으로 아래의 화면이 보인다.
        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-settings.png)
    - ***Unity 2022.3.4*** 버전을 기준으로 아래의 화면이 보인다.
        ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-settings2.png)
    - ***Enabled For Builds(Legacy Sprite Packer)***
        > - 기존 스프라이트 패커를 사용한다.
        > - 빌드 시에만 아틀라스를 생성, 로드 한다.
        > - 에디터의 Play 모드에서 실행하면 아틀라스가 아닌 각각의 스프라이트를 사용한다.
    - ***Always Enabled(Legacy Sprite Packer)***
        > - 기존 스프라이트 패커를 사용하여 아틀라스를 생성한다.
        > - 에디터의 Play 모드에서 실행해도 아틀라스를 생성, 로드 한다.
        > - 씬 뷰의 일반 에디트 모드에서는 아틀라스를 사용하지 않는다.
    - ***Enabled For Builds***
        > - 새로운 스프라이트 아틀라스를 사용한다.
        > - 빌드 시에만 아틀라스를 생성, 로드 한다.
        > - 에디터의 Play 모드에서 실행하면 아틀라스가 아닌 각각의 스프라이트를 사용한다.
    - ***Always Enabled***
        > - 새로운 스프라이트 아틀라스를 사용한다.
        > - 에디터의 Play 모드에서 실행해도 아틀라스를 생성, 로드 한다.
        > - 씬 뷰의 일반 에디트 모드에서는 아틀라스를 사용하지 않는다.
    - ***Sprite Atlas V2***
        > - *https://docs.unity3d.com/2022.1/Documentation/Manual/SpriteAtlasV2.html*
        > - *https://forum.unity.com/threads/sprite-atlas-v2-in-unity-2022-1.1327704/*


　

- **Sprite Atlas - Creating**
    - ***메뉴 ‣ Asset ‣ Create ‣ 2D ‣ Sprite Atlas*** 항목 선택
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-create.png)
    - 스프라이트 아틀라스가 생성된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-create2.png)


　

- **Packing**
    - ***Objects for Packing*** 칸에 있는 ***+ 버튼을*** 클릭해서 원하는 스프라이트 또는 폴더를 선택한다.
    - Asset 폴더 내의 모든 스프라이트와 해당 스프라이트 들이 들어있는 폴더들의 목록이 뜬다.
    - 여기에서 폴더 또는 스프라이트 들을 선택해 추가.
    - 또는 프로젝트 뷰에서 폴더 또는 스프라이트들을 ***드래그*** 해서 Objects for Packing 영역으로 드래그.
    - 인스펙터 창의 우측 상단의 ***자물쇠를*** 풀어줘야 동작한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-packing.gif)


　

 ## Optimization

- 스프라이트 아틀라스의 패킹 최적화 옵션들
- **Properties**
    - 생성된 스프라이트 아틀라스의 인스펙터 창 속성
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-property.png)
    - **Type**
        > - ***Master Type은*** 묶은 스프라이트 아틀라스를 그대로 사용하는 것.
        > - ***Variant Type은*** Master Type을 기준으로 퀄리티 속성을 변형하여 최적화된 아틀라스를 다시 추출한다.
        > - 예를 들어, 아틀라스 크기를 조절하여 저사양 단말기에서 메모리를 적게 사용할 수 있다.
    - **Including in Build**
        > - 켠 경우 빌드 시에 스프라이트 아틀라스가 포함되며, 실행될 때 자동으로 메모리에 로드된다.
        > - 끈 경우 빌드시에 스프라이트 아틀라스가 ***Resources*** 폴더에 있다면 포함되지만, 에셋번들인 경우 포함되지 않는다.
    - **Allow Rotation**
        > - 패킹할 때, 공간 최적화를 위해 필요하다면, 스프라이트가 회전할 수 있도록 허용한다.
    - **Tight Packing**
        > - 스프라이트의 아웃라인에 따라 패킹하는 것으로 아틀라스의 공간을 효과적으로 사용할 수 있다.
        > - 아웃라인이 명확하지 않은 경우 렌더링 시 이미지간의 침범이 발생할 수 있다.
        > 　![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tight-packing-example.png)
    - **Padding**
        > - 스프라이트 사이에 띄어진 공간 픽셀 수를 정의한다.
        > - Padding이 없으면 렌더링 시 이미지간 침범이 발생할 수 있다.
    - **Objects for Packing**
        > - 아틀라스로 묶을 스프라이트를 넣는 곳.


　

- **Tight Packing**
    - ***Tight Packing*** 옵션과 ***Allow Rotation*** 옵션은 공간의 낭비없이 스프라이트들을 배치하는 기능이다.
    - 즉, 필요에 따라 스프라이트를 회전하거나 알파 영역 공간을 침범해서 촘촘하게 스프라이트를 배치한다.
    - 해당 옵션을 끈 상태로 패킹을 하면 자신의 스프라이트 사이즈 만큼의 공간을 확보한 상태로 아틀라스가 만들어진다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tightpacking2.png)
    - 만약 이들 옵션을 사용하여 패킹을 하게 되면
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tightpacking3.png)
    - 스프라이트가 회전되거나 스프라이트의 사각 영역 내에 다른 텍스쳐들이 겹쳐 배치 된 것을 알 수 있다.
    - 문제는 회전되거나 겹친 스프라이트를 사용 해보면, 그대로 뒤집히고 겹친 텍스쳐들까지 함께 출력시켜 버린다는 것이다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tightpacking-error.png)
    - 이러한 현상을 막으려면 해당 UI 가 출력되는 컨트롤에 가서 ***Use Sprite Mesh*** 항목을 체크하면 된다.
    - 단, Use Sprite Mesh 기능은 Image Type 이 ***Simple*** 일 때에만 가능하다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/tightpacking-fix.png)
    - Tight Packing 옵션은 ***스프라이트의 아웃라인에*** 따라 공간을 계산하여 최적화 패킹을 한다.
    - 따라서 좀 더 커스텀하게 패킹을 동작시키려면 ***Sprite Editor*** 창에서 ***Custom Outline을*** 수정하면 된다.
        > *https://docs.unity3d.com/kr/2021.1/Manual/SpriteOutlineEditor.html*
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/2DCustomOutline_7.png)


　

## Scripting

- **동적으로 스프라이트 로드하기**
    - Resources 폴더에 SpriteAtlas 준비
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-script2.png)
    - SpriteManager 빈 오브젝트와 SpriteManager.cs 스크립트를 생성하여 서로 바인딩
    - SpriteManager.cs 코드 작성
        ```
        using UnityEngine;
        using UnityEngine.UI;
        using UnityEngine.U2D;

        public class SpriteManager : MonoBehaviour
        {
            public SpriteAtlas spriteAtlas;
            public Image img;

            void Start()
            {
                if (spriteAtlas == null)
                    spriteAtlas = Resources.Load<SpriteAtlas>("SpriteAtlas");
            }

            void Update()
            {
                if (Input.GetMouseButtonDown(0))
                    img.sprite = GetSprite("ChomperAttack_00001"); // 좌클릭
                if (Input.GetMouseButtonDown(1))
                    img.sprite = GetSprite("ChomperAttack_00007"); // 우클릭
                if (Input.GetMouseButtonDown(2))
                    img.sprite = GetSprite("ChomperAttack_00013"); // 휠클릭
            }

            public Sprite GetSprite(string spriteName)
            {
                return spriteAtlas.GetSprite(spriteName);
            }
        }
        ```
    - 대충 Image UI 컨트롤 연결하고 실행하면
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/spriteatlas-script.gif)


　

　

# # TextMesh Pro
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







　

　

　

　

# # 유니티(Unity) - Textmesh Pro(텍스트 메쉬 프로) 한글 사용법 

- https://m.blog.naver.com/cdw0424/221641217203