// Name : Het Bharatkumar Patel
// SID : 1742431
// CCID : hetbhara
// AnonID : 1000348298
// CMPUT 275, Winter 2023

// Weekly Exercise #2: Idols
// ----------------------------------

#include <iostream>
using namespace std;

void reverse(int *begin, int *end)
/*
This function reverses all entries between two pointers given as an input,
including the entry provided to by begin but not the entry pointed at end
Arguments:
        Inputs: This function takes two pointers as an input arguments which are
                pointing into an array
                begin : pointer of an entry from an array where the reversing begins
                end : pointer of an entry from an array where the reversing stops
                      (this entry will not be reversed by this function.)
        Outputs: None
*/
{
    while (begin < end - 1)
    // Reverse the order of the entries in an array by using temporary variable (temp).
    {
        int temp = *begin;
        *begin = *(end - 1); // swap the entries
        *(end - 1) = temp;
        begin++;
        end--;
    }
}

int main()
/*
This function identifies idols (entry which is larger than every entry after itself)
from the array and calls the reverse function to swap the order of the entries in an array
Arguments:
        Inputs: None
        Outputs: integer 0 (main funciton always returns 0)
*/
{
    // declaring variables
    int n;
    cin >> n;
    int num_array[n];
    int *begin;
    int *end;

    // reading the input (array)
    for (int i = 0; i < n; i++)
        cin >> num_array[i];

    // finding the idol
    for (int k = 0; k < n; k++)
    // This loop checks whether the entry is larger than every entry after it in an array or not.
    // If yes, that entry (idol) gets printed and the idol group gets reversed using reverse funciton.
    {
        if (k == n - 1)
        // last element of an array will always be an idol of any array
        {
            cout << num_array[k] << endl;
            end = &num_array[k];
            reverse(begin, end);

            for (int p = 0; p < n; p++)
            // This loop prints an array after getting reversed
            {
                if (p != n - 1)
                {
                    cout << num_array[p] << " ";
                }
                else
                {
                    cout << num_array[p] << endl;
                }
            }
        }
        if (k == 0)
        {
            begin = num_array;
        }

        for (int l = k + 1; l < n; l++)
        {
            if (num_array[k] <= num_array[l])
            // If entry is smaller than any entry after it, break the loop
            // and move to the next entry in an array
            {
                break;
            }
            else if (l == n - 1)
            // If the entry is larger than every entry after it, print that
            // entry (idol) and reverse the group
            {
                cout << num_array[k] << " ";
                end = &num_array[k];
                reverse(begin, end);
                begin = &num_array[k + 1];
            }
        }
    }
    return 0;
}
