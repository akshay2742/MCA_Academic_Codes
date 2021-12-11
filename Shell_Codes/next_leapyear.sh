# !/bin/sh

read n

count=0
while(($count==0))
do
n=`expr $n + 1`
if(($n%400==0))
then
count=1
elif(($n%100==0))
then
count=0
elif(($n%4==0))
then
count=1
else
count=0
fi
done

echo "Next leap year is $n"
