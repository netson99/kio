#!/bin/sh
export LANG=C.UTF-8
export LC_ALL=C.UTF-8
openbox &
sleep 5
kdeinit5
trap "kdeinit5_shutdown" EXIT
sleep 1
dh_auto_test --no-parallel
