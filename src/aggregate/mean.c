#include "commander.h"
#include "datafun.h"

static double _sum = 0.0;
static double _count = 0.0;

void init_commands(command_t* cmd) {
  df_cmd_io(cmd);
}

void each_line(char* line) {
  double num = atof(line);
  _sum += num;
  _count += 1;
}

void result() {
  fprintf(df_carg_output, "%f\n", (_sum / _count));  
}


