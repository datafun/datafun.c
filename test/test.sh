#!/bin/bash

PASS=0
FAIL=0

source ./test/testlib.sh

printf "\nTesting datafun...\n"


#initailization
mkdir -p /tmp/test-datafun


##########
# TESTS
##########

#reduce
test/reduce/lt.test.sh

#aggregate
test/aggregate/mean.test.sh


#any cleanup
test_all_done 