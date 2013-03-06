#include "commander.h"
#include "datafun.h"

void start(int argc, char** argv, command_t* cmd) {
  df_cmd_setup(cmd, df_filename(FILE_NAME, __name));
  
  df_cmd_io(cmd);
}

void each_line(char* line) {
  if (line[0] == '-')
    fprintf(df_carg_output, "%s\n", (line+1));  
  else
    fprintf(df_carg_output, "%s\n", line);
}

void finish() {
  
}
