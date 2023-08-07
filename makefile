all:
	gcc -o status_konia -O3 `pkg-config --cflags --libs libnotify glib-2.0 gdk-pixbuf-2.0 sdl2 SDL2_mixer` main.c
