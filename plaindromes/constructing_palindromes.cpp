#include <bits/stdc++.h>
using namespace std;

int palindrome_length(string s) {
        unordered_map<char, int> letter_map;
        int length = 0, flag = false;

        for(char k : s)letter_map[k]++;

        for(auto i : letter_map){
            if(i.second % 2 == 0){
                length += i.second;
            }
            else{
                length += i.second - 1;
                flag = true;
            }
        }
        if (flag){
            length = length + 1;
        }
        return length;
    }

int main(){
	// declare your variables
	int n;
	string s;

	// read the input
	cin >> n;
	cin >> s;

	// solve, good luck!
	cout << palindrome_length(s) << endl;
	return 0;

}
