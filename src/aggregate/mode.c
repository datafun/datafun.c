/**
  Want this to obey rules of mode:

  Must haves:
  1. If there is not more than one occurance of an element, there is no mode.
  2. If there is more than one occurance and it is the highest number of frequency, then it is the mode.
  3. If more than one element satisfies (2), then they are all the mode. Ice cream anyone? hehehehe

  Nice to have:
  1. Input does not need to be sorted.
  2. Allow strings as well as numbers.

*/

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include "commander.h"
#include "datafun.h"


static double _prevNum = 0.0;

static double _currentNum = 0.0;
static uint64_t _currentCount = 0;

static uint64_t _modeCount = 0;
static double _mode = 0.0;

static bool carg_s = false;
static void on_arg_s(command_t *self) {
  carg_s = true;
}

void start(command_t* cmd) {
  df_cmd_setup(cmd, df_filename(FILE_NAME, __name));
  
  df_cmd_io(cmd);

  command_option(cmd, "-s", "--sorted", "the input is sorted, required at the moment", on_arg_s);  
}

void each_line(char* line) {
  if (!carg_s) { ERR_EXIT(100, "You did not pass the -s or --sorted flag. Input is required to be sorted at the moment."); }

  double num = atof(line);
  if (_prevNum == num) {
    _currentCount += 1;
    if (_currentCount > _)
  }  



  _prevNum = num;
}

void finish() {
 
}


