# !/bin/sh

echo "Enter the base"
read base
echo "Enter the power"
read power

result=1

for((i=1;i<=power;i++))
do
result=`expr $result \* $base`
done

echo "Answer is: $result"
