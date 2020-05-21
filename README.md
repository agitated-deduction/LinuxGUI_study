# Linux gui study
## in bit academy

# <<<딱히 GUI에 관한 내용이 아님 저장소 이름 잘못 지음>>>

x윈도 시스템 : GUI 시스템

X윈도 구조. 

X server
gui클라이언ㅌ트들이 서버에 붙어서 통신
-분산환경에서 유리, 그러나 하나의 컴퓨터라면 좋지는 않음
X프로토콜 저수준 프로토콜이라 생성 파싱이 힘들다
X라이브러리
toolkit 라이브러리(보다 쉬운 윈도우 프로그래밍을 위해 버튼이나 레이블같은 객체 제공) 중 하나가 우리가 배울 SDL

vnc는 x윈도우가 아님/ copy&transfer (쉽게 말해서 동영상같은 원리)

SDL도 XLib위에서 동작함.

Simple DirectMedia Layer
C프로그래밍 언어로 작성된 멀티미디어 라이브러리
장: 단순하고 쉽다. 임베디드에 유리함! 간단한 디스플레이. ex> 출석 관리 임베디드 기기
Cross Platform지원
비디오, 오디오, CD-ROM, 조이스틱, 타이머 등
저수준 기본적인 지원 뿐 아니라 오디오 믹싱, OpenGL과 같은 3D기능등의 복잡한 기능 또한 지원

게임의 시각적 구성요소 처리
이벤트 핸들링 시스템

파일 입출력 시스템
오디오 시스템
CD-ROM 시스템
쓰레드 시스템
로깅 시스템


------------------
ubuntu

패스워드 묻지 않고
로그인의 편의성
 
ssh
 
authorized_keys
id_rsa.pub

필요없는 사용자가 있으면 열어서 삭제하면 됨.

ssh user1@192.168.X.XX
비밀번호...

### sshfs
ubuntu
apt install sshfs

sublime text3
ctrl shift p 
install packages 
sftp

sftp-config.json
```js
{
    // The tab key will cycle through the settings when first created
    // Visit http://wbond.net/sublime_packages/sftp/settings for help
    
    // sftp, ftp or ftps
    "type": "sftp",

    "save_before_upload": true,
    "upload_on_save": false,
    "sync_down_on_open": true,
    "sync_skip_deletes": false,
    "sync_same_age": true,
    "confirm_downloads": false,
    "confirm_sync": true,
    "confirm_overwrite_newer": false,
    
    "host": "192.168.1.36",
    "user": "user1",
    "password": "1234",
    "port": "22",
    
    "remote_path": "/home/user1/myTest",
    "ignore_regexes": [
        "\\.sublime-(project|workspace)", "sftp-config(-alt\\d?)?\\.json",
        "sftp-settings\\.json", "/venv/", "\\.svn/", "\\.hg/", "\\.git/",
        "\\.bzr", "_darcs", "CVS", "\\.DS_Store", "Thumbs\\.db", "desktop\\.ini"
    ],
    "file_permissions": "664",
    "dir_permissions": "775",
    
    //"extra_list_connections": 0,

    "connect_timeout": 30,
    //"keepalive": 120,
    //"ftp_passive_mode": true,
    //"ftp_obey_passive_host": false,
    //"ssh_key_file": "~/.ssh/id_rsa",
    //"sftp_flags": ["-F", "/path/to/ssh_config"],
    
    //"preserve_modification_times": false,
    //"remote_time_offset_in_hours": 0,
    //"remote_encoding": "utf-8",
    //"remote_locale": "C",
    //"allow_config_upload": false,
}

```

우클릭 > SFTP/FTP > Sync Local->Remote...

GCC Tools

sudo apt install build-essential<br>
sudo apt install libsdl2-dev libsdl2-2.0.0  //usr/lib에 설치 됨.

gcc -I[뭐더라] -l[라이브러리 이름]<br>
ex libSDL2.so  >> -lSDL2<br>
-I/usr/include/SDL2

ldd명령어로 어떤 라이브러리 사용중인지 알 수 있다.<br>

