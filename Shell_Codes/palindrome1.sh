# !/bin/sh

read str1

length=${#str1}

str2=$(echo $str1 | rev)

if [ $str1 = $str2 ]
then
echo "String is a palindrome"
else
echo "String is not a palindrome"
fi
