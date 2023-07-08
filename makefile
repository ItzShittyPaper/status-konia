all:
	gcc -o status_konia -O3 `pkg-config --cflags --libs libnotify gdk-pixbuf-2.0` main.c
