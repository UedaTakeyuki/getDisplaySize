#include <gtk/gtk.h>
int displaysize (gint *width, gint *height);

main(){
  gint width, height, result;
  result = displaysize(&width, &height);
  g_print("width: %d\n", width);
  g_print("height: %d\n", height);
  
}
