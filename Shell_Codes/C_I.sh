# !/bin/sh

echo -n "Enter the principal: "
read principal
echo -n "Enter the rate: "
read rate
echo -n "Enter the year: "
read year

temp1=$(echo "scale=4; 1 + $rate / 100" | bc)

temp2=$(echo "scale=5; $temp1 ^ $year" | bc)

amount=$(echo "scale=5; $principal * $temp2" | bc)

echo -n "Compound Interest is: "
echo "scale=5; $amount - $principal" | bc

