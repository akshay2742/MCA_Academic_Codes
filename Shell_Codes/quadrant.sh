# !/bin/sh

echo "Enter the value of x axis"
read x
echo "Enter the value of y axis"
read y

if(( $x > 0 & $y > 0 ))
then
echo "Point belongs to 1st quadrant"
elif(( $x < 0 & $y > 0 ))
then
echo "Point belongs to 2nd quadrant"
elif(( $x < 0 & $y < 0 ))
then
echo "Point belongs to 3rd quadrant"
elif(( $x > 0 & $y < 0 ))
then
echo "Point belongs to 4th quadrant"
else
echo "Point is at the center"
fi

