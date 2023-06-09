#include <gtk/gtk.h>

int
displaysize (gint *width, gint *height){

  // call "tvservice -s" to get a string of width and height
  // https://howchoo.com/pi/raspberry-pi-display-resolution-lookup
  // https://forums.raspberrypi.com/viewtopic.php?t=19817
//  const gchar *command_line = "fbset -s";
  const gchar *command_line = "cat /sys/class/graphics/fb0/virtual_size";
  gchar *standard_output = NULL;
  gboolean result;
  GError *error = NULL;
  gint status;

  // spawn "tvservice -s" command and receive result to standard_output
  // https://palepoli.skr.jp/tips/glib/index.php
  result = g_spawn_command_line_sync (
    command_line, // const gchar* command_line,
    &standard_output, // gchar** standard_output,
    NULL, // gchar** standard_error,
    &status, // gint* wait_status,
    &error// GError** error
  );
  if (!result){ // error handling
    g_print("err: %s\n", error->message);
    g_print("err: %d\n", error->code);
    g_print("status: %d\n", status);
    g_error_free (error);
    return status;
  }
//  g_print("standard_output: %s\n",standard_output);

  gchar **xy = g_strsplit (
    standard_output,
    ",",
    0
  );
//  g_print("x: %s\n", xy[0]);
//  g_print("y: %s\n", xy[1]);
  *width = g_ascii_strtoll(xy[0], NULL, 10);
  *height = g_ascii_strtoll(xy[1], NULL, 10);
  g_free(standard_output);
  g_free(xy);

/*
  // parse width and height string
  GRegex *regex;
  GMatchInfo *match_info;

//  regex = g_regex_new ("geometry ([0-9]+) ([0-9]+)", 0, 0, &error);
//  regex = g_regex_new ("([0-9]+)x([0-9]+)", 0, 0, &error);
  regex = g_regex_new ("([0-9]+),([0-9]+)", 0, 0, &error);
  if (!result){ // error handling
    g_print("err: %s\n", error->message);
    g_print("err: %d\n", error->code);
    g_error_free (error);
    return error->code;
  }

  g_regex_match (regex, standard_output, 0, &match_info);
  g_free(standard_output);
  
  // whether the previous match operation succeeded
  if (g_match_info_matches (match_info)){
    gchar *zero = g_match_info_fetch (match_info, 0);
    g_print("match: %s\n", zero);
    gchar *x = g_match_info_fetch (match_info, 1);
    gchar *y = g_match_info_fetch (match_info, 2);
  //  g_print("x: %s\n", x);
  //  g_print("y: %s\n", y);

    *width = g_ascii_strtoll(x, NULL, 10);
    *height = g_ascii_strtoll(y, NULL, 10);

  //  g_print("width: %d\n", *width);
  //  g_print("hight: %d\n", *height);

    return 0;
  } else {
    return 1;
  }*/
  return 0;
}