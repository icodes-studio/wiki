# # HTML 문서 기본 구조 살펴보기

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


　

　

# # 텍스트를 덩어리로 묶어 주는 태그

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
            <blockquote>성이시돌목장은 제주특별자치도 제주시 한림읍 금악리에 있는 목장이다. 특히 이시돌목장은 제주 지역 최초의 
            전기업목장(全企業牧場)으로 1961년 11월 말 제주시 한림읍 금악리에 세워 양돈 사업을 실시하였으며 면양을 사육하였던 
            것으로 알려져 있다. 이시돌목장의 특색있는 건축양식으로 테쉬폰도 유명하다. (출처:향토문화전자대전)</blockquote>
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-1.png)


　

- **소스 코드 표시하기**
    - \<pre\> - 입력한 문자 그대로 브라우저 창에 표시하기
        ```
        <body>
            <h3>로컬 스토리지(Local Storage)를 저장하는 함수 :  </h3>
            <pre>
            function savetheLocal(){
                var second = document.getElementById("second");
                var thevalue = second.value;
                localStorage.setItem(1, thevalue);
                gettheLocal();
            }    
            </pre>
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-2.png)


　

　

# # 텍스트를 한 줄로 표시하는 태그

- **텍스트 강조하기**
    - \<strong\> - 볼드체로 강조
    - \<b\> - 볼드체
    - \<em\> - 이탤릭체로 강조
    - \<bi\> - 이택릭체
        ```
        <body>
            <h2>제주 이색 여행지 - 이중섭 거리</h2>
            <p><strong>주말</strong>마다 <b>'서귀포문화예술디자인시장'</b>이 열립니다.</p>
            <p><em>'아트마켓'</em>이라고도 부르는데, <i>문화예술체험</i>이나 <i>공연관람</i>을 할 수도 있고 <br>
            작가들이 직접 만든 창작예술품 등을 판매하기도 합니다.</p>
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-3.png)


　

- **텍스트 인용하기**
    - \<q\> - 인용 내용 표시하기 (인라인 따옴표)
        ```
        <body>
            <h1>웹 접근성</h1>
            <p>웹의 창시자인 팀 버너스 리 (Tim Berners-Lee)의 
            <q cite="http://www.w3.org/standards/webdesign/accessibility">웹의 힘은 보편성에 있다. 
            장애에 구애없이 모든 사람이 접근할 수 있는 것이 필수적인 요소이다.</q>라는 말로 웹 접근성을 설명한다.</p>
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-4.png)


　

- **일부 텍스트에만 스타일 적용하기**
    - \<mark\> - 형광펜 효과 내기
    - \<span\> - 줄바꿈 없이 영역 묶기
        ```
        <body>
            <h2>야외 텐트를 닮은 건축물 <mark>"테쉬폰"</mark></h2>
            <p>아일랜드 출신 임피제 신부가 1954년 제주에 오면서 목장 숙소로 짓기 시작한 후 사료공장, 성당으로 활용됐습니다. 
            제주에서 점차 다른 지방으로 보급됐지만 현재 제주에만 건축물이 남아있으며, 
            <span style="color:blue;">국내 근현대 건축사의 한 페이지를 보여주는 가치를 지닌다</span>고 전문가들은 평가합니다.</p>
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-5.png)


　

