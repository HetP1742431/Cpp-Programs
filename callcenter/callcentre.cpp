#include <iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    int calls_no[n + 1] = {};
    for (int i = 1; i <= n; i++) {
        cin >> calls_no[i];
        calls_no[i] += calls_no[i - 1];
    }

    int output[q] = {};
    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        output[i] = calls_no[t] - calls_no[s - 1];
    }

    for (int x = 0; x < q; x++) {
        cout << output[x] << endl;
    }

    return 0;
}
