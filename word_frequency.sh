#!/bin/bash
cat words.txt| tr -cs 'a-z' '\n' | sort | uniq -c | sort -r -n | awk '{print $2, $1}' 
