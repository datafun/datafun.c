#include "commander.h"
#include "datafun.h"

static double _sum = 0.0;

void start(command_t* cmd) {
  df_cmd_setup(cmd, df_filename(FILE_NAME, __name));
  
  df_cmd_io(cmd);
}

void each_line(char* line) {
  _sum += atof(line);
}

void finish() {
  fprintf(df_carg_output, "%.15g\n", _sum);  
}
