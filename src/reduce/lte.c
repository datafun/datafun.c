#include "commander.h"
#include "datafun.h"

void start(command_t* cmd) {
  df_cmd_setup(cmd, df_filename(FILE_NAME, __name));

  df_cmd_io(cmd);
  df_cmd_n(cmd);
}

void each_line(char* line) {
  double num = atof(line);
  if (num <= df_carg_n) {
    fprintf(df_carg_output, "%s\n", line);
  }
}

void finish() {

}

