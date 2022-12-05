#include <iostream>

using namespace std;

#define Max 100

template<class T>

class Queue
{
    T arr[Max];
    int r=-1;
    int f=0;
public:
    void enqueue()
    {
        if(r==Max-1)
        {
            cout<<"Queue is full\n";
        }
        else
        {
            T item;
            cout<<"Enter the item to be inserted:\n";
            cin>>item;
            r=r+1;
            arr[r]=item;
        }
    }

    void dequeue()
    {
        if(f>r)
        {
            cout<<"Queue is empty\n";
        }
        else
        {
            T delitem=arr[f];
            f=f+1;
            cout<<"Item deleted is:"<<delitem<<endl;
        }
    }
    void display()
    {
        if(f>r)
        {
            cout<<"Queue is empty\n";
        }
        cout<<"Elements in queue are:\n";
        for(int i=f;i<=r;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void operation()
    {
        int choice;
        while(1)
        {
            cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice\n";
            cin>>choice;
            switch(choice)
            {
                case 1:enqueue();
                       break;
                case 2:dequeue();
                       break;
                case 3:display();
                       break;
                case 4:exit(0);
                default:cout<<"Incorrect choice!\n";
            }
        }
    }
};

int main()
{
    Queue<int>q1;
    Queue<float>q2;
    while(1)
    {
        cout<<"Enter the data type whose operations are to be performed:\n";
        cout<<"1.Integer\n2.Float\n3.Exit\n";
        int ch;
        cout<<"Enter your choice:\n";
        cin>>ch;
        switch(ch)
        {
            case 1:q1.operation();
                   break;
            case 2:q2.operation();
                   break;
            case 3:exit(0);
            default:cout<<"Incorrect choice!\n";
        }
    }
    return 0;
}