ㅣㄴ <br>
gcc -o hello helloworld.cpp `sdl2-config --cflags --libs` <br>
==gcc -o hello helloworld.cpp -I/usr/include/SDL2 -lSDL2

정적 vs 동적 컴파일<br>

git 권장 commit message 형식<br>
<br>
1번째 줄 : 커밋 내의 변경 내용을 요약<br>
2번째 줄 : 빈 칸<br>
3번째 줄 : 변경한 이유<br>

폰트 라이브러리<br>
sudo apt install libfreetype6-dev libsdl2-ttf-dev<br>

image라이브러리<br>
sudo apt install libjpeg9-dev libwebp-dev libtiff5-dev  (라즈베리파이에서 설치가 안됨)<br>
sudo apt install libsdl2-image-2.0.0 libsdl2-image-dev<br>
(png는 폰트 설치할때 같이 설치 됨)<br>

멀티미디어 믹서<br>
sudo apt install libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev<br>
sudo apt install libsdl2-mixer-dev libsdl2-mixer-2.0-0 -y;<br>

sdl2 manual<br>
git clone https://github.com/haxpor/sdl2-manpage.git\<br>

cd sdl2-manpage<br>
sudo ./install.sh
<br>
http://www.libsdl.org/<br>

# SDL
### Simple DirectMedia Layer

* C프로그래밍 언어로 작성된 멀티미디어 라이브러리
* OpenGL 및 Direct3D 를 통해 오디오 키보드, 마우스 조이스틱, 및 그래픽 하드웨어에 대한 저수준 엑세스 제공하고자 설계된 크로스 플랫폼 개발 라이브러리
* c프로그래밍 언어로 작성됐으며 c++에서 기본적으로 동작

#### SDL의 추가 라이브러리
* SDL_image : png, gif, jpeg와 같은 bmp이외의 이미지 형식 지원
* SDL_mixer : wav, mod, mp3 등등 더 많은 형식 세트에서 음악 및 사운드 샘플을 재생할 수 있도록 지원
* SDL_net : 크로스 플랫폼을 위한 네트워크 기능을 제공, 채팅 클라이언트 및 서버 응용 프로그램이 포함
* SDL_ttf : 트루타입 글꼴 사용 기능 제공

## 서피스 (Surface)
* 화면에 표시되는 정보들이 저장되는 일종의 화면의 출력을 위한 메모리버퍼?
실제 화면에 표시되고 있는 모든 정보들이 저장.<br>

비디오메모리는 운영체제만 접근 가능 SDL은 화면에 표시되는 것을 비디오 메모리에 바로 그릴 수 없어서 서피스라고 하는 메모리 공간에 먼저 그리고, 그것을 비디오 메모리에 다시 복사<br>

SDL_INIT_VIDEO로 비디오 장치 사용
```c
if(SDL_Init(SDL_INIT_ViDEO<0){
 perror("could not initialize sdl2\n");
 return 1;
```
서피스 생성( 비디오 프레임)
```c
screenSurface = SDL_GetWindowSurface(window); //Returns the surface associated with the window.
//int SDL_FillRect(SDL_Surface* dst, const SDL_Rect* rect, Uint32 color)
//Use this function to perform a fast fill of a rectangle with a specific color.
SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
SDL_UpdateWindowSurface(window);

SDL_Delay(5000);
SDL_DestroyWindow(window);
SDL_Quit();
```

Blit(Block Transfer): 이미지 데이터를 복사<br>
```c
int SDL_BlitSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect)
```
Use this function to perform a fast surface copy to a destination surface.<br>
src: bmp이미지를 불러운 서피스를 설정<br>
srcrect: 이미지를 자를 위치를 위한 SDL_Rect의 인자. 기본값이면 NULL<br>
dst: 화면에 출력할 서피스 지정<br>
dstrect: 출력 위치를 위한 SDL_Rect의 인자. 기본값이면 NULL


## Poll event 사용하기
```c
do{
 SDL_PollEvent(&event);
 SDL_Delay(100);
}while(event.key.keysym.sym!=SDLK_ESCAPE);
```

## 윈도우의 생성
```c
#include<SDL2/SDL.h>

SDL_Window * window = NULL;
SDL_Init(SDL_INIT_EVERYTHING);
```
* SDL_INIT_AUDIO : 오디오 서브 시스템 초기화
* SDL_INIT_VIDEO : 비디오 서브 시스템 초기화
* SDL_INIT_TIMER : 타이머(timer) 서브 시스템 초기화
* SDL_INIT_CDROM : CD-ROM 서브 시스템 초기화
* SDL_INIT_JOYSTICK : 조이스틱 서브 시스템 초기화
* SDL_INIT_EVERYTHING : 위의 모든 내용 초기화
* SDL_INIT_NOPARACHUTE : Fatal 시그널로부터 SDL을 보호
* SDL_INIT_EVENTTHREAD : SDL의 이벤트 스레드 초기화
```c
/*form*/
SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags)
/*example*/
window = SDL_CreateWindow("Window", 100, 100, 640, 480, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

```
* SDL_Window 구조체 : 윈도우 자체에 대한 모든 정보(크기, 위치, 전체화면, 테두리 등)
* x, y : 윈도우의 위치(x, y), 미정(SDL_WINDOWPOS_UNDEFINED인자)
* w, h : 윈도우의 크기
* flags : 윈도우의 플래그 값
 * SDL_WINDOW_FULLSCREEN : 전체화면으로 창(윈도우) 표시
 * SDL_WINDOW_FULLSCREEN_DESKTOP : 현재 데스크탑 해상도의 전체 화면으로 창 표시
 * SDL_WINDOW_OPENGL : OpenGL 컨텍스트에서 사용 가능한 창 표시
 * SDL_WINDOW_VULKAN : Vulkan인스턴스와 함께 사용할 수 있는 창 표시
 * SDL_WINDOW_HIDDEN : 창을 표시하지 않음
 * SDL_WINDOW_BORDERLESS : 창에 타이틀바나 외곽의 프레임을 표시하지 않음
 * SDL_WINDOW_RESIZABLE : 창 크기 조정 가능
 * SDL_WINDOW_MINIMIZED : 창이 최소화 되어 표시
 * SDL_WINDOW_MAXIMIZED : 창이 최대화 되어 표시
 * SDL_WINDOW_INPUT_GRABBED : 창이 입력 포커스를 잡음
 * SDL_WINDOW_ALLOW_HIGHDPI : 지원되는 경우 최대 DPI모드에서 창을 만듦.

윈도우 위치 설정
```c
SDL_GetWindowPosition(window, &x, &y);
```
윈도우 위치 획득
```c
SDL_GetWindowPosition(window, &x, &y);
```

## 렌더러(Renderer)

렌더링이란 컴퓨터 프로그램을 사용하여 모델로부터 영상을 만들어내는 과정을 말한다.
렌더러는 실제 표시하는 객체를 의미한다.
SDL에서 렌더러를 이용하여 이미지 등의 정보를 사용자에게 표시
SDL_Renderer는 SDL의 렌더링을 처리하는 구조체로 렌더링과 관련된 설정을 추적
```c
SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, int index, Uint32 flags)
```
* SDL_RENDERER_SOFTWARE : 소프트웨어 기반
* SDL_RENDERER_ACCELERATED : 하드웨어 가속을 사용
* SDL_RENDERER_PRESENTVSYNC : 현재는 새로 고침 빈도와 동기화
* SDL_RENDERER_TARETTEXTURE : 렌더러는 텍스처 렌더링 지원

SDL_Renderer구조체의 중요한 함수
```c
SDL_SetRenderDrawColor(renderer, r, g, b, a) //창을 지우는 색상 설정
SDL_RenderClear(renderer) // SDL_SetRenderDrawColor()함수로 설정한 값을 이용해서 대상 렌더러를 지움(채움)
SDL_RenderCopy(renderer, texture, srcrect, dstrect) // SDL_Texture를 렌더링 하는데 사용
SDL_RenderPresent(renderer) // 렌더러에 연결된 창에 그림?
```

## 이벤트처리 (Event)

