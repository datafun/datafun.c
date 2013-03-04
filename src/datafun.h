#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include <errno.h>


/***************
 * MACROS
 ****************/


#define ERR_EXIT(code, ...) fprintf(stderr, __VA_ARGS__); exit(code)

#define FILE_NAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define VERSION "0.0.0"


/****************
 * CLI PARAMS
 ****************/

char** ARGV = NULL;
int ARGC = 0;

static FILE* df_carg_input = NULL;
static void on_arg_input(command_t *self) {
  FILE* fp = fopen(self->arg, "r");
  if (!fp) {
    if (errno == ENOENT) { 
      ERR_EXIT(errno, "The file %s does not exist.", self->arg); 
    } else {
      ERR_EXIT(errno, "Error opening file: %d", errno);
    }
  }
  df_carg_input = fp;
}

static FILE* df_carg_output = NULL;
static void on_arg_output(command_t *self) {
  FILE* fp = fopen(self->arg, "w");
  if (!fp) {
    ERR_EXIT(errno, "Error opening file for writing: %d", errno);
  }
  df_carg_output = fp;
}

static double df_carg_n = 0.0;
static void on_arg_n(command_t *self) {
  for (int i = 0; i < ARGC; ++i) { //fix for commander.c not being able to handle negative numbers
    if (strcmp(ARGV[i], "-n") == 0) {
      self->arg = ARGV[i + 1];
      break;
    }
  }

  if (!self->arg) {
    for (int i = 0; i < ARGC; ++i) { //fix for commander.c not being able to handle negative numbers
      if (strcmp(ARGV[i], "--number") == 0) {
        self->arg = ARGV[i + 1];
        break;
      }
    }
  }

  if (self->arg) {
    df_carg_n = atof(self->arg);
  } else {
    ERR_EXIT(102, "You specified a number flag via '-n' or '--number' but with no argument.");
  }
}

// 

//http://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
char* strtrim(char *str) {
  char *end;

  // Trim leading space
  while(isspace(*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}


/****************
 * DATA FUN
 ****************/


void df_cleanup() {
  fclose(df_carg_input);
  fclose(df_carg_output);
}

char* df_filename(char* name, char* buf){
  strcpy(buf, name);
  buf[strlen(buf) - 2] = 0;
  return buf;
}

void df_cmd_setup(command_t* cmd, char* name, int argc, char **argv) {
  command_init(cmd, name, VERSION);
  cmd->usage = "[options] <command>";
  ARGC = argc;
  ARGV = argv;
}

void df_cmd_io(command_t* cmd) {
  command_option(cmd, "-i", "--input <path>", "specify input file [stdin]", on_arg_input);
  command_option(cmd, "-o", "--output <path>", "specify output file [stdout]", on_arg_output);
}

void df_cmd_n(command_t* cmd) {
  command_option(cmd, "-n", "--number [number]", "specify the number [0]", on_arg_n);
}

void df_cmd_init_defaults() {
  if (!df_carg_input) df_carg_input = stdin;
  if (!df_carg_output) df_carg_output = stdout;
  if (!df_carg_n) df_carg_n = 0.0;
}

void df_cmd_reduce(command_t* cmd) {

}

/****************
 * INTERFACE
 ****************/

void each_line(char* line);

void start(command_t* cmd);

void finish();

int main(int argc, char **argv) {
  command_t program;
  char* name = malloc(255);
  
  df_cmd_setup(&program, df_filename(FILE_NAME, name), argc, argv);

  start(&program);

  command_parse(&program, argc, argv);

  df_cmd_init_defaults();

  char* line = malloc(255);
  size_t n = 0;
  ssize_t m = 0;

  do {
    m = getline(&line, &n, df_carg_input);
    strtrim(line);
    if (strlen(line) > 0) {
      each_line(line);
    }
  } while (m > 0);

  finish();

  free(name);
  free(line);
  
  df_cleanup();

  command_free(&program);
}











