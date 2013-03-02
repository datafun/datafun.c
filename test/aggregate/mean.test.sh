#!/bin/bash

source ./test/testlib.sh

test_file_start 



test_start "mean"

OUT_FILE=/tmp/test-datafun/mean.test.out

$(pwd)/bin/mean -i $(pwd)/test/resources/data.txt -o $OUT_FILE

OUTPUT=$(diff $OUT_FILE -<<EOF
64.050780
EOF)

test_empty $OUTPUT



