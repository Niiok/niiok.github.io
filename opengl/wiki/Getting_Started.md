Getting Started
==========
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

 OpenGL API의 이점을 취하고싶습니까? 
만약 당신이 OpenGL API를 활용하는 게임이나 소프트웨어로 인해 이 페이지를 방문했다면, 
제공된 기능을 사용할 수 있게 해주는 적당한 그래픽 드라이버를 설치해야 합니다. 

 OpenGL API를 활용해 프로그램 하기 위해서는, (플랫폼과 개발언어에 따른)드라이버와 개발도구가 필용합니다. 
각 플랫폼에 따른 상세사항은 아래에서 설명합니다.    


> 목차    
> 1. 질의문답
> 2. OpenGL 다운로드 하기
>    1. Windows
>    2. Linux
>    3. macOS
> 3. OpenGL 응용프로그램 작성하기
>    1. Initialization
>       1. OpenGL Context 만들기
>       2. 함수 가져오기
> 4. OpenGL 사용하기
> 5. OpenGL 시각화
> 6. Tutorials and How To Guides
> 7. 개발도구들
> 8. 같이보기
> 9. 외부링크
>
    

## 질의문답
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

						<!--준비중-->


## OpenGL 다운로드 하기
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

3대 주요 데스크탑 운영체제(Linux, macOS, Windows)는 각각 다른 OpenGL 기본 지원 수준을 갖습니다. 
그렇지만 당신의 그래픽 장치 드라이버를 최신으로 유지해야 한다는 것은 동일합니다.

### Windows

적당한 Windows 드라이버 사이트:    
- [AMD/ATI](http://support.amd.com/en-us/download)
- [Intel](https://downloadcenter.intel.com/)
- [NVidia](http://www.nvidia.com/Download/index.aspx)

몇몇 사이트들은 버그를 수정했거나 정식 출시전에 신기능을 제공하는 베타버전의 그래픽 드라이버를 제공하기도 합니다.
- [Guru3D](http://www.guru3d.com/)

드라이버가 없다면, Win98 과 WinMe, Win2000에서는 OpenGL 1.1버전, WinXP, Windows Vista, Windows 7 에서는 OpenGL 1.1 버전으로의 전환을 지원하는 Direct3D가 기본이 됩니다. 
이들은 특별히 빠르지 않으므로 최신 드라이버를 설치하는 것은 언제나 좋은 선택지입니다.    

만약 당신의 시스템이 GPU를 가지고 있지 않거나, 너무 낮은 버전의 OpenGL를 지원해서 쓸모가 없다면, 시스템에 Mesa3D OpenGL 라이브러리를 설치하는 것을 고려해볼만 하다.

### Linux

			준비중

### macOS

			준비중


## OpenGL 응용프로그램 작성하기
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

첫번째로 할 일은 언어를 선택하는것입니다. 
OpenGL에 사용할 수 있는 언어는 C# 과 Java 부터 Python 과 Lua 등 다양합니다. 
몇몇 언어들은 OpenGL에 엮어주는 방법이 여러가지이기도 하지만, 그 중 어떤 것도 공식지원은 아닙니다. 
모든 언어의 OpenGL에 대한 연결은 C/C++에 기반합니다.    

만약 당신이 C/C++을 사용하지 않는다면, 
선택한 언어를 OpenGL에 엮어주는 패키지나 라이브러리를 설치하는 것은 필수적입니다. 
몇몇은 미리 설치되어 기본적으로 지원되기도 하지만, 나머지는 별도의 설치가 필요합니다.    

만약 당신이 C/C++을 사용한다면, 
OpenGL을 링크해줄 수 있는 Visual Studio project, GNU makefile, Cmake file 등의 빌드 환경을 준비해야 합니다. 
Windows에서는 32비트이든 64비트이든 무관하게 "OpenGL32.lib" 라는 이름의 라이브러리를 정적 링크해줘야 합니다. 
Visual Studio뿐만 아니라 대부분의 Windows 컴파일러는 이 라이브러리를 포함합니다.    

Linux에서는 libGL을 링크해줘야하는데, 이는 컴파일 할 때 "-lGL" 인자를 넣어서 할 수 있습니다.    

### Initialization

프로그램에서 OpenGL을 실질적으로 사용하기에 앞서, Initialize(이하 초기화)를 해줘야 합니다. 
왜냐하면 OpenGL은 플랫폼에 무관하게 동작하기에, 
특정 플랫폼에 맞춘 표준 초기화가 존재하지 않기 때문입니다
(각 플랫폼은 서로 다른 방식으로 초기화를 수행합니다.). 
C/C++이 아닌 언어들 또한 다른 방식으로 초기화를 수행합니다.    

OpenGL의 초기화는 크게 두가지 단계로 나뉩니다. 
첫번째 단계는 OpenGL Context를 생성하는 것이고, 
두번째 단계는 OpenGL을 사용하기위한 주요 함수들을 로드하는 것입니다. 
몇몇 C/C++이 아닌 언어들은 이 두단계를 한단계로 병합하여 수행하기도 합니다.

### OpenGL Context 생성

OpenGL Context는 OpenGL의 모든것을 나타냅니다. 
이를 생성하는것은 플랫폼마다 특정적입니다(상이합니다); 서로 다른 언어를 엮는 방법이 다른 만큼이나요.    

만약 당신이 C/C++을 통해 OpenGL을 사용하려 한다면, window toolkit을 사용하는것을 강력히 추천합니다.




