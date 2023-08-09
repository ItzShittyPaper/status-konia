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

//sekcja funkcji dla powiadomień statusu konia

//zwykły koń
void generate_random_notif() {
	const char* status_gaming[10] = {"status konia", "Flak", "nie żyje", "zajebisty",  "stoi petarda", "zwalony", "dzień udany robimy", "dobry koń", "głodny", "zjedzony"};
	notify_init("Status konia");
	char* iconstr = (char*)malloc(BUFFER);
	int dobry_cykl = rand() % 10;
	int zly_cykl = rand() % 2;
	switch(zly_cykl) {
		case 0:
			snprintf(iconstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/images/cygar1.jpg");
			break;
		case 1:
			snprintf(iconstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/images/cygar2.jpg");
			break;
		default:
			printf("coś się zjebało brachu");
	}
	NotifyNotification * status = notify_notification_new ("Status Konia", status_gaming[dobry_cykl], iconstr);
	notify_notification_show (status, NULL);
	g_object_unref(G_OBJECT(status));
	free(iconstr);
	notify_uninit();
}

//rzadki koń: szansa 1 na 100
void generate_random_notif_lucky() {
	notify_init("Status konia");
	char* iconstr = (char*)malloc(BUFFER);
	snprintf(iconstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/images/goldcygar.png");
	NotifyNotification * status = notify_notification_new ("Status Konia", "przezajekurwabisty", iconstr);
	notify_notification_show (status, NULL);
	g_object_unref(G_OBJECT(status));
	free(iconstr);
    notify_uninit();		
}

//papież: tylko o 21:37
void generate_random_notif_2137() {
	const char* status_gaming[3] = {"nie wiem", "zjadł (dali mu)", "na wakacjach w Wadowicach"};
	notify_init("Status papieża");
	int dobry_cykl = rand() % 3;
    char* iconstr = (char*)malloc(BUFFER);
	snprintf(iconstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/images/papaj.jpg");
	NotifyNotification * status = notify_notification_new ("Status Papieża", status_gaming[dobry_cykl], iconstr);
	notify_notification_show (status, NULL);
	g_object_unref(G_OBJECT(status));
	free(iconstr);
    notify_uninit();		
}