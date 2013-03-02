#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include "commander.h"
#include "datafun.h"

void do_action(char* line) {
  double num = atof(line);
  if (num < df_carg_n) {
    fprintf(df_carg_output, "%s\n", line);
  }
}

int main(int argc, char **argv) {
  command_t program;
  char* name = malloc(255);
  
  df_cmd_setup(&program, df_filename(FILE_NAME, name), argc, argv);
  df_cmd_io(&program);
  df_cmd_n(&program);

  command_parse(&program, argc, argv);

  df_cmd_init_defaults();

  char* line = malloc(255);
  size_t n = 0;
  ssize_t m = 0;

  do {
    m = getline(&line, &n, df_carg_input);
    strtrim(line);
    if (strlen(line) > 0) {
      do_action(line);
    }
  } while (m > 0);


  free(name);
  free(line);
  
  df_cleanup();

  command_free(&program);
}



