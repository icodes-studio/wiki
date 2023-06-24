## HTML 문서 기본 구조 살펴보기

- 기본 태그
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


　

- 특수 기호 사용하기
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
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML%2BCSS/Assets/ime.gif)
