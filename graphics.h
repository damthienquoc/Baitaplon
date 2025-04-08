
#ifndef GRAPHICS__H
#define GRAPHICS__H

#include <SDL.h>
#include <math.h>
#include "defs.h"

void Ve_ban_co(SDL_Renderer* renderer){          // vẽ bàn cờ

    SDL_SetRenderDrawColor(renderer,0,0,0,255); //màu vẽ là màu đen

    for(int i=1;i<=2;i++){
        SDL_RenderDrawLine(renderer,i * KICH_THUOC_O,0,i * KICH_THUOC_O,CHIEU_CAO_MAN); //vẽ 2 đường dọc
    }

    for(int i=1;i<=2;i++){
        SDL_RenderDrawLine(renderer,0,i * KICH_THUOC_O,CHIEU_RONG_MAN,i * KICH_THUOC_O); //vẽ 2 đường ngang
    }
}

void Ve_x(SDL_Renderer* renderer, int col, int row) {           // Vẽ ô X

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);           // Màu trắng

    SDL_RenderDrawLine(renderer, col * KICH_THUOC_O, row * KICH_THUOC_O, (col + 1) * KICH_THUOC_O, (row + 1) * KICH_THUOC_O); //vẽ đường chéo chính

    SDL_RenderDrawLine(renderer, col * KICH_THUOC_O, (row + 1) * KICH_THUOC_O, (col + 1) * KICH_THUOC_O, row * KICH_THUOC_O); //vẽ đường chéo phụ
}

void Ve_o(SDL_Renderer* renderer,int col, int row){
    SDL_SetRenderDrawColor(renderer,0,0,255,255);      //màu xanh dương

    int Toa_do_tam_x = (col * KICH_THUOC_O) + KICH_THUOC_O / 2;   //tọa độ của hình tròn cần vẽ khi vẽ O x0

    int Toa_do_tam_y = (row * KICH_THUOC_O) + KICH_THUOC_O / 2;     //tương tự ở trên                    y0

    int Ban_kinh_o = KICH_THUOC_O / 4;                               //bán kính bằng 1/4 kích thước của ô là vừa nè @@

    for (int w = 0; w < 360; w++) {

    int dcol = Ban_kinh_o * cos(w * M_PI / 180);        // x = x0 + rcosw

    int drow = Ban_kinh_o * sin(w * M_PI / 180);        // y = y0 + rsinw

    SDL_RenderDrawPoint(renderer, Toa_do_tam_x + dcol, Toa_do_tam_y + drow); //hàm vẽ điểm khi w thay đổi :3
    }
}

#endif
