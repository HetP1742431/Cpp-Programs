#include <iostream>
#include <map>
using namespace std;

int main()
{
	// Read in the input
	int n, m, arr_time;
	cin >> n >> m;

	map<int, char> arrivals;
	for (int i = 0; i < n; i++)
	{
		cin >> arr_time;
		arrivals[arr_time] = 'W';
	}
	for (int i = 0; i < m; i++)
	{
		cin >> arr_time;
		arrivals[arr_time] = 'E';
	}

	// Solve the problem
	char ferry_location = 'W';
	int time = 0;

	while (!arrivals.empty())
	{
		int vehicle_time = arrivals.begin()->first;
		char vehicle_loc = arrivals.begin()->second;

		if (time < vehicle_time)
		{
			time = vehicle_time;
		}

		if (vehicle_loc != ferry_location)
		{
			time += 200;
		}
		else
		{
			time += 100;
			if (ferry_location == 'E')
			{
				ferry_location = 'W';
			}
			else
			{
				ferry_location = 'E';
			}
		}
		arrivals.erase(vehicle_time);
	}

	// Output the result

	cout << time << endl;

	return 0;
}