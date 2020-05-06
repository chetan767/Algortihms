///Implement Heap Sort(The program should report the number of comparisons)
/// MADE BY CHETAN KHANNA
#include <bits/stdc++.h>
using namespace std;

int count_max=0,count_min=0;

void max_heapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        count_max++;
        if (j < n && a[j+1] > a[j])
            j = j+1;

        if (temp > a[j])
            break;

        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}

void heapsort_max(int a[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
    cout<<"\n\nComparisons = "<<count_max<<endl;
}

void min_heapify(int a[],int i,int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        count_min++;
        if (j < n && a[j+1] < a[j])
            j = j + 1;

        if (temp < a[j])
            break;

        else if (temp >= a[j])
        {
            a[j/2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}

void build_minheap(int a[], int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        min_heapify(a,i,n);
    }
}

void heapsort_min(int a[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        min_heapify(a, 1, i - 1);
    }
    cout<<"\n\nComparisons = "<<count_min<<endl;
}

void build_maxheap(int a[], int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}

int main()
{
    int n, i, x, ch;
    do
    {
        cout<<"SIZE : ";
        cin>>n;

        int a[20];
        for (i = 1; i <=n; i++)
        {
            cin>>a[i];
        }

        cout<<"\n1.MAX HEAP\n2.MIN HEAP\n"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            build_maxheap(a,n);
            cout<<"\nMAXHEAP : ";
            for (i = 1; i <= n; i++)
            {
                cout<<a[i]<<" ";
            }
            heapsort_max(a, n);
            cout<<"\nSORTED HEAP : ";
            for (i = n; i >= 1; i--)
            {
                cout<<a[i]<<" ";
            }
            exit(0);

        case 2:
            build_minheap(a,n);
            cout<<"\nMINHEAP : ";
            for (i = 1; i <= n; i++)
            {
                cout<<a[i]<<" ";
            }
            heapsort_min(a, n);
            cout<<"\nSORTED HEAP : ";
            for (i = n; i >= 1; i--)
            {
                cout<<a[i]<<" ";
            }
            exit(0);
        }
    }
    while(ch>0&&ch<3);
    return 0;
}
