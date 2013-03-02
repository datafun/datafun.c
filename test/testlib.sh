COLOR_CYAN="\x1B[36m"
COLOR_RED="\x1B[31m"
COLOR_GREEN="\x1B[32m"
COLOR_NORMAL="\x1B[39m"

function test_file_start() {
	printf "  ${COLOR_CYAN}$(basename $0)${COLOR_NORMAL}\n"
}

function test_start() {
	printf "    $1 ... "
}

function test_empty() {
	if [ -z "$1" ]
	then
		printf "${COLOR_GREEN}passed${COLOR_NORMAL}\n"
		#PASS=$((PASS+1))
	else
		printf "${COLOR_RED}failed${COLOR_NORMAL}\n"
		printf "$1\n"
		#FAIL=`expr $FAIL + 1`
	fi
}

function test_all_done() {
	printf "\nFinished.\n" # $PASS passed, $FAIL failed\n"
}

