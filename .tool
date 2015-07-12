#!/bin/bash

ls -al | grep .dat
echo -n "total"
ls -al | grep .dat |wc -l

echo
echo
echo "SHOW .name.lst"
cat .name.lst 
cat .name.lst | wc -l 
