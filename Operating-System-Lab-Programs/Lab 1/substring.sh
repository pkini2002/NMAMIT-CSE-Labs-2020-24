echo "enter the string"
read str
if [-z $str ]
then
echo "invalid string entered"
else
y=`expr "$str" : '.*'`
echo "length is : $y"
if [ $y -ge 6 ]
then
z=`expr "$str" : '\(...\).*'`
echo "$z"
else
fi
fi
echo "not possible"
echo "enter the character to locate the position:"
read ch
if [-z $ch ]
then
echo "error!!!"
else
r=`expr "$str" : '[^'$ch']*'$ch`
echo "position: $r"
fi
