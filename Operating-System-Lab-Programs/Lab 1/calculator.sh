#Write a shell program to implement simple calculator operations.

echo "Enter 2 operands and the operator: "
read a
read b
read op

case $op in
        '+') res=`expr $a + $b `
                echo "Sum is $res";;

        '-') res=`expr $a - $b `
                 echo "Difference is $res";;

        '*') res=`expr $a \* $b `
                  echo "Product is $res";;

        '/') if [ $b -eq 0 ]
        then
                echo "Division is not possible"
        else
                res=`expr $a / $b `
                echo "Quotient = $res"
        fi
        ;;

        '%') res=`expr $a % $b `
                echo "Result is $res";;

        *) echo "Invalid Option";;
esac
