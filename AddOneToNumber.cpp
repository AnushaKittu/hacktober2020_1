#include <iostream>
#include <vector>
using namespace std;
vector<int> plusOne(vector<int> &A)
{
  int s = A.size();
  int sum = A[s - 1] + 1;
  int carry = sum / 10;
  int num = sum % 10;
  vector<int> ans;
  ans.push_back(num);
  if (s - 1 == 0)
  {
    if (carry > 0)
      ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    return ans;
  }
  for (int i = s - 2; i >= 0; i--)
  {
    sum = A[i] + carry;
    carry = sum / 10;
    num = sum % 10;
    ans.push_back(num);
  }
  if (carry != 0)
  {
    ans.push_back(carry);
  }
  reverse(ans.begin(), ans.end());
  while (ans[0] == 0)
  {
    ans.erase(ans.begin());
  }
  return ans;
}
int main()
{
  int n;
  cin >> n;
  vector<int> numbers;
  for (int i = 0; i < n; i++)
  {
    int data = 0;
    cin >> data;
    numbers.push_back(data);
  }
  vector<int> ans = plusOne(numbers);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}