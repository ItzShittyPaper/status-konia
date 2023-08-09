//coś dużo bibliotek brachu
#include "getopt.h"
#include "ctype.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "time.h"
#include "notifs.c"
#include "audio.c"

#include "libnotify/notify.h"
#include "gdk-pixbuf/gdk-pixbuf.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#define BUFFER 1024

//funkcja main: tu się dzieje cała akcja
int main(int argc, char** argv) {

	int index;
	char *cvalue = NULL;
	int c;

	while ((c = getopt(argc, argv, "igplIGP")) != -1) {
//debug menu
		switch(c) {

			case 'i':
				goto instant;
				break;

			case 'g':
				goto goldinstant;
				break;

			case 'p':
				goto papiezinstant;
				break;

			case 'l':
				goto loop;
				break;

			case 'I':
				goto playsound;
				break;

			case 'G':
				goto goldplaysound;
				break;

			case 'P':
				goto papiezplaysound;
				break;

			default: abort();

		}

	}
//pętla statusu konia
	for( ; ; ) { 
		loop: 
		int losowanie = rand() % 100;
		int czas = rand() % 7 + 3;
		srand(time(NULL));
//sprawdzanie obecnej godziny w czasie odtwarzania pętli
		int godziny, minuty;
  		time_t now;
  		time(&now);
  		struct tm *local = localtime(&now);
  		godziny = local->tm_hour;
  		minuty = local->tm_min;
//jeśli godzina 21:37 to papież
		if(godziny == 20 && minuty == 24){
			generate_random_notif_2137(); play_sound_effect_2137();
		} 
//inaczej jeśli wylosowany rzadki koń
		else if(losowanie == 0){
		        generate_random_notif_lucky(); play_sound_effect_lucky();
		}
//inaczej zwykły koń
		else{
		        generate_random_notif(); play_sound_effect_normal();
		}
//status konia aktualizowany co 3-10 minut
		sleep(czas * 60); 
	}
//instanty do debug menu
	instant: generate_random_notif(); goto playsound;
	goldinstant: generate_random_notif_lucky(); goto goldplaysound;
	papiezinstant: generate_random_notif_2137(); goto papiezplaysound;

	playsound: play_sound_effect_normal();
	goldplaysound: play_sound_effect_lucky();
	papiezplaysound: play_sound_effect_2137();

	for(index = optind; index < argc; index++) { printf ("Non-option argument %s\n", argv[index]); }
	
	return 0;
}