- **일본 글자 표시하기**
    - \<ruby\> - 동아시아 글자 표시하기
        ```
        <body>
            <p>루비(Ruby)는 1995년, 일본의 프로그래머인 마츠모토 유키히로 
            (<ruby>松本行弘<rt>まつもとゆきひろ</rt></ruby>)가 만든 프로그래밍 언어입니다.</p>
        </body>	
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-6.png)


　

 - **이 외에도 다음과 같은 다양한 태그가 있다.**
    |태그|설명|예시|
    |:---|:---|:---|
    |\<abbr\>|약자 표시.<br>title 속성을 함께 사용할 수 있음|\<p\>\<b\>\<abbr title="Internet of Things"\>IoT\</abbr\>\</b\>란 <br>각종 사물에 센서와 통신 기능을 내장해 인터넷에 연결하는 기술을 의미한다.\</p\><br>　<br>![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-7.png)|
    |\<cite\>|웹 문서나 포스트에서 참고 내용 표시|\<p\>내가 경험한 가장 흥미진진한 일은 누군가를 만나는 일이다 <br>- 영화, \<cite\>'비포선셋'\</cite\> 중\</p\>|
    |\<code\>|프로그래밍 언어를 나타낼 때 사용<br>\<pre\> 태그와 함께 사용한다.|\<pre\>\<code\> function save(){...}\</code\>\</pre\>|
    |\<kbd\>|키보드 입력이나 음성 명령 같은<br>사용자 입력 내용|\<p\>웹 화면을 다시 불러오려면 \<kbd\>F5\</kbd\> 키를 누릅니다\</p\>|
    |\<small\>|부가 정보처럼 작게 표시해도 <br>되는 텍스트|\<p\>가격: 13,000원 \<small\>(부가세 별도)\</small\>\</p\>|
    |\<sub\>|아래 첨자|\<p\>물의 화학식은 \<b\>H\<sub\>2\</sub\>O\</b\>다\</p\>|
    |\<sup\>|위 첨자|\<p\>E = mc\<sup\>2\</sup\>\</p\>|
    |\<s\>|취소선|\<p\>\<s\>34,000원\</s\>\<strong\>19,000원\</strong\>\</p\>|
    |\<u\>|밑줄|\<p\>단순히 밑줄을 긋는다면 \<u\>U 태그\</u\>\</p\>|


　

　

# # 목록을 만드는 태그

- **다양한 형태의 순서 목록 만들기**
    - \<ul\> - unordered list
    - \<li\> - list item
    - \<ol\> - ordered list
        > - type 속성: 숫자 불릿의 종류를 선택
        >
        |속성값|설명|
        |:---|:---|
        |1|숫자(기본값)|
        |a|영문 소문자|
        |A|영문 대문자|
        |i|로마숫자 소문자|
        |I|로마숫자 대문자|
        > - start 속성: 시작 순서 선택
        > - reversed 속성: 항목을 역순으로 표시
    - 활용 예
        ```
        <body>
            <h1>1박 2일 가족 여행 코스</h1>
            <ul>
                <li>1일차
                    <ol type="a">
                        <li>해녀박물관</li>
                        <li>낚시체험</li>
                    </ol>
                </li>
                <li>2일차
                    <ol type="a" start ="3">
                        <li>용눈이오름</li>
                        <li>만장굴</li>
                        <li>카약체험</li>
                    </ol>
                </li>
            </ul>
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-9.png)


　

- **설명 목록 만들기**
    - \<dl\> : definition list
    - \<dt\> : definition term
    - \<dd\> : definition description
        ```
        <body>
            <h1>제주 올레 </h1>
            <dl>
                <dt>올레 1코스</dt>
                <dd>코스 : 시흥 초등학교 옆 - 광치기 해변</dd>
                <dd>거리 : 14.6km(4~5시간)</dd>
                <dd>난이도 : 중</dd>
                <dt>올레 2코스</dt>
                <dd>코스 : 광치기 해변 - 온평 포구</dd>
                <dd>거리 : 14.5km(4~5시간)</dd>
                <dd>난이도 : 중</dd>
            </dl>
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-10.png)


　

　

# # 표를 만드는 태그

- **기본적인 표 만들기**
    - \<table\> - 표 전체 윤곽
    - \<tr\> - 행
    - \<td\> - 열
        > - colspan: 컬럼 합치기
        > - rowspan: 행 합치기
    - \<th\> - 제목 셀 (강조)
        ```
        <!DOCTYPE html>
        <html lang="ko">
        <head>
            <meta charset="utf-8">
            <title>표 만들기</title>
            <style>
                table, th, td {
                    border:1px solid #ccc;
                }		
                th {
                    padding:15px;   /* 셀 테두리와 내용 사이의 간격(패딩) */
                }
                tr > td:nth-child(odd) { 
                    width:120px;  /* 홀수번째 열의 너비 : 120px */
                }
                tr > td:nth-child(even) { 
                    width:300px;  /* 짝수번째 열의 너비 : 300px */
                }
            </style>
        </head>
        <body>
            <table>
                <tr>
                    <th>이름</th>
                    <td></td>
                    <th>연락처</th>
                    <td></td>
                </tr>
                <tr>
                    <th>주소</th>
                    <td colspan="3"></td>
                </tr>		
                <tr>
                    <th>자기소개</th>
                    <td colspan="3"></td>
                </tr>
            </table>
        </body>
        </html>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-11.png)


　

