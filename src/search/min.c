#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include "commander.h"
#include "datafun.h"

static double _min = INFINITY;
static uint64_t _minIndex = -1;
static uint64_t _count = 0;

static bool carg_x = false;
static void on_arg_x(command_t *self) {
  carg_x = true;
}

static double carg_s = 0.0;
static bool carg_s_present = false;
static void on_arg_s(command_t *self) {
  carg_s_present = true;
  carg_s = atof(self->arg);
}

void start(command_t* cmd) {
  df_cmd_setup(cmd, df_filename(FILE_NAME, __name));
  
  df_cmd_io(cmd);
  df_cmd_n(cmd);

  command_option(cmd, "-s", "--start [number]", "the start of the data, x0 [0]", on_arg_s);
  command_option(cmd, "-x", "--show-index", "show the index along with the minimum", on_arg_x);
}

void each_line(char* line) {
  double num = atof(line);
  if (num < _min) {
    _min = num;
    _minIndex = _count;
  }
  _count += 1;
}

void finish() {
  if (!carg_s_present)
    if (carg_x)
      fprintf(df_carg_output, "%llu,%f\n", _minIndex, _min); 
    else
      fprintf(df_carg_output, "%f\n", _min);  
  else
    fprintf(df_carg_output, "%f,%f\n", (_minIndex*df_carg_n) + carg_s, _min); //x0 + (delta x) * xi, ymin
}