cat words.txt | sed 's/ /\n/g' | sed '/^$/d' | sort | uniq -c | awk '{print $2, $1}' | sort -nrk2
