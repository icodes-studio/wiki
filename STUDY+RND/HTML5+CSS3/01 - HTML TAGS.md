## HTML 문서 기본 구조 살펴보기

- **기본 태그**
    ```
    <!DOCTYPE html>
    <html lang="ko">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>내가 처음 만드는 HTML 문서</title>
    </head>
    <body>
        <h1>시간이란...</h1>
        <p>내일 죽을 것처럼 오늘을 살고<br>
        영원히 살 것처럼 내일을 꿈꾸어라</p>
        <img src = "../01/images/first.jpg" />
    </body>
    </html>
    ```
    - \<!DOCTYPE html\>
        > - 현재 문서가 HTML5 언어로 작성된 웹 문서라는 뜻.
    - \<html\> ~ \</html\>
        > - 웹 문서의 시작과 끝을 나타내는 태그.
        > - 웹 브라우저가 \<html\> 태그를 만나면 \</html\> 까지 읽어 표시한다.
    - \<head\> ~ \</head\>
        > - 웹 브라우저가 웹 문서를 해석하기 위해 필요한 정보
        > - 문서 제목 외에는 화면에 표시되지 않는다.
        > - 스타일 및 스크립트 등이 포함되기도 한다.
    - \<body\> ~ \</body\>
        > - 실제 웹브라우저 화면에 나타날 내용.
        > - 앞으로 배울 HTML 태그들은 대부분 여기에 들어간다.


　

- **특수 기호 사용하기**
    ```
    <body>
        ★ ♣ ♥
        &lt; &lang; &langle; &#x027E8;
    </body>
    ```
    - 엔티티 코드 표
        > - https://dev.w3.org/html5/html-author/charref
        > - https://html.spec.whatwg.org/multipage/named-characters.html
    - 윈도우에서 특수 문자 입력하기
        > - 한글 자음을 누른 후 '한자' 키를 누르면 특수 문자 표시
        >
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/ime.gif)


　

　

## 텍스트를 덩어리로 묶어 주는 태그

- **기본적인 텍스트 입력하기**
    - \<hn\> - 제목 표시하기
    - \<p\> - 단락 만들기
    - \</br\> - 줄 바꾸기
    - \<hr\> - 수평 줄 넣기
    - \<blockquote\> - 인용문 넣기
        ```
        <body>
            <h1>제주 이색 여행지</h1>
            <h2>야외 텐트를 닮은 건축물 "테쉬폰"</h2>
            <p>아일랜드 출신 임피제 신부가 1954년 제주에 오면서 목장 숙소로 짓기 시작한 후 사료공장, 성당으로 활용됐습니다.</p>
            <p>제주에서 점차 다른 지방으로 보급됐지만 현재 제주에만 건축물이 남아있는데, <br>
            국내 근현대 건축사의 한 페이지를 보여주는 가치를 지닌다고 전문가들은 평가합니다.</p>
            <hr>
            <blockquote>성이시돌목장은 제주특별자치도 제주시 한림읍 금악리에 있는 목장이다. 특히 이시돌목장은 제주 지역 최초의 전기업목장(全企業牧場)으로 1961년 11월 말 제주시 한림읍 금악리에 세워 양돈 사업을 실시하였으며 면양을 사육하였던 것으로 알려져 있다. 이시돌목장의 특색있는 건축양식으로 테쉬폰도 유명하다. (출처:향토문화전자대전)</blockquote>
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-1.png)
    