- **표에 제목 붙이기**
    - **\<caption\> 태그 사용하기**
        > - \<table\> 태그 바로 다음에 사용
        > - 표의 위쪽 중앙에 표시된다.
        ```
        <body>
            <table>
                <caption>
                    <strong>Modern Browser</strong>
                    <p>국내에서 자주 사용하는 모던 브라우저</p>
                </caption>
                <tr>
                    <th>브라우저</th>
                    <th>제조업체</th>
                    <th>다운로드</th>
                </tr>
                <tr>
                    <th>크롬(Chrome)</th>
                    <td>Google</td>
                    <td>https://www.google.com/chrome/ </td>
                </tr>
                <tr>
                    <th>파이어폭스(Firfox)</th>
                    <td>Mozilla</td>
                    <td>https://www.mozilla.org/ko/firefox/</td>
                </tr>
                <tr>
                    <th> 엣지(Edge) </th>
                    <td> Microsoft </td>
                    <td>https://www.microsoft.com/ko-kr/windows/microsoft-edge</td>
                </tr>
            </table>
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-12.png)
    - **\<figcaption\> 태그 사용하기**
        > - 표를 \<figure\> 태그로 감싼 후 \<figcaption\> 태그를 이용해 제목을 입력한다.
        > - \<figcaption\> 태그가 위치한 곳에 표시된다.
        ```
        <body>	
            <figure>
                <figcaption>
                    <p>국내에서 자주 사용하는 <b>모던 브라우저</b></p>
                </figcaption>
                <table>
                    <tr>
                        <th>브라우저</th>
                        <th>제조업체</th>
                        <th>다운로드</th>
                    </tr>
                    <tr>
                        <th>크롬(Chrome)</th>
                        <td>Google</td>
                        <td>https://www.google.com/chrome/ </td>
                    </tr>
                    <tr>
                        <th>파이어폭스(Firfox)</th>
                        <td>Mozilla</td>
                        <td>https://www.mozilla.org/ko/firefox/</td>
                    </tr>
                    <tr>
                        <th> 엣지(Edge) </th>
                        <td> Microsoft </td>
                        <td>https://www.microsoft.com/ko-kr/windows/microsoft-edge</td>
                    </tr>
                </table>
            </figure>
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-13.png)


　

