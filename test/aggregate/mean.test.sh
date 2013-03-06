#!/bin/bash

source ./test/testlib.sh

test_file_start 



test_start "mean" "" "data.txt"

OUTPUT=$(diff $RET -<<EOF
61.9340266666667
EOF)

assert_empty $OUTPUT



