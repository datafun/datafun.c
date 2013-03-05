#!/bin/bash

source ./test/testlib.sh

test_file_start 



test_start "mode" "" "data.txt"

OUTPUT=$(diff $RET -<<EOF
45.000000
EOF)

assert_empty $OUTPUT

