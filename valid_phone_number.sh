# MUST use Extended Regex-expression 
grep  -Eo '^((\([0-9]{3}\)\s)|([0-9]{3}-))([0-9]{3}[-][0-9]{4})$' file.txt
