#include "commander.h"
#include "datafun.h"
#include "hash.h"

static hash_t* hash = NULL;

int dhash_has(hash_t *self, char *key) {
  khiter_t k = kh_get(ptr, self, key);
  printf("%d\n", k);
  return kh_exist(self, k);
}

void start(command_t* cmd) {
  df_cmd_setup(cmd, df_filename(FILE_NAME, __name));
  
  df_cmd_io(cmd);

  hash = hash_new();
}

void each_line(char* line) {
  double num = atof(line);
  char* buf = malloc(strlen(line));
  sprintf(buf, "%f", num);

  int* val = NULL;
  printf("EACH: %s\n", buf);
  int d = dhash_has(hash, buf);
  printf("HAS: %d\n", d);
  if (hash_has(hash, buf)) {
    puts("has");
    val = (int*)hash_get(hash, buf);
    *val += 1;
  } else {
    puts("doe nost");
    val = malloc(4);
    *val = 5;
  }

  printf("%d\n", *val);
  hash_set(hash, buf, val);
}

void finish() {
  /*for (khiter_t k = kh_begin(hash); k < kh_end(hash); ++k) {
    if (!kh_exist(hash, k)) continue;
    const char* key = kh_key(hash, k); 
    int* val = (int*)kh_value(hash, k);
    
    printf("%s: %d\n", key, *val);
  }*/

  hash_free(hash);
}


