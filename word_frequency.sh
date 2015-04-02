#!/bin/bash
# tr -cs 'a-z' '\n'
# 将文件每行所有不包含在[a-z]（所有希腊字母）的字符串放在字符串1中并转换为一新行。
# -s选项表明压缩所有新行， -c表明保留所有字母不动
cat words.txt| tr -cs 'a-z' '\n' | sort | uniq -c | sort -r -n | awk '{print $2, $1}' 
