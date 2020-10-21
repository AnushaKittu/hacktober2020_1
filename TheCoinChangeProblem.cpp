#include <iostream>
#include <vector>
using namespace std;

//RECURSION
long helper(int n, vector<long> c, int index)
{
  if (n == 0)
  {
    return 1;
  }
  if (n < 0)
  {
    return 0;
  }
  int m = c.size();
  long ans = 0;
  for (int i = index; i < m; i++)
  {
    ans += helper(n - c[i], c, index);
    index++;
  }
  return ans;
}
long getWays(int n, vector<long> c)
{
  if (n <= 0)
  {
    return 0;
  }
  //return helper(n,c,0);
  int m = c.size();
  long int dp[m + 1][n + 1];
  for (int i = 0; i <= n; i++)
  {
    dp[0][i] = 0;
  }
  for (int i = 0; i <= m; i++)
  {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (c[i - 1] <= j)
      {
        dp[i][j] = dp[i - 1][j] + dp[i][j - c[i - 1]];
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  cout << dp[m][n] << endl;
  return dp[m][n];
}
// {
//     if(n <= 0)
//     {
//         return 0;
//     }
//     //DP
//     int dp[n + 1];
//     dp[0] = 1;
//     for (int i = 0; i < c.size(); i++) {
//             for (int j = 0; j <= n; j++) {
//                 if (c[i] <= j) {
//                     dp[j] += dp[j - c[i]];
//                 }
//             }
//         }
//     return dp[n];
//     // return helper(n,c,0);
// }