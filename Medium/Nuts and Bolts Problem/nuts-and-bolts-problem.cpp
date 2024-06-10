//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    public:
 unordered_map<char, int> mp;

    Solution() {
        mp['!'] = 0;
        mp['#'] = 1;
        mp['$'] = 2;
        mp['%'] = 3;
        mp['&'] = 4;
        mp['*'] = 5;
        mp['?'] = 6;
        mp['@'] = 7;
        mp['^'] = 8;
    }

    bool customComparator(char a, char b) {
        return mp[a] < mp[b]; // Sort in ascending order based on the map values
    }

    static bool comparator(char a, char b, Solution* obj) {
        return obj->customComparator(a, b);
    }

    void matchPairs(int n, char nuts[], char bolts[]) {
        std::sort(nuts, nuts + n, [this](char a, char b) { return comparator(a, b, this); });
        std::sort(bolts, bolts + n, [this](char a, char b) { return comparator(a, b, this); });   
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends