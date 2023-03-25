#include <gtk/gtk.h>
#include "displaysize.h"

int main(){
  gint width, height, result;
  result = displaysize(&width, &height);
  g_print("width: %d\n", width);
  g_print("height: %d\n", height);
  return 0;
}
