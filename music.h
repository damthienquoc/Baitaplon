#ifndef MUSIC_H
#define MUSIC_H

#include <SDL_mixer.h>



inline Mix_Music* loadMusic(const char* path) {  //hàm load nhạc
    Mix_Music* g_Music = Mix_LoadMUS(path);
    if (g_Music == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                       SDL_LOG_PRIORITY_ERROR,
                       "Could not load music! SDL_mixer Error: %s", Mix_GetError());
    }
    return g_Music;
}


inline void play_music(Mix_Music* gMusic,int n) {      //hàm chạy nhạc
        Mix_PlayMusic(gMusic, n);
}

#endif // MUSIC_H
