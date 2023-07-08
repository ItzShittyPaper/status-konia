#include "libnotify/notify.h"
#include "gdk-pixbuf/gdk-pixbuf.h"
#include "unistd.h"
#include "stdlib.h"

#define BUFFER 1024

const char* status_gaming[8] = {"status konia", "Flak", "nie żyje", "zajebisty",  "stoi petarda", "zwalony", "dzień udany robimy", "dobry koń"};

int main() {

	for( ; ; ) {

		notify_init ("Status Konia");
		srand(time(NULL));
		int dobry_cykl = rand() % 8;
		char* iconstr = (char*)malloc(BUFFER);
		snprintf(iconstr, BUFFER, "%s%s", getcwd(NULL, BUFFER), "/courage.jpg");
		NotifyNotification * status = notify_notification_new ("Status Konia", status_gaming[dobry_cykl], iconstr);
		notify_notification_show (status, NULL);
		g_object_unref(G_OBJECT(status));
		free(iconstr);
		notify_uninit();

		sleep(10 * 60);
	}

	return 0;
}
