# !/bin/sh

echo "Enter the starting value"
read start

echo "Enter the ending value"
read end

count=0
i=$start
echo "Prime numbers ranging from $start to $end are"
while((i<=end))
do
	j=2
	while((j<i))
	do
		if((i%j!=0))
		then
			count=0
		else
			count=1
			break
		fi
		j=`expr $j + 1`
	done
	if(($count==0))
	then
		echo $i
	fi
	i=`expr $i + 1`
done
