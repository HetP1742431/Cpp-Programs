// Name: Het Bharatkumar Patel
// SID: 1742431
// CCID: hetbhara
// AnonID: 1000348298
// CMPUT 275, Winter 2023

// Weekly Exercise #5: Bash History
// ----------------------------------

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // declaring variables and getting input from user
    int n;
    cin >> n;

    map<string, set<string>> directories; // declaring a map with keys of a string type and values of set (string)
    directories["/"];                     // initializing a map "directories" with a root directory ("/")

    string command, argument;
    string currentDir = "/"; // define a current directory path as a root directory ("/")

    for (int i = 0; i <= n; i++)
    // this for loop takes input from user nd sore the value as command and argument (strings)
    // checks if the command (string) entered by user is "cd" or "ls"
    {
        if (i != n)
        {
            cin >> command >> argument;
        }

        if (command == "cd")
        // if the command is "cd" checks whether the argument is ".." or a directory name
        {
            if (argument == "..")
            // if the argument entered by user is ".." then go back to the previous current directory
            // erase the latest added directory from the path of current directory (cuurentDir)
            {
                if (directories[currentDir].empty())
                // if current directory has no files in it then add an empty file in the current directory
                {
                    directories[currentDir].insert("");
                }
                auto last_slash = currentDir.rfind("/");
                auto second_last_slash = currentDir.rfind("/", last_slash - 1);
                currentDir.erase(second_last_slash + 1); // erase the lastest added directory
            }
            else
            // if argument is a name of the directory then add a new directory to the path of current directory (currentDir)
            {
                if (directories[currentDir].empty())
                // if current directory has no files in it then add an empty file in the current directory
                {
                    directories[currentDir].insert("");
                }
                currentDir += argument + "/";
            }
        }
        else
        // if the command is "ls" then check if the file is in the current directory
        // if not there then add a new file entered as an argument to the current directory
        {
            auto file_name = directories[currentDir].find(argument);
            if (file_name != directories[currentDir].end())
            // check if the file is already there in the current directory or not
            // if the file is there then continue
            {
                continue;
            }
            else
            // if the file is not there in the current directory then add a new file to the current directory
            {
                directories[currentDir].insert(argument); // insert new file to the set (value)
            }
        }
    }

    for (auto it : directories)
    // print the keys and values of the map "directories"
    {
        auto key = it.first;
        auto value = it.second;
        if (key != "/")
        {
            key.erase(key.size() - 1); // remove last "/" from the key
        }
        cout << key; // output key (path of the directory)
        for (auto file : value)
        {
            if (file != "")
            {
                cout << " ";
            }
            cout << file; // output files in the certain path of directories
        }
        cout << endl;
    }
    return 0;
}