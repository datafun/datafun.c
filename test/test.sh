#!/bin/bash

PASS=0
FAIL=0

source ./test/testlib.sh

printf "\nTesting datafun...\n"


#initailization
mkdir -p /tmp/test-datafun


#actual tests
test/reduce/lt.test.sh


#any cleanup
test_all_done 