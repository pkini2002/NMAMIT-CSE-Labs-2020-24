# 5.Write a shell program to display the length of the name and also display first three characters and last three characters in the name in two different lines
# if the name contains at least 6 characters

echo "Enter your name:"
read name
if [ -z "$name" ]
then
        echo "NULL"
else
        z=`expr "$name" : '.*' `
        echo "Length of string is:$z"
        if [ $z -ge 6 ]
        then
                echo "First 3 chars of name is:"
                m=`expr "$name" : '\(...\).*'`
                echo "$m"
                echo "Last 3 chars of name is:"
                n=`expr "$name" : '.*\(...\)'`
                echo "$n"
        fi
fi
