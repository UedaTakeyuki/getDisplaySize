getDisplaySize: main.c displaysize.o
	gcc -g `pkg-config --cflags --libs gtk+-3.0` -o getDisplaySize main.c displaysize.o

displaysize.o: displaysize.c
	gcc -c `pkg-config --cflags --libs gtk+-3.0` displaysize.c
