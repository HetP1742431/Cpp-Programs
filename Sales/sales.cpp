// Name: Het Bharatkumar Patel
// SID: 1742431
// CCID: hetbhara
// AnonID: 1000348298
// CMPUT 275, Winter 2023

// Weekly Exercise #3: Sales
// ----------------------------------

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // declaring variables and getting inputs from user
    int n, T, p;
    cin >> n >> T;
    unordered_map<int, bool> price_map;

    // solving the problem
    for (int i = 0; i < n; i++)
    // this for loop takes input from user and store those values in hash table
    // this for loop also checks if we have any two prices which make up to T (pi + pj = T)
    {
        cin >> p;
        if (price_map.find(T - p) != price_map.end()) // check if we have T-p in our hash table (price_map)
        {                                             // (p) + (T-p) = T (check if we have pi + pj = T)
            cout << "YES" << endl;                    // print "YES" if we have pairs which make up pi + pj = T
            return 0;
        }
        price_map[p] = true;
    }
    cout << "NO" << endl; // print "NO" if we don't have any pairs
    return 0;
}
