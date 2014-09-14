#include<windows.h>
#include<stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <smpeg/smpeg.h>
#include <dirent.h>
int main(){

SDL_Surface *screen;
SMPEG *mpeg;
SMPEG_Info info;

SDL_Init(SDL_INIT_VIDEO SDL_INIT_AUDIO);

mpeg = SMPEG_new("1.mp3",&info,1);

SMPEG_play(mpeg);

do {
	SDL_Delay(250);
}while(!SDL_QuitRequested() && SMPEG_status(mpeg) == SMPEG_PLAYING);

SMPEG_delete(mpeg);
SDL_Quit();
 

SYSTEM_POWER_STATUS status;
if(GetSystemPowerStatus(&status)) {
    unsigned char battery = status.BatteryLifePercent;
    /* battery := 0..100 or 255 if unknown */
    if(battery == 255) {
        printf("Battery level unknown !");
    }
    else {
        printf("Battery level : %u%%.", battery);
    }
} 
else {
    printf("Cannot get the power status, error %lu", GetLastError()); 
}

}
