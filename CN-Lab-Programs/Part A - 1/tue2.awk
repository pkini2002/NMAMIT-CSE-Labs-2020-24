BEGIN{
count=0;
}
{
if($1=="d")
{
    count++;
    printf("%s\t%s\n",$5,$11)
}
}
END{printf("The number of packets dropped is %d\n",count);}

