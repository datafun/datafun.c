#!/bin/bash

source ./test/testlib.sh

test_file_start 


BIN=splitlines
ARGS="-l 3 /tmp/test-datafun/sl_chunks.txt"

OUT_FILE=/tmp/test-datafun/$BIN.test.out
  
printf "    $BIN $ARGS ... "
  
$(pwd)/bin/$BIN -i $(pwd)/test/resources/$INPUT -o $OUT_FILE -l 3 /tmp/test-datafun/sl_chunks.txt #> $OUT_FILE
status=$?
if [ $status -ne 0 ]; then
  echo "FAILED" > $OUT_FILE
fi

OUTPUT=$(diff $OUT_FILE -<<EOF
/tmp/test-datafun/0-sl_chunks.txt
/tmp/test-datafun/1-sl_chunks.txt
/tmp/test-datafun/2-sl_chunks.txt
EOF)

assert_empty $OUTPUT




