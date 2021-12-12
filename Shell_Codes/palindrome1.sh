# !/bin/sh

count=0

arguments=$(echo $#)

i=1
while(($i<=$arguments))
do
	str=$(echo ${!i} | rev)
	if [ ${!i} = $str ]
	then
		count=`expr $count + 1`
	fi
	i=`expr $i + 1`
done

echo "Number of palindromes present in the arguments are: $count"
