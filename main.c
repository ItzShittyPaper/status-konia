#include "getopt.h"
#include "ctype.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

#include "libnotify/notify.h"
#include "gdk-pixbuf/gdk-pixbuf.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#define BUFFER 1024
const char* status_gaming[8] = {"status konia", "Flak", "nie żyje", "zajebisty",  "stoi petarda", "zwalony", "dzień udany robimy", "dobry koń"};

void generate_random_notif() {
			notify_init("Status konia");
		        char* iconstr = (char*)malloc(BUFFER);
			int dobry_cykl = rand() % 8;
			snprintf(iconstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/cygar.jpg");
			NotifyNotification * status = notify_notification_new ("Status Konia", status_gaming[dobry_cykl], iconstr);
			notify_notification_show (status, NULL);
			g_object_unref(G_OBJECT(status));
			free(iconstr);
		        notify_uninit();
}
		

void generate_random_notif_lucky() {
		        notify_init("Status konia");
		        char* iconstr = (char*)malloc(BUFFER);
			snprintf(iconstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/goldcygar.png");
			NotifyNotification * status = notify_notification_new ("Status Konia", "przezajekurwabisty", iconstr);
			notify_notification_show (status, NULL);
			g_object_unref(G_OBJECT(status));
			free(iconstr);
		        notify_uninit();		
}


int play_sound_effect() {

	Mix_Init(MIX_INIT_MP3 || MIX_INIT_OGG);

	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096) != 0) { printf("zesrało się, nie masz dźwięku, i chuj (program nie mógł załadować drivera audio, nie mój problem)\n"); return -1; }

	char* soundstr = (char*)malloc(BUFFER);
	Mix_Volume(1, 32);
	snprintf(soundstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/sound.wav");

	Mix_Chunk* sounddata = Mix_LoadWAV(soundstr);
	if (sounddata == NULL) { printf("ZESRAŁO SIĘ\n"); return -3; }

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

int main(int argc, char** argv) {

	int index;
	char *cvalue = NULL;
	int c;

	while ((c = getopt(argc, argv, "iIls")) != -1) {

		switch(c) {

			case 'i':
				goto instant;
				break;

			case 'I':
				goto goldinstant;
				break;

			case 'l':
				goto loop;
				break;

			case 's':
				goto playsound;
				break;

			default: abort();

		}

	}

	for( ; ; ) { 
		loop: 
		int losowanie = rand() % 100;
		srand(time(NULL));
		if(losowanie == 0){
		        generate_random_notif_lucky(); play_sound_effect();
		}
		else{
		        generate_random_notif();
		}
		sleep(5 *60); 
	}

	instant: generate_random_notif(); return 0;
	goldinstant: generate_random_notif_lucky(); goto playsound;
	playsound: play_sound_effect();

	for(index = optind; index < argc; index++) { printf ("Non-option argument %s\n", argv[index]); }
	
	return 0;
}
