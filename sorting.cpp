///i. Implement Insertion Sort (The program should report the number of comparisons)
///ii. Implement Merge Sort(The program should report the number of comparisons
/// MADE BY CHETAN KHANNA

#include<iostream>
using namespace std;

int count=0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void merge(int a[], int l, int mid, int h);

void mergeSort(int a[], int l, int h)
{
    if(l<h)
    {
        int mid = l + (h-l)/2;

        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);

        merge(a,l,mid,h);
    }
}

void merge(int a[], int l, int mid, int h)
{
    int i = l;
    int j = mid+1;
    int k = l;
    int n = sizeof(a)/sizeof(a[0]);
    int temp[n];

    while(i <= mid && j <= h)
    {
        count++;
        if(a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= h)
        temp[k++] = a[j++];

    for(i=l; i<=h; i++)
        a[i]=temp[i];
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            count++;
            swap(&arr[j + 1],&arr[j]);
            j = j - 1;
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[100];
    int n,ch;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    do
    {
        cout<<"\n\n1.INSERTION SORT\n2.MERGE SORT\n\n";
        cout<<"\nCHOICE : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            insertionSort(arr,n);
            printArray(arr,n);
            cout<<"\nCOMPARISONS : "<<count+1;
            exit(0);
        case 2:
            mergeSort(arr,0,n-1);
            printArray(arr,n);
            cout<<"\nCOMPARISONS : "<<count+1;
            exit(0);
        case 3:
            exit(0);

        }

    }while(ch<6&&ch>0);
}
