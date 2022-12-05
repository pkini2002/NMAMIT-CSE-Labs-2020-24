#Write a shell script that accepts filenames as arguments and for every files, it should check whether it exists in the current directory and if exists convert 
# its name to uppercase and only if there is no file exists with new name.

for file in "$@"
do
        if [ -f $file ]
        then
                Ufile=`echo $file | tr '[a-z]' '[A-Z]'`
                if [ -f $Ufile ]
                then
                        echo "$Ufile already exists!"
                else
                        mv $file $Ufile
                fi
        else
                echo "$file does not exist!"
        fi
done
