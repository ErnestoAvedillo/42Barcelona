cat /etc/passwd | awk -F ":" '{print $1}' | grep -v -E '^(#)'|awk 'NR<='$FT_LINE2'&& NR>='$FT_LINE1|rev | sort | tr '\n' ','| sed 's/,$//'|tr '\n' '.'
