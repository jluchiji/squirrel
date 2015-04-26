#!/bin/bash

ARENA="arena1"
SELF="./squirrel"

function count_proc() {
	echo $(ps -u $ARENA | grep $(basename $1) | grep -v defu | wc -l)
}

pkill -KILL -u $ARENA
sleep 2

su $ARENA -c "./arena 10 $SELF $*"
sleep 10

printf "\e[4;1;31m          PROCESS LIST           \e[0m\n"
ps -u $ARENA

printf "\e[4;1;31m          BATTLE REPORT          \e[0m\n"


printf "%-27s%s\n" "$SELF" $(count_proc $SELF)
for prog in $@; do
	printf "%-27s%s\n" "$prog" $(count_proc $prog)
done
pkill -KILL -u $ARENA