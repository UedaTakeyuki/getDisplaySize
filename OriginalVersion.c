#include <gtk/gtk.h>

int
main (int    argc, char **argv){
  const gchar *command_line = "tvservice -s";
  gchar *standard_output = NULL;
  gboolean result;
  GError *error = NULL;
  gint status;

  g_print("command_line: %s\n", command_line);

  // spawn "tvservice -s" command and receive result to standard_output
  // https://palepoli.skr.jp/tips/glib/index.php
  result = g_spawn_command_line_sync (
    command_line, // const gchar* command_line,
    &standard_output, // gchar** standard_output,
    NULL, // gchar** standard_error,
    &status, // gint* wait_status,
    &error// GError** error
  );
  if (!result){
    g_print("err: %s\n", error->message);
    g_print("err: %d\n", error->code);
    g_print("status: %d\n", status);
    g_error_free (error);
    return status;
  }
  g_print("standard_output: %s\n", standard_output);

  GRegex *regex;
  GMatchInfo *match_info;

  // create regex and match it
  regex = g_regex_new ("([0-9]+)x([0-9]+)", 0, 0, NULL);
  g_regex_match (regex, standard_output, 0, &match_info);
  gchar *x = g_match_info_fetch (match_info, 1);
  g_print("x: %s\n", x);
  gchar *y = g_match_info_fetch (match_info, 2);
  g_print("y: %s\n", y);

  gint width = g_ascii_strtoll(x, NULL, 10);
  g_print("width: %d\n", width);
  gint hight = g_ascii_strtoll(y, NULL, 10);
  g_print("hight: %d\n", hight);
}