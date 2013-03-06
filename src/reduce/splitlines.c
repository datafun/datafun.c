#include "commander.h"
#include "datafun.h"

static long _lineCount = 0;
static long _fileCount = 0;
static FILE* _currentFd = NULL;
static char* _currentFile = NULL;
static char* _dirPart = NULL;
static char* _filePart = NULL;

void open_file();

static long carg_line = 1000;
static void on_arg_line(command_t *self) {
  carg_line = atol(self->arg);
}

void start(int argc, char** argv, command_t* cmd) {
  df_cmd_setup(cmd, df_filename(FILE_NAME, __name));

  //command_option(cmd, "-i", "--input <path>", "specify input file [stdin]", on_arg_input);
  df_cmd_io(cmd);

  command_option(cmd, "-l", "--lines <number>", "number of lines to split file by [1000]", on_arg_line);
  cmd->usage = "[options] postfix";

  _dirPart = argv[argc - 1];
  _filePart = strrchr(_dirPart, '/');
  if (_filePart) {
    *_filePart = 0; //split dir and file part
    _filePart += 1; //set file part
  } else { //there is no directory part input
    _filePart = _dirPart;
    _dirPart = NULL;
  }

  open_file();
}

void each_line(char* line) {
  fprintf(_currentFd, "%s\n", line);
  
  _lineCount += 1;
  if (_lineCount == carg_line) {
    _lineCount = 0;
    _fileCount += 1;

    fclose(_currentFd);
    fprintf(df_carg_output, "%s\n", _currentFile); //for xargs to start processing
    free(_currentFile);
    open_file();
  }
}

void finish() {

}


void open_file() {
  if (_dirPart)
    asprintf(&_currentFile, "%s/%ld-%s", _dirPart, _fileCount, _filePart);
  else
    asprintf(&_currentFile, "%ld-%s", _fileCount, _filePart);

  _currentFd = fopen(_currentFile, "w");
}
