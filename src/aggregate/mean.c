#include "commander.h"
#include "datafun.h"

static double _sum = 0.0;
static double _count = 0.0;

void start(int argc, char** argv, command_t* cmd) {
  df_cmd_setup(cmd, df_filename(FILE_NAME, __name));
  
  df_cmd_io(cmd);
}

void each_line(char* line) {
  double num = atof(line);
  _sum += num;
  _count += 1;
}

void finish() {
  fprintf(df_carg_output, "%.15g\n", (_sum / _count));  
}


