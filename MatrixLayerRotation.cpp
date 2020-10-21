#include <iostream>
using namespace std;
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int R)
{
  int M = matrix.size();
  int N = matrix[0].size();
  // while(r<=row/2 && c<= col/2)
  // {   k = k%(2*(m + n - 4*r) - 4);
  //     l = 0;
  //     while(l < k)
  //     {
  //         i = r;
  //         int d = matrix[r][c];
  //         //cout<<"i "<<i<<" j "<<j<<endl;
  //         for(j = c+1;j <= col - c;j++)
  //         {
  //             matrix[i][j-1] = matrix[i][j];
  //         }
  //         j--;i++;
  //         //cout<<"i "<<i<<" j "<<j<<endl;
  //         for(;i<=row - r;i++)
  //         {
  //             matrix[i-1][j] = matrix[i][j];
  //         }
  //         i--;j--;
  //         //cout<<"i "<<i<<" j "<<j<<endl;
  //         for(;j>=c;j--)
  //         {
  //             matrix[i][j+1] = matrix[i][j];
  //         }
  //         j++;i--;
  //         //cout<<"i "<<i<<" j "<<j<<endl;
  //         for(;i>r;i--)
  //         {
  //             matrix[i+1][j] = matrix[i][j];
  //         }
  //         matrix[r+1][c] = d;
  //         l++;
  //     }
  //     r++;
  //     c++;
  //}
  int numRings = min(M, N) / 2;
  for (int i = 0; i < numRings; i++)
  {
    // Subtract the number of 360 degree rotations from R
    // A 360 degree rotation = rotating the same number of times as the perimeter of the current ring
    int numRotations = R % (2 * (M + N - 4 * i) - 4);
    for (int rotation = 0; rotation < numRotations; rotation++)
    {
      // Rotate the ring (see the clockwise algorithm for an in-depth example of how this is done)
      // Rotate top row
      for (int j = i; j < N - i - 1; j++)
      {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[i][j + 1];
        matrix[i][j + 1] = tmp;
      }
      // Rotate right column
      for (int j = i; j < M - i - 1; j++)
      {
        int tmp = matrix[j][N - i - 1];
        matrix[j][N - i - 1] = matrix[j + 1][N - i - 1];
        matrix[j + 1][N - i - 1] = tmp;
      }
      // Rotate bottom row
      for (int j = N - i - 1; j > i; j--)
      {
        int tmp = matrix[M - i - 1][j];
        matrix[M - i - 1][j] = matrix[M - i - 1][j - 1];
        matrix[M - i - 1][j - 1] = tmp;
      }
      // Rotate left column
      for (int j = M - i - 1; j > i + 1; j--)
      {
        int tmp = matrix[j][i];
        matrix[j][i] = matrix[j - 1][i];
        matrix[j - 1][i] = tmp;
      }
    }
  }
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return;
}
