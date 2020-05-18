#include<SDL2/SDL_image.h>
#include<stdio.h>

using namespace std;

int main(int argc, char** argv){
	SDL_Event event;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Rect img_rect;
	SDL_Texture* img_image = NULL;	

	img_rect.x = 100;
	img_rect.y = 100;
	img_rect.w = 320;
	img_rect.x = 240;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("window", 100, 100, 640, 480, \
			SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	img_image = IMG_LoadTexture(renderer, "colorbar.bmp");
		
	do{
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
		SDL_RenderCopy(renderer, img_image, NULL, &img_rect);
		SDL_RenderPresent(renderer);

		SDL_PollEvent(&event);
		if(event.type == SDL_KEYDOWN){
			switch(event.key.keysym.sym){
				case SDLK_LEFT: img_rect.x-=2;break;
				case SDLK_RIGHT: img_rect.x+=2; break;
				case SDLK_UP: img_rect.y-=2; break;
				case SDLK_DOWN:img_rect.y+=2; break;
			}
		}
		SDL_Delay(50);
	}while(event.key.keysym.sym!=SDLK_ESCAPE);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}
