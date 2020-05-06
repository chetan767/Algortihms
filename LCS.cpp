///Write a program to determine the LCS of two given sequences
/// MADE BY CHETAN KHANNA
#include <bits/stdc++.h>
using namespace std;

void lcs(string S1, string S2, int m, int n)
{
  int LCS[m + 1][n + 1];

  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
        LCS[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS[i][j] = LCS[i - 1][j - 1] + 1;
      else
        LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
    }
  }

  int index = LCS[m][n];
  char lcs[index + 1];
  lcs[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0)
  {
    if (S1[i - 1] == S2[j - 1])
    {
      lcs[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS[i - 1][j] > LCS[i][j - 1])
      i--;
    else
      j--;
  }

  cout<<"\nLCS : "<<lcs;
}

int main()
{
  string S1,S2;
  cin>>S1>>S2;
  int m = S1.length();
  int n = S2.length();

  lcs(S1, S2, m, n);
}
