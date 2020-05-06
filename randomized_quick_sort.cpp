///Implement Heap Sort(The program should report the number of comparisons)
/// MADE BY CHETAN KHANNA
#include<bits/stdc++.h>
#include<ctime>
#include<cstdlib>
using namespace std;

int c=0;

void shuffle(int *a,int s,int e){

    srand(time(NULL));

    int i,j, temp;
    for(int i=e;i>0;i--){
        ///Create one random index
        j = rand()%(i+1);
        swap(a[i],a[j]);
    }
}

int partition(int *a,int s,int e){

    int i=s-1;
    int j = s;
    int pivot = a[e];
    for( ;j<e;j++){
        c++;
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    ///Bring the pivot element to its sorted position
    swap(a[i+1],a[e]);
    return i+1;
}

void quickSort(int *a,int s,int e){
    if(s>=e){
        return;
    }

    int p = partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}

int main(){

    int a[20],n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    shuffle(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


    quickSort(a,0,n-1);
    cout<<"\n\nSORTED ARRAY : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    cout<<"\n\nCOMPARISONS = "<<c;

return 0;
}

