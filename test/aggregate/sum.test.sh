#!/bin/bash

source ./test/testlib.sh

test_file_start 



test_start "sum" "" "data.txt"

OUTPUT=$(diff $RET -<<EOF
557.40624
EOF)

assert_empty $OUTPUT



