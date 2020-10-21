#include <iostream>
using namespace std;

// An Inplace function to
// rotate a N x N matrix
// by 90 degrees in
// anti-clockwise direction
void rotateMatrix(int mat[][4])
{
  int N = 4;
  // Consider all squares one by one
  for (int x = 0; x < N / 2; x++)
  {
    // Consider elements in group
    // of 4 in current square
    for (int y = x; y < N - x - 1; y++)
    {
      // Store current cell in
      // temp variable
      int temp = mat[x][y];

      // Move values from right to top
      mat[x][y] = mat[y][N - 1 - x];

      // Move values from bottom to right
      mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];

      // Move values from left to bottom
      mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];

      // Assign temp to left
      mat[N - 1 - y][x] = temp;
    }
  }
}

// Function to print the matrix
void displayMatrix(int mat[4][4])
{
  int N = 4;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      printf("%2d ", mat[i][j]);

    printf("\n");
  }
  printf("\n");
}

/* Driver program to test above functions */
int main()
{
  int n = 4;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }
  rotateMatrix(mat);
  // Print rotated matrix
  displayMatrix(mat);

  return 0;
}