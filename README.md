# getDisplaySize
library to get displaysize of the RaspberryPi

## How to use

make **display.o**
```
git clone https://github.com/UedaTakeyuki/getDisplaySize.git
cd getDisplaySize
make
```

then use **display.o** on your app as follo:

```
#include <gtk/gtk.h>
int displaysize (gint *width, gint *height);

main(){
  gint width, height, result;
  result = displaysize(&width, &height);
}
```

build it as follows:
```
gcc -g `pkg-config --cflags --libs gtk+-3.0` -o getDisplaySize main.c displaysize.o

```

You can refer running [main.c](https://github.com/UedaTakeyuki/getDisplaySize/blob/main/main.c) and [Makefile](https://github.com/UedaTakeyuki/getDisplaySize/blob/main/Makefile).

## References

-[Commands to get RPi display size](wiki/commands-to-get-RPi-display-size)
