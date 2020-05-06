#include<bits/stdc++.h>

using namespace std;

bitset<30> col,d1,d2;
int c=0;
int board[10][10]={0};
void solve(int r,int n)
{
    if(r==n)
    {
        c++;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                board[i][j]==1?cout<<"Q ":cout<<"_ ";
            }
            cout<<endl;
        }

        cout<<"\n\n\n\n";
        return;
    }
    for(int c=0; c<n; c++)
    {
        if(!col[c]&&!d1[r-c+n-1]&&!d2[r+c])
        {
            col[c]=d1[r-c+n-1]=d2[r+c]=board[r][c]=1;
            solve(r+1,n);
            col[c]=d1[r-c+n-1]=d2[r+c]=board[r][c]=0;
        }
    }
}
int main()
{
    solve(0,5);
    cout<<c;
}
