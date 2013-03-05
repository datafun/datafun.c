#!/bin/bash

PASS=0
FAIL=0

source ./test/testlib.sh

printf "\nTesting datafun...\n"


#initailization
rm -rf /tmp/test-datafun
mkdir -p /tmp/test-datafun


##########
# TESTS
##########

#reduce
test/reduce/lt.test.sh
test/reduce/gt.test.sh

#aggregate
test/aggregate/mean.test.sh
#test/aggregate/mode.test.sh

#search
test/search/max.test.sh


#any cleanup
test_all_done 