이벤트 감지는 SDL_PollEvent()나 SDL_WaitEvent()함수 사용<br>
SDL_Event 공용체 이용, 이벤트를 상황에 맞게 처리
```c
typedef union{
 Uint8 type;
 SDL_ActiveEvent key;
 SDL_MouseModtionEvent motion;
 SDL_MouseButtonEvent button;
 SDL_JoyAxisEvent jaxis;
 SDL_JoyBallEvent jball;
 SDL_JoyJatEvent jhat;
 SDL_JoyButtonEvent jbutton;
 SDL_ResizeEvent resize;
 SDL_ExposeEvent expose;
 SDL_QuitEvent quit;
 SDL_UserEvent user;
 SDL_SysWMEvent syswm;
}SDL_Event;
```


SDL의 비디오 표면(Surface)처리<br>
surface: 화면에 출력되는 화면에 대한 이미지 데이터를 저장하는 버퍼.

## 점 그리기 예제
```c
#include<SDL2/SLD.h>
#include<stdio.h>

#define SCREEN_WIDTH 200
#define SCREEN_HIEGHT 200

int main(int argc, char** argv){
  float scale = 1.0;
  if(SDL_Init(SDL_INIT_VIDEO)<0){
    perror("could not initialize sdl2\n");
    return 1;
  }
  SDL_Window* window = SDL_CreateWindow("Draw Point",
            SDL_WINPOS_UNDEFINED,
            SDL_WINPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
  SDL_Renderer* renderer = SDL_CreateRenderer(window -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(renderer);
  
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF);
  SDL_RenderSetScale(renderer, scale, scale);
  SDL_RenderDrawPoint(renderer, 100/scale, 100/scale);
  SDL_RenderPresent(renderer);
  
  SDL_Delay(5000);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  
  SDL_Quit();
  return 0;
}
```

SDL_SetRenderColor(): 색상 지정
SDL_RenderDrawPoint(): x와 y의 위치에 점 그리기
```c
int SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
int SDL_RenderDrawPoint(SDL_Renderer* renderer, int x, int y)
```


## 블렌딩 모드 Blending Mode
블렌딩 : 두 색상을 섞는 기능<br>
블렌딩 모드 : 투명도가 있는 이미지 데이터의 색상 혼합 방식 결정
```c
int SDL_SetRenderDrawBlendMode(SDL_Renderer* renderer, SDL_BlendMode blendMode)
```
두번째 인자인 blendMode를 이용해서 블렌딩 모드 설정.
* SDL_BLENDMODE_NONE : 블렌딩 없음 dstRGBA = srcRGBA
* SDL_BLENDMODE_BLEND : 알파블렌딩 dstRGB = (srcRGB* srcA) + (dstRGB * (1 - srcA)), dstA = srcA + (dstA*(1-srcA))
* SDL_BLENDMODE_ADD : 가산블렌딩 dstRGB = (srcRGB * srcA)+dstRGB, dstA = dstA
* SDL_BLENDMODE_MOD : 곱셈블렌딩 dstRGB = srcRGB*dstRGB, dstA = dstA

## SDL과 이미지
SDL에서 기본적으로 BMP포맷 지원<br>
추가 sdl라이브러리 있음<br>
bmp/pnm/xpm/lbm/pcx/gif/jpeg/png/tga/tiff등의 다양한 이미지 포맷 지원<br>
알파블랜딩 지원<br>
스프라이트 지원<br>
이미지 변환 및 비트 전송 가능<br>

*  BMP 이미지 출력
```c
int SDL_BlitSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect);
```
src: SDL_LoadBMP()함수로 이미지를 불러와서 반환받은 surface<br>
srcrect: 이미지에서의 영역을 나타냄<br>
dst: 출력을 위한 surface<br>
dstrect: 출력 지점에서의 영역을 나타냄

```c
SDL_Rect srcRect = {100, 100, 100, SCREEN_WIDTH/2};
SDL_Rect dstRect = {50, 50, SCREEN_HEIGHT/2, 100};
SDL_BlitSurface(imgSurface, &srcRect, screenSurface, &dstRect);
```
* 이미지 크기 변경
