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

#aggregate
test/aggregate/mean.test.sh
#test/aggregate/mode.test.sh
test/aggregate/sum.test.sh

#map
test/map/abs.test.sh


#reduce
test/reduce/gt.test.sh
test/reduce/gte.test.sh
test/reduce/lt.test.sh
test/reduce/lte.test.sh
test/reduce/splitlines.test.sh



#search
test/search/max.test.sh
test/search/min.test.sh


#any cleanup
test_all_done 
