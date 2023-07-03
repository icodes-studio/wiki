# CHAPTER 4 - 앵커를 찾아서
    ● 디바이스 해상도가 변경되면 UI가 어떻게 될까?
    ● UI는 무턱대고 줄이거나 늘리면 안 된다.
    ● 애초에 모든 크기에 들어맞는 UI 라는 게 있을 리 없어.
    ● 앵커 시스템을 사용하면 동적인 반응형 디자인 구현 가능.
*https://docs.unity3d.com/2023.2/Documentation/Manual/UIBasicLayout.html*


　

- **앵커 기초 개념**
    - *https://wergia.tistory.com/184*
    - *https://blog.danggun.net/4431*
    - Rect Transform 컴포넌트의 앵커 속성
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/rect-transform-anchor.png)
    - Anchor는 상위 오브젝트의 어디를 기준으로 어떻게 위치할 것인지 설정.
    - Pivot은 자신의 기준점을 어디로 설정하여 위치할 것인지 정하는 것.


　

- **PIVOT 리마인드**
    - 피벗은 선택한 UI의 위치를 정하는 기준점이다.
    - 피벗을 에디터 씬 뷰에서 수정하려면 툴의 기준점을 Pivot으로 설정.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/pivot.png)
    - 마우스로 피벗 위치를 바꿀 수 있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/pivot.gif)
    - 피벗 위치를 바꾸면 기존 자리를 지키기 위해 위치가 자동 조절된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/pivot-position.png)
    - 꽤 유용하지만 경우에 따라 거슬리는 경우가 있다.
    - 그럴 때는 "Raw edit mode"를 키면 위치를 자동 조절하지 않는다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/raweditmode-on.png)
    - TIP : 씬 뷰에서 피벗 위치를 바꾸는 경우는 이 모드가 적용 안됨.


　

- **앵커 프리셋**
    - 빨간색 십자선 사각형 이미지를 선택하면 앵커 프리셋 창이 뜬다.
    - 자주 쓰이는 앵커 패턴을 제공해 주는 프리셋.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/anchor-preset.png)
    - 너비 앵커에는 left, center, right, stretch를 제공한다.
    - 높이 앵커에는 top, middle, bottom, stretch를 제공한다.
    - 이들 옵션은 부모 영역에서의 내 위치 기준을 의미. (기준점은 Pivot)
    - 반면 **stretch** 옵션은 의미가 조금 다른데, 너비, 높이 앵커 프리셋을 둘 다 stretch로 변경하면 원래는 Pos X, Pos Y, Width, Height이던 렉트 트랜스폼의 프로퍼티가 **Left, Top, Right, Bottom**으로 변경된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/stretch.png)
    - 이것은 부모 영역의 경계선으로부터의 거리. 즉 마진을 의미한다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/stretch1.png)
    - 이는 부모 영역의 너비와 높이의 변화에 영향을 받는다는 것이다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/stretch2.png)


　

- **앵커 이해하기 - 예시#1**
    - 빨간 이미지 UI를 항상 화면 왼쪽 상단에 위치 시키고 싶은데,
    - 앵커가 middle, center인 상태에서 아래와 같이 배치한다면...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/anchor-example1.png)
    - 해상도 종횡비가 변경되면 노답. (화면에서 벗어난다)
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/anchor-example2.png)
    - 앵커를 top, left로 설정해 주고 위치값을 적절하게 잡아주면 해결.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/anchor-example.gif)


　

- **앵커 이해하기 - 예시#2**
    - 화면 상단에 항상 아래와 같은 상단 바를 띄우고 싶은데,
    - 앵커가 middle center인 상태에서 아래와 같이 배치하면...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/understand1.png)
    - 해상도 종횡비가 변경되면 이렇게 병신이 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/understand.gif)
    - 이때는 앵커를 top, stretch로 설정해 주고 위치를 잡아주면 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/understand2.png)
    - 문제 해결!
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/understand3.gif)


　

