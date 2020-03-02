#!/bin/sh

# $> sh run.sh			-> 0..100
# $> sh run.sh 10		-> 0..10
# $> sh run.sh -4 32	-> -4..32

MIN="1";
MAX="100";
TMPFILE="/tmp/push_swap.res";

case $# in 	# $# -> argc
	1) MAX="$1"; ;;
	2) MIN="$1"; MAX="$2"; ;; 
esac

ARG="$(ruby -e "puts ($MIN..$MAX).to_a.shuffle.join(' ')")";
./push_swap $ARG | ./checker $ARG
echo "Lines:";
./push_swap $ARG | wc -l
echo "$ARG" > tmp;