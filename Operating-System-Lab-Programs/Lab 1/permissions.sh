# Write a shell program that takes two file names ,checks the permission for these files are identical and if they are identical ,output
# the common permissions; otherwise output each file name followed by its permissions

echo "Enter the 2 file names: "
read f1 f2
if [ -e $f1 -a -e $f2 ]
then
        p1=`ls -l $f1 | cut -c 2-10`
        p2=`ls -l $f2 | cut -c 2-10`
        echo "$f1:$p1"
        echo "$f2:$p2"
        if [ "$p1"="$p2" ]
        then
                echo "$f1 and $f2 have same permissions"
                echo "The permission is $p1"
        else
                echo "$f1 and $f2 have different permissions"
                echo "The permission of $f1 is $p1"
                echo "The permission of $f2 is $p2"
        fi
else
        echo "Invalid filenames!"
fi
