#include <SDL.h>
#include <SDL_image.h>
#include <SDL_misc.h>

#include "defs.h"
#include "graphics.h"
#include "logic.h"
#include "music.h"






int main(int argc, char* argv[]) {

    SDL_Window* window = SDL_CreateWindow(        //khai báo sdl, các thông tin của cửa sổ chính;
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        CHIEU_RONG_MAN,
        CHIEU_CAO_MAN,
        SDL_WINDOW_SHOWN
    );



    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);             //tạo bút vẽ gì đó hehe



    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);                 //khai báo để có thể sử dụng ảnh, nghe lói zay
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);



    SDL_Texture* background = loadTexture("bachgoraomeo.jpg", renderer);        //load ảnh nền
    SDL_RenderCopy( renderer, background, NULL, NULL);                 //vẽ ảnh lên màn hình
    SDL_RenderPresent( renderer );     //hiển thị hình đã vẽ



    Ve_ban_co(renderer);    //vẽ bàn cờ
    SDL_RenderPresent(renderer); // hiển thị bàn cờ


    Mix_Music* gMusic = loadMusic("amthanhnen.mp3");
    play_music(gMusic,-1);

    while (!Ket_thuc) {   //hàm tiếp tục nếu game chưa kết thúc
        Kiem_tra_tro_choi(Su_Kien, renderer, Luot_di); //hàm kiểm tra trò chơi
        SDL_RenderPresent(renderer);   //hiển thị tất cả những gì đã vẽ khi hoạt động, vẽ x và o
    }



    SDL_Delay(3000); //tạm dừng 3s để người chơi xem



    SDL_DestroyTexture( background ); //xóa ảnh màn hình khi kết thúc
    background = NULL; //reset lại màn hình
    IMG_Quit(); //dừng sử dụng ảnh
    Mix_FreeMusic(gMusic);
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer); //xóa dữ liệu về bút vẽ
    SDL_DestroyWindow(window); //xóa dữ liệu về cửa sổ chính
    SDL_Quit(); //kết thúc

    return 0;
}
