//coś dużo bibliotek brachu
#include "getopt.h"
#include "ctype.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "time.h"

#include "libnotify/notify.h"
#include "gdk-pixbuf/gdk-pixbuf.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#define BUFFER 1024

//funkcja odpowiadająca za audio przy rzadkim koniu i papieżu
int play_sound_effect_lucky() {

	int losowe_audio = rand() % 3;

	Mix_Init(MIX_INIT_MP3 || MIX_INIT_OGG);
//failcheck 1
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096) != 0) { printf("zesrało się, nie masz dźwięku, i chuj (program nie mógł załadować drivera audio, nie mój problem)\n"); return -1; }

	char* soundstr = (char*)malloc(BUFFER);
	Mix_Volume(1, 10);
//losowanie audio z dostępnych opcji w switchu
	switch(losowe_audio){
		case 0:
			snprintf(soundstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/audio/goldsound1.wav");
			break;
		case 1:
			snprintf(soundstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/audio/goldsound2.wav");
			break;
		case 2:
			snprintf(soundstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/audio/goldsound3.wav");
			break;
	}
	Mix_Chunk* sounddata = Mix_LoadWAV(soundstr);
//failcheck 2
	if (sounddata == NULL) { printf("ZESRAŁO SIĘ\n"); return -3; }
//failcheck 3
	if (Mix_PlayChannel(1, sounddata, 0) == -1) { printf("zesrało się, nie masz dźwięku, i chuj (nie chce się dźwięk puścić nie wiem kurwa czemu)\n"); return -2; }

	for( ; ; ) {
		if (Mix_Playing(1) != 0) { continue; }
		else {break;}
	}

	Mix_FreeChunk(sounddata);
	Mix_Quit();
	free(soundstr);
	return 0;

}

int play_sound_effect_normal() {

	int losowe_audio = rand() % 3;
	Mix_Init(MIX_INIT_MP3 || MIX_INIT_OGG);
//failcheck 1
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096) != 0) { printf("zesrało się, nie masz dźwięku, i chuj (program nie mógł załadować drivera audio, nie mój problem)\n"); return -1; }

	char* soundstr = (char*)malloc(BUFFER);
	Mix_Volume(1, 3);
		snprintf(soundstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/audio/sound.wav");
	Mix_Chunk* sounddata = Mix_LoadWAV(soundstr);
//failcheck 2
	if (sounddata == NULL) { printf("ZESRAŁO SIĘ\n"); return -3; }
//failcheck 3
	if (Mix_PlayChannel(1, sounddata, 0) == -1) { printf("zesrało się, nie masz dźwięku, i chuj (nie chce się dźwięk puścić nie wiem kurwa czemu)\n"); return -2; }

	for( ; ; ) {
		if (Mix_Playing(1) != 0) { continue; }
		else {break;}
	}

	Mix_FreeChunk(sounddata);
	Mix_Quit();
	free(soundstr);
	return 0;

}

int play_sound_effect_2137() {

	int losowe_audio = rand() % 3;
	Mix_Init(MIX_INIT_MP3 || MIX_INIT_OGG);
//failcheck 1
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096) != 0) { printf("zesrało się, nie masz dźwięku, i chuj (program nie mógł załadować drivera audio, nie mój problem)\n"); return -1; }

	char* soundstr = (char*)malloc(BUFFER);
	Mix_Volume(1, 10);
		snprintf(soundstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/audio/papajsound.wav");
	Mix_Chunk* sounddata = Mix_LoadWAV(soundstr);
//failcheck 2
	if (sounddata == NULL) { printf("ZESRAŁO SIĘ\n"); return -3; }
//failcheck 3
	if (Mix_PlayChannel(1, sounddata, 0) == -1) { printf("zesrało się, nie masz dźwięku, i chuj (nie chce się dźwięk puścić nie wiem kurwa czemu)\n"); return -2; }

	for( ; ; ) {
		if (Mix_Playing(1) != 0) { continue; }
		else {break;}
	}

	Mix_FreeChunk(sounddata);
	Mix_Quit();
	free(soundstr);
	return 0;

}