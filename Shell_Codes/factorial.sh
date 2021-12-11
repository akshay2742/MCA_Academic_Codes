# !/bin/sh

read n
temp=$n
result=1
while((temp!=0))
do
result=`expr $result \* $temp`
temp=`expr $temp - 1`
done

echo "Factorial of $n is $result"


