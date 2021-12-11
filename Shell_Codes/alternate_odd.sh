# !/bin/sh

read n

echo "Odd numbers till n are"

i=1
while((i<=n))
do 
echo $i
i=`expr $i + 2`
done


j=1
sum=0
while((j<=n))
do
sum=`expr $sum + $j`
j=`expr $j + 4`
done

echo "Alternate sum of odd numbers till n is $sum"
