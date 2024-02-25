#!/bin/sh
head -n 1 data.csv >input.txt | sort -R data.csv | head -n 10 >> input.txt
sed -i "s/,/|/g" input.txt
cat input.txt
