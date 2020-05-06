///Implement Radix Sort
/// MADE BY CHETAN KHANNA
#include<bits/stdc++.h>
using namespace std;

int maximum(int*a,int n)
{
    int x = a[0];

    for(int i=1; i<n; i++)
    {
        if(x<a[i])
            x=a[i];

    }

    return x;

}

void bucket_sort(int array[], int size,int place)
{
    vector<float>b[10];
    for(int i=0; i<size; i++)
    {
        b[(array[i]/place)%10].push_back(array[i]);

    }

    for(int i=0; i<10; i++)
    {
        sort(b[i].begin(),b[i].end());
    }
    int index=0;
    for(int i=0; i<10; i++)
        for(int j=0; j<b[i].size(); j++)
        {
            array[index++]=b[i][j];
        }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void radixSort(int*arr,int n)
{
    int max = maximum(arr,n);
    for(int i=1; max/i>0; i=i*10)
    {
        bucket_sort(arr,n,i);
    }
}
int main()
{
    int array[100];
    int n;
    cout<<"SIZE : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }
    radixSort(array, n);
    cout<<"\n\nSORTED ARRAY : ";
    printArray(array, n);
}


