print "Enter the input string: \n";
$a= <STDIN>;
print "Enter total number of times the string has to be displayed: \n";
chop($b=<STDIN>);
$c=$a x $b;
print "Result is: \n$c\n";
