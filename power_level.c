#include<windows.h>
#include<stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <smpeg/smpeg.h>
#include <dirent.h>
bool play_sound(char *sound){

   SMPEG *mpeg;
   SMPEG_Info inf;

   SDL_Init(SDL_INIT_VIDEO SDL_INIT_AUDIO); //initialize SDL

   mpeg = SMPEG_new(sound,&inf,1); // create new sound variable

   SMPEG_play(mpeg); //play...

   do {
        SDL_Delay(250);
   }while(!SDL_QuitRequested() && SMPEG_status(mpeg) == SMPEG_PLAYING); //dont delete till done playing..

   SMPEG_delete(mpeg); //delete....
   SDL_Quit(); //free dat mem...

   return 0;
}

int power_status(){
   SYSTEM_POWER_STATUS status; //gotta love windows api
   if(GetSystemPowerStatus(&status)) {
      unsigned char battery = status.BatteryLifePercent;
      /* battery := 0..100 or 255 if unknown */
      if(battery == 255) {
        return 255;
      }
      else {
        return battery;
      }
   } 
   else {
     return 255; //couldn't even get the status....
   }

}
int main(){
 int rc;
 while((rc =power_status()) < 100);

 if(rc == 255){
    play_sound("your_battery_sucks_or_you_arent_on_windows.mp3");
 }
 play_sound("very_annoying_sound.mp3");
 system("ruby script.rb"); //run script that texts user because visual studio c++ won't install on my laptop..gg
 
return 0;

}
