#include <iostream>

using namespace std;

template<class T>

void bsort(T arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                T temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    cout<<"Integer array sort\n";
    int ia[30],n;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    cout<<"Enter array elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>ia[i];
    }
    cout<<"Array elements before sorting:\n";
    for(int i=0;i<n;i++)
    {
        cout<<ia[i]<<" ";
    }
    cout<<endl;
    bsort(ia,n);
    cout<<"Array elements after sorting\n";
    for(int i=0;i<n;i++)
    {
        cout<<ia[i]<<" ";
    }
    cout<<endl;
    cout<<"Floating array sort\n";
    float fa[30];
    cout<<"Enter the number of elements:\n";
    cin>>n;
    cout<<"Enter array elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>fa[i];
    }
    cout<<"Array elements before sorting:\n";
    for(int i=0;i<n;i++)
    {
        cout<<fa[i]<<" ";
    }
    cout<<endl;
    bsort(fa,n);
    cout<<"Array elements after sorting\n";
    for(int i=0;i<n;i++)
    {
        cout<<fa[i]<<" ";
    }
    cout<<endl;

    return 0;
}
