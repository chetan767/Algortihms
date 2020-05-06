#include<iostream>
using namespace std;

void permutations(char *in,int i)
{
    // Base case
    if(in[i] == '\0')
    {
        cout<<in<<endl;
        return;
    }

 for(int j=i;in[j]!='\0';j++)
 {
 swap(in[i],in[j]);
 permutations(in,i+1);
 swap(in[j],in[i]);
 }

}

int main()
{
    char in[10];
    cin>>in;

    char out[100];

    permutations(in,0);
    return 0;
}
