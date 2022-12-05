# Write a shell program to check the number n is divisible by m ornot Where m and n are supplied as command line argument or read from keyboard interactively.

echo "Enter the value of n: "
read n
echo "Enter the value of m: "
read m
y=`expr $n % $m`
if [ $y -eq 0 ]
then
        echo "$n is divisible by $m"
else
        echo "$n is not divisible by $m"
fi
