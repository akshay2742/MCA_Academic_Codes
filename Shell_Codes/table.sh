# !/bin/sh

echo "Enter the Number"
read n

for((i=1;i<=10;i++))
do
echo "$n * $i =  `expr $n \* $i`"
done
