#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n, k, t;
    cin >> n >> k >> t;
    int glass = k;

    int capacity[n];
    int source[n];
    for (int i = 0; i < n; i++)
    {
        cin >> capacity[i] >> source[i];
    }
    int time = capacity[glass];

    if (glass == 0)
    {
        cout << time * t << endl;
    }
    else
    {
        while (glass != 0)
        {
            glass = source[glass];
            time += capacity[glass];
        }
        cout << time * t << endl;
    }

    return 0;
}