- **Tips**
    - 앵커 프리셋을 선택할 때...
    - \<ALT\> 키를 누르면 컨트롤의 위치가 적절히 이동.
    - \<SHIFT\> 키를 누르면 Pivot(기준점) 위치가 적절히 이동.
    - \<ALT\> 키와 \<SHIFT\> 키를 동시에 누르면 Pivot 위치와 컨트롤 위치가 적절히 이동.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/shortcut.png)
    - 그리고 당연한 얘기지만... 앵커는 커스텀 하게 변경이 가능하다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/25.gif)
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/26.gif)


　

　

# # 여러 해상도의 UI 설계 - 사례 #1
    ● 게임은 아주 다양한 스크린 해상도를 지원해야 하는 경우가 많다.
    ● 간단한 사례 연구를 통해 다양한 방법을 살펴보고 비교하자.
*https://docs.unity3d.com/2023.2/Documentation/Manual/HOWTO-UIMultiResolution.html*

　

- [**참고 자료 - UNITY DOCUMENTATION**](https://docs.unity3d.com/kr/2021.1/Manual/HOWTO-UIMultiResolution.html)
    - 아래와 같이 세 개의 버튼이 스크린의 각 코너에 있으며, 목표는 이 레이아웃을 다양한 해상도에 맞게 조정하는 것.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/UI_MultiResBase.png)
    - 네 가지 스크린 해상도에 대해 고민해 보자.
        > - 세로(640 x 960)
        > - 가로(960 x 640)
        > - 세로(320 x 480)
        > - 가로(480 x 320)

　

- **앵커를 사용하여 여러 종횡비 조정**
    - UI 요소는 디폴트(middle, center)로 부모 사각형의 중심에 위치.
    - 즉 중심으로부터 일정한 오프셋을 유지한다.
    - 이때 해상도가 가로방향 종횡비로 변경되면 버튼이 화면을 벗어남.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/UI_MultiResCenter.png)
    - 해결 방법은 지금까지 배운 대로...
    - 왼쪽 상단 버튼의 앵커는 left, top 설정.
    - 왼쪽 하단 버튼의 앵커는 left, bottom 설정.
    - 오른쪽 하단 버튼의 앵커는 right, bottom 설정.
    - 버튼이 해당 코너에 각각 위치한 후에는 다른 종횡비로 해상도를 변경할 때도 고정된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/UI_MultiResCorners.png)
    - 스크린 크기를 더 크거나 작은 해상도로 변경하면?
    - 버튼 역시 해당 코너에 앵커 된 상태로 남아 있다. 그러나...
    - 원했던 결과 일 수도 있으나... 버튼 크기가 병신이 되어버림.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/UI_MultiResSizeChange.png)
    - 결국, 버튼이 스크린이 작을수록 같은 비율로 작아져야 한다.
    - **Canvas Scaler** 컴포넌트가 도움이 될 수 있다.


　

- **스크린 크기에 따른 스케일링**
    - **Canvas** 게임 오브젝트에 **Canvas Scaler** 컴포넌트가 있다.
    - 모든 UI 요소는 이 게임 오브젝트의 자식이다.
    - 이 컴포넌트의 **UI Scale Mode**를 **Scale With Screen Size**로 설정.
    - 이 스케일 모드에서 레퍼런스로 사용할 해상도를 지정.
    - 현재 스크린 해상도가 이 레퍼런스 해상도보다 더 크거나 작은 경우 캔버스의 스케일 팩터가 적절하게 설정되므로 모든 UI 요소가 스크린 해상도에 맞게 함께 확대 또는 축소된다.
    - 여기에서는 레퍼런스 해상도를 세로 해상도인 640 x 960 설정
    - 스크린 해상도를 320 x 480으로 변경하면 아래처럼 예쁘게 나옴.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/UI_MultiResReferenceResolution.png)
    - BUT, 이때 스크린 해상도를 가로 종횡비인 960 x 640으로 변경하면?
    - 아래 그림처럼 버튼이 다시 병신이 된다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/UI_MultiResLandscapeWrongScaling.png)
    - 가로 종횡비에서 버튼이 더 크다. 이유는...
    - 디폴트(Match:0)로 현재 해상도의 너비를 캔버스 스케일러의 너비와 비교하고, 그 결과가 모든 것을 스케일 하는 스케일 팩터로 사용된다. 가로 해상도인 960 x 640은 세로 캔버스 스케일러의 레퍼런스 640 x 960보다 너비가 1.5배 크므로 이 레이아웃은 1.5배 확대되는 것이다.
    - Canvas Scaler의 Match 옵션을 0.5로 설정해서 균형을 맞추면...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/UI_MultiResAllResolutions.png)
    - 가로 해상도는 1.5배 넓지만 높이가 1.5배 작기 때문에 이 두 팩터는 서로 상쇄되어 최종 스케일 팩터가 1이 되므로 버튼 크기가 유지.

　

　

