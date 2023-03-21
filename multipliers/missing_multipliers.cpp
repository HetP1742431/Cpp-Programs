#include <iostream>
using namespace std;

int main()
{

	int n, m, in_arr[100000];
	cin >> n >> m;

	long long answer = 1;

	long long *left = new long long[n];
	long long *right = new long long[n];

	for (int i = 0; i < n; i++)
	{
		cin >> in_arr[i];
	}

	for (int i = 0; i < (n - 1 - m); i++)
	{
		answer = answer*in_arr[n - 1 - i];
		left[n - m - i - 2] = answer;
	}

	for (int i = (n - 1 - m); i < n; i++)
	{
		left[i] = 0;
	}

	for (int i = 0; i <= m; i++)
	{
		right[i] = 0;
	}

	answer = 1;

	for (int i = (m + 1); i < n; i++)
	{
		answer = answer*in_arr[i - 1 - m];
		right[i] = answer;
	}

	for (int i = 0; i < n; i++)
	{

		if (i <= m)
		{
			answer = left[i];
		}
		else if (i >= (n - 1 - m))
		{
			answer = right[i];
		}
		else
		{
			answer = left[i] * right[i];
		}

		if ((m == i) && (i == (n - 1) / 2))
		{

			if (n - 1 != 0)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else if (n - 1 == i)
		{
			cout << answer << endl;
		}
		else
		{
			cout << answer << " ";
		}
	}

	return 0;
}