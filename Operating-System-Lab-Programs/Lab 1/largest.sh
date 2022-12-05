# Write a shell program to find and display largest and smallest of threenumbers.

echo "Enter the first number"
read a
echo "Enter the second number"
read b
echo "Enter the third number"
read c

if [ $a -gt $b ] && [ $a -gt $c ]
then
        echo "$a is greatest"
elif [ $b -gt $c ] && [ $b -gt $a ]
then
        echo "$b is greatest"
else
        echo "$c is greatest"

fi

if [ $a -lt $b ] && [ $a -lt $c ]
then
        echo "$a is smallest"
elif [ $b -lt $c ] && [ $b -lt $a ]
then
        echo "$b is smallest"
else
        echo "$c is smallest"
fi
