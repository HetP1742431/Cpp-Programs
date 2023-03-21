#include <iostream>
using namespace std;

int main()
{
	// Declare your variables
	int neighbours, time;
	cin >> neighbours >> time;
	int time_left[neighbours];
	int time_return[neighbours];
	int practice_time = 0;

	// Read the input
	for (int i = 0; i < neighbours; i++)
		cin >> time_left[i] >> time_return[i];

	// Solve the problem
	for (int j = 0; j < 24; j++)
	{
		for (int k = 0; k < neighbours; k++)
		{
			if (j <= time_left[k] || j > time_return[k])
			{
				break;
			}
			else if (k == neighbours - 1)
			{
				practice_time++;
			}
		}
	}

	if (practice_time == 0)
	{
		cout << "IMPOSSIBLE" << endl;
	}
	else if (time % practice_time == 0)
	{
		cout << time / practice_time << endl;
	}
	else
	{
		cout << time / practice_time + 1 << endl;
	}
	return 0;
}