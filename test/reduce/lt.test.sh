#!/bin/bash

source ./test/testlib.sh

filename=$(basename "$fullfile")
extension="${filename##*.}"
filename="${filename%.*}"

test_file_start 



test_start "lt -n -6"

OUT_FILE=/tmp/test-datafun/lt.test.out

$(pwd)/bin/lt -i $(pwd)/test/resources/data.txt -o $OUT_FILE -n -6

OUTPUT=$(diff $OUT_FILE -<<EOF
-10000.34
EOF)

test_empty $OUTPUT



test_start "lt -n 2"

OUT_FILE=/tmp/test-datafun/lt.test.out

$(pwd)/bin/lt -i $(pwd)/test/resources/data.txt -o $OUT_FILE -n 2

OUTPUT=$(diff $OUT_FILE -<<EOF
-10000.34
0.42424
-5.678
EOF)

test_empty $OUTPUT



test_start "lt -n 23.43"

OUT_FILE=/tmp/test-datafun/lt.test.out

$(pwd)/bin/lt -i $(pwd)/test/resources/data.txt -o $OUT_FILE -n 23.43

OUTPUT=$(diff $OUT_FILE -<<EOF
23.0
-10000.34
0.42424
2
-5.678
6
EOF)

test_empty $OUTPUT




