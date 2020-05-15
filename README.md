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
```json
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

sudo apt install build-essential
sudo apt install libsdl2-dev libsdl2-2.0.0  //usr/lib에 설치 됨.

gcc -I[뭐더라] -l[라이브러리 이름]
ex libSDL2.so  >> -lSDL2
-I/usr/include/SDL2

ldd명령어로 어떤 라이브러리 사용중인지 알 수 있다.

ㅣㄴ 
gcc -o hello helloworld.cpp `sdl2-config --cflags --libs` 
==gcc -o hello helloworld.cpp -I/usr/include/SDL2 -lSDL2

정적 vs 동적 컴파일

git 권장 commit message 형식

1번째 줄 : 커밋 내의 변경 내용을 요약
2번째 줄 : 빈 칸
3번째 줄 : 변경한 이유