# # 여러 해상도의 UI 설계 - 사례 #2

　

- 아래 그림과 같은 체력 게이지 컨트롤을 배치한다고 해보자.
    - 　
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/resolution-1.png)


　

- **기본 환경**
    - 체력 게이지는 슬라이더 컨트롤을 이용해 만들었다.
    - Canvas Scaler 옵션과 슬라이더 Rect Transform 설정은 아래와 같다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/resolution-4.png)
    - 고정 픽셀 모드에서 stretch 앵커로 left/right 마진을 200 픽셀 주었다.


　

- **해상도 변경**
    - 가로 해상도가 낮은 3:2 종횡비에서의 체력 게이지 모습
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/resolution-2.png)
    - 가로 해상도가 더 낮은 5:4 종횡비에서의 체력 게이지 모습
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/resolution-3.png)
    - 또한 같은 스크린 크기라도 해상도가 낮으면 **왕따시**
    - 문제는 고정 픽셀 크기 모드 - Constant Pixel Size Mode


　

- **스케일 조정하기**
    - Scale With Screen Size 모드를 사용해 보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/scalewithscreensize.png)
    - 사례 #1에서 설명했으니 자세한 설명은 생략하고 결과 화면을 보자.
    - 가로 해상도가 낮은 3:2 종횡비에서의 체력 게이지 모습
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/3-2.png)
    - 가로 해상도가 더 낮은 5:4 종횡비에서의 체력 게이지 모습
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/5-4.png)
    - 멋지게 적용되었다. 하지만...
    - 원하는 해상도에 맞추기 위해 게이지가 전체적으로 작아졌다.
    - 만약 이 게이지 UI가 가독성이 너무 중요해서 크기를 포기할 수 없다면?


　

- **근본적 해결을 위해 단위 바꾸기**
    - 포지션과 크기를 물리적인 단위로 지정해야 한다.
    - Constant Physical Size 모드로 바꾸어 보자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/constantphysicalsize.png)
    - 스크린 크기가 작아져도 물리적인 크기가 유지된다.
    - 얼추 보기엔 Constant Pixel Size 모드와 같아 보이지만 다른 개념임.
    - Constant Pixel Size 모드는 해상도과 관련이 있는 것이고
    - Constant Physical Size 모드는 스크린의 물리적 크기와 관련이 있다.
    - 암튼, 아래 그림을 보면 마진이 너무 크게 잡혀있다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/constant-physical-size-1.png)
    - Constant Pixel Size 모드 때처럼 금방 찌그러졌다.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/constant-physical-size-2.png)
    - 아예 화면에서 안 보이기까지...
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/constant-physical-size-3.png)
    - 이유는 위치 및 마진을 측정하는 방식이 완전히 달라졌기 때문.
    - Canvas Scaler에 대해 단위를 바꿨으니 다시 계산해야 한다.
    - 게이지 슬라이더의 Left, Right 값을 100으로 변경하자.
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Unity3D%20UI%20Essential/Assets/constant-physical-size-4.png)


　

- **무엇을 선택할 것인가?**
    - Canvas Scaler 각 모드들은 각기 장단점이 있다.
    - 보통은 Scale With Screen Size 모드가 좋은 해결책이 된다.
    - 특수한 목적과 필요에 따라 다른 모드의 캔버스를 별도로 생성해서 대응하는 방식이 좋아 보인다.
  