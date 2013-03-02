#include "commander.h"
#include "datafun.h"

void init_commands(command_t* cmd) {
  df_cmd_io(cmd);
  df_cmd_n(cmd);
}

void each_line(char* line) {
  double num = atof(line);
  if (num < df_carg_n) {
    fprintf(df_carg_output, "%s\n", line);
  }
}

void result() {
  
}

