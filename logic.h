#ifndef LOGIC_H
#define LOGIC_H

#include<iostream>
#include<SDL_image.h>
#include <sdl_mixer.h>
#include "defs.h"
#include "graphics.h"
#include "music.h"

using namespace std;


SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer)                //hàm load ảnh
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
	if (texture == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

	return texture;
}



bool Ket_thuc = false;   //kiểm tra xem kết thúc trò chơi hay chưa

bool Kiem_tra_hoa() {       //hàm kiểm tra xem hòa hay không
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)          //nếu bàn còn ô trống thì có nghĩa chưa hòa
            if (BAN_CO[i][j] == NONE)
                return false;
    return true; //nếu bàn không còn chỗ trống mà chưa kết thú
}

void Kiem_tra_ket_thuc(TRANG_THAI Luot_di,SDL_Renderer* renderer){
    SDL_Texture* anhwinx = loadTexture("anhwinx.jpg",renderer);
    SDL_Texture *anhwino = loadTexture("anhwino.jpg",renderer);
    SDL_Texture *anhhoa = loadTexture("anhhoa.jpg",renderer);

    for(int i = 0; i < 3; i++){
        if(BAN_CO[i][0] == Luot_di && BAN_CO[i][1] == Luot_di && BAN_CO[i][2] == Luot_di){
                if(Luot_di == X){
                    SDL_RenderCopy(renderer, anhwinx, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    Mix_HaltMusic();
                    Mix_Music* gMusic = loadMusic("amthanhwin.mp3");
                    play_music(gMusic,1);

                }
                else{
                    SDL_RenderCopy(renderer, anhwino, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    Mix_HaltMusic();
                    Mix_Music* gMusic = loadMusic("amthanhwin.mp3");
                    play_music(gMusic,1);
                }
            Ket_thuc = true;
            return;
        }
        if(BAN_CO[0][i] == Luot_di && BAN_CO[1][i] == Luot_di && BAN_CO[2][i] == Luot_di){
                if(Luot_di == X){
                    SDL_RenderCopy(renderer, anhwinx, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    Mix_HaltMusic();
                    Mix_Music* gMusic = loadMusic("amthanhwin.mp3");
                    play_music(gMusic,1);
                }
                else{
                    SDL_RenderCopy(renderer, anhwino, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    Mix_HaltMusic();
                    Mix_Music* gMusic = loadMusic("amthanhwin.mp3");
                    play_music(gMusic,1);
                }
            Ket_thuc = true;
            return;
        }
    }
    if(BAN_CO[0][0] == Luot_di && BAN_CO[1][1] == Luot_di && BAN_CO[2][2] == Luot_di){
        if(Luot_di == X){
                    SDL_RenderCopy(renderer, anhwinx, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    Mix_HaltMusic();
                    Mix_Music* gMusic = loadMusic("amthanhwin.mp3");
                    play_music(gMusic,1);
                }
                else{
                    SDL_RenderCopy(renderer, anhwino, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    Mix_HaltMusic();
                    Mix_Music* gMusic = loadMusic("amthanhwin.mp3");
                    play_music(gMusic,1);
                }
        Ket_thuc = true;
        return;
    }
    if(BAN_CO[2][0] == Luot_di && BAN_CO[1][1] == Luot_di && BAN_CO[0][2] == Luot_di){
        if(Luot_di == X){
                    SDL_RenderCopy(renderer, anhwinx, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    Mix_HaltMusic();
                    Mix_Music* gMusic = loadMusic("amthanhwin.mp3");
                    play_music(gMusic,1);
                }
                else{
                    SDL_RenderCopy(renderer, anhwino, NULL, NULL);
                    SDL_RenderPresent(renderer);
                    Mix_HaltMusic();
                    Mix_Music* gMusic = loadMusic("amthanhwin.mp3");
                    play_music(gMusic,1);
                }
        Ket_thuc = true;
        return;
    }
    if (Kiem_tra_hoa()) {
        SDL_RenderCopy(renderer, anhhoa, NULL, NULL);
        SDL_RenderPresent(renderer);
        Mix_HaltMusic();
        Mix_Music* gMusic = loadMusic("amthanhhoaa.mp3");
        play_music(gMusic,1);
        Ket_thuc = true;
        return;
    }
}

SDL_Event Su_Kien;
void Kiem_tra_tro_choi(SDL_Event &Su_Kien, SDL_Renderer* renderer, TRANG_THAI &Luot_di){
    while(SDL_PollEvent(&Su_Kien)){
        if(Su_Kien.type == SDL_QUIT){
            Ket_thuc = true;
            return;
        }
        else if(Su_Kien.type == SDL_MOUSEBUTTONDOWN){
            int x = Su_Kien.button.x;
            int y = Su_Kien.button.y;
            int col = x / 200;
            int row = y / 200;

            if (col >= 0 && col < 3 && row >= 0 && row < 3 && BAN_CO[row][col] == NONE) {
                if (Luot_di == X) {
                    Ve_x(renderer, col, row);
                    Mix_Music* gMusic = loadMusic("amthanhclick.mp3");
                    play_music(gMusic,1);
                    BAN_CO[row][col] = X;
                    Kiem_tra_ket_thuc(Luot_di,renderer);
                    Luot_di = O;
                } else if (Luot_di == O) {
                    Ve_o(renderer, col, row);
                    Mix_Music* gMusic = loadMusic("amthanhclick.mp3");
                    play_music(gMusic,1);
                    BAN_CO[row][col] = O;
                    Kiem_tra_ket_thuc(Luot_di,renderer);
                    Luot_di = X;
                }
            }
        }
    }
}

#endif // LOGIC_H
