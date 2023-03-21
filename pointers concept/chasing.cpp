#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // declare variables
  int S, A;
  cin >> S >> A;
  int ptr_arr[A];
  vector<int> seen_ptrs {0};

  // read the input
  for (int i = 0; i < A; i++)
  {
    cin >> ptr_arr[i];
  }

  // solve the problem
  
  if (ptr_arr[0] < 0)
  {
    cout << ptr_arr[0] << endl;
  }
  else
  {
    int k = ptr_arr[0] - S;
    if (ptr_arr[k] < 0)
    {
      cout << ptr_arr[k] << endl;
    }
    
    while (ptr_arr[k] >= 0)
    {
      if (ptr_arr[k] < 0)
      {
        cout << ptr_arr[k] << endl;
        break;
      }
      else if ((find(seen_ptrs.begin(), seen_ptrs.end(), k) != seen_ptrs.end()))
      {
        cout << "There was a cycle" << endl;
        break;
      }
      else
      {
        seen_ptrs.push_back(k);
        k = ptr_arr[k] - S;
      }
    }
  }

  // print the output

  return 0;
}
