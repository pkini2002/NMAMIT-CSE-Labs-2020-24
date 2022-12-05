# Write a shell program to check the year is the leap year ornot. Displayappropriatemessage.

echo "Enter the year: "
read year
x=`expr $year % 100`
y=`expr $year % 4`
z=`expr $year % 400`

if [ $y -eq 0 ] && [ $x -ne 0 ] || [ $z -eq 0 ]
then
        echo "$year is a leap year"
else
        echo "$year is not a leap year"
fi
