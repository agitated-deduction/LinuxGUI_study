#include<stdio.h>
#include<string.h>
#include<SDL2/SDL_image.h>

using namespace std;

int main(int argc, char** argv){
	SDL_Event event;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* img_image = NULL;
	SDL_Rect img_rect;

	img_rect.x = 100;
	img_rect.y = 100;
	img_rect.w = 320;
	img_rect.h = 240;

	
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Window", 100, 100, 640, 480,\
			SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	bool isRocket = false;

	do{
		char file_name[16] = {};
		strcpy(file_name, isRocket?"rocket.bmp": "colorbar.bmp");
	img_image = IMG_LoadTexture(renderer, file_name);

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_RenderCopy(renderer, img_image, NULL, &img_rect);
	SDL_RenderPresent(renderer);

		SDL_PollEvent(&event);
		if(event.type == SDL_KEYDOWN){
			switch(event.key.keysym.sym){
				case '1': isRocket = !isRocket;break;
			}
		}
		SDL_Delay(50);
	}while(event.key.keysym.sym!=SDLK_ESCAPE);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