- **표 구조화 하기**
    - \<thead\> - 제목
    - \<tbody\> - 본문
    - \<tfoot\> - 요약
    - 장점
        > - 화면 낭독기를 통해 표의 구조를 쉽게 이해할 수 있다.
        > - 표의 제목, 본문, 요약 부분에 각각 다른 스타일을 적용할 수 있다.
        > - \<thread\>와 \<tfoot\>을 고정시키고 \<tbody\>만 스크롤되도록 만들 수 있다.
    - 활용 예
        ```
        <!DOCTYPE html>
        <html lang="ko">
        <head>
            <meta charset="utf-8">
            <title>표 만들기</title>
            <style>
                table, th, td {
                    border:1px solid #ccc;
                }
                th, td {
                    width:80px;  /* 셀의 너비 */
                    padding:10px; /* 셀 테두리와 내용 사이의 간격(패딩) */
                }
                thead, tfoot { 
                    background : #eeeeee;  /* thead와 tfoot의 배경 색 */
                }
            </style>
        </head>
        <body>
            <table>
                <caption>제주특별자치도 학교현황(2015.4.1 기준)</caption>
                <thead>
                    <tr>
                        <th>구분</th>
                        <th>학교수</th>
                        <th>학급수</th>
                        <th>학생수</th>
                        <th>교원수</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <th>유치원</th>
                        <td>117</td>
                        <td>252</td>
                        <td>5,547</td>
                        <td>474</td>
                    </tr>
                    <tr>
                        <th>초등학교</th>
                        <td>111</td>
                        <td>1,720</td>
                        <td>37,686</td>
                        <td>2,632</td>
                    </tr>
                    <tr>
                        <th>중학교</th>
                        <td>44</td>
                        <td>699</td>
                        <td>21,274</td>
                        <td>1,412</td>
                    </tr>
                    <tr>
                        <th>고등학교</th>
                        <td>29</td>
                        <td>676</td>
                        <td>22,019</td>
                        <td>1,433</td>
                    </tr>
                    <tr>
                        <th>특수학교</th>
                        <td>3</td>
                        <td>90</td>
                        <td>428</td>
                        <td>160</td>
                    </tr>
                </tbody>
                <tfoot>
                    <tr>
                        <th>합계</th>
                        <td>300</td>
                        <td>3,437</td>
                        <td>86,954</td>
                        <td>6,111</td>
                    </tr>
                </tfoot>
            </table>
        </body>
        </html>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-14.png)


　

- **열을 묶어 스타일 지정하기**
    - \<colgroup\>
    - \<col\>
    - \<col\> 태그와 \<colgroup\> 태그는 \<caption\> 태그 뒤와 \<tr\>, \<td\> 태그 전에 사용해야 한다.
        ```
        <body>
            <table>
                <caption>colgroup 연습</caption>
                <colgroup>
                    <col>
                    <col span="2" style="background-color:blue;">
                    <col style="background-color:yellow">
                </colgroup>
                <tr>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td></td>
                </tr>
            </table>
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-15.png)


　

　

# # 이미지

- **\<img\> 태그 & 속성**
    - src: 이미지 리소스 경로
    - alt: 이미지를 설명해 주는 대체 텍스트
    - width, height: 이미지 크기 조정
        ```
        <body>
            <img src="images/gugudan.jpg" alt="바빠구구단">
            <img src="images/gugudan.jpg" width="250" height="250" alt="바빠구구단">
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-16.png)


　

- **이미지에 설명 글 붙이기**
    - \<figure\> 태그로 \<img\> 태그를 감싸고...
    - \<figcaption\> 태그로 설명 표시
        ```
        <body>
            <figure>
                <img src="images/prod.jpg" alt="예멘 모카 마타리">
                <figcaption>예멘 모카 마타리(Yemen Mocha Mattari)</figcaption>
            </figure>  
        </body>
        ```
        > ![](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/HTML5%2BCSS3/Assets/example-17.png)


　

　

# # 링크 만들기

- **\<a\> 태그 & 속성**
    - 텍스트와 함께 사용하면 텍스트 링크가 되고
    - 이미지와 함께 사용하면 이미지 링크가 된다.
        |속성|설명|
        |:---|:---|
        |href|링크한 문서나 사이트의 주소|
        |target|링크한 내용이 표시될 위치(현재 창 또는 새 창)를 지정<br>_blank: 새 창으로 열림<br>_self: 현재 화면에서 열림<br>_parent: 부모 프레임에 표시<br>_top:프레임을 사용했을 때, 프레임에서 벗어나 전체 화면에 표시한다.|
        |download|링크한 내용을 보여 주는 것이 아니라 다운로드 한다.|
        |rel|현재 문서와 링크한 문서의 관계를 알려준다.|
        |hreflang|링크한 문서의 언어를 지정|
        |type|링크한 문서의 파일 유형을 알랴줌|
        ```
        <body>
            <h1>텍스트 링크 만들기</h1>
            <p><a href="http://www.easyspub.com">이지스퍼블리싱 홈페이지(현재 화면)</a></p>
            <p><a href="http://www.easyspub.com" target="_blank">이지스퍼블리싱 홈페이지(새 창 또는 새 탭)</a></p>
        </body>
        ```


