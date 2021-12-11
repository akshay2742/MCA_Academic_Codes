# !/bin/sh

echo "Enter the number"
read n

result=0

i=2
a=0
b=1
echo "The Fibonacci series is"
echo $a
echo $b
while((i<n))
do
c=`expr $a + $b`
echo $c
a=$b
b=$c
i=`expr $i + 1`
done

