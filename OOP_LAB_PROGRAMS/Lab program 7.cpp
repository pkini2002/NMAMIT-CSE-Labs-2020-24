#include <iostream>
#include<cstring>

using namespace std;

class String
{
    char *str;
    int length;
public:
    String()
    {
        length=0;
        str=new char[length+1];
    }
    String(char *s)
    {
        length=strlen(s);
        str=new char[length+1];
        str=s;
    }
    void join(String s1,String s2)
    {
        length=s1.length+s2.length;
        str=new char[length+1];
        str=strcpy(str,s1.str);
        str=strcat(str,s2.str);
        cout<<"The string after concatenation is:"<<str<<endl;
    }
    void display()
    {
        cout<<"The entered string is:"<<str<<endl;
    }
};

int main()
{
    char str1[20];
    char str2[20];
    cout<<"Enter the first string:\n";
    cin>>str1;
    cout<<"Enter the second string:\n";
    cin>>str2;
    String s1(str1);
    s1.display();
    String s2(str2);
    s2.display();
    String s3;
    s3.join(s1,s2);
    return 0;
}
