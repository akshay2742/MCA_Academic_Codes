# !/bin/sh

declare -a arr

read str

length=${#str}

i=0
count=0
while(($i<$length))
do
case ${str:i:1} in
	"a") arr[$count]=${str:i:1}
	     count=`expr $count + 1`;;
	"e") arr[$count]=${str:i:1}
	     count=`expr $count + 1`;;
	"i") arr[$count]=${str:i:1}
             count=`expr $count + 1`;;
	"o") arr[$count]=${str:i:1}
             count=`expr $count + 1`;;   
	"u") arr[$count]=${str:i:1}
             count=`expr $count + 1`;;
esac
i=`expr $i + 1`
done

echo ${arr[1]}




