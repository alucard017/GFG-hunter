//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        int n = sentence.length();
        long long maxi = INT_MIN;
        // vector<string> arr;
        string s  = "";
        for(int i=0;i<n;i++)
        {
            if(sentence[i]>='0' && sentence[i]<='9')
            {
                s+=sentence[i];
            }
            else if(s.length()>0 && s.find('9')==string::npos)
            {
                maxi = max(maxi,stoll(s));
                s = "";
            }
            else
            {
                s = "";
            }
        }
        if(s.length()>0 && s.find('9')==string::npos) maxi = max(maxi,stoll(s));
        return (maxi==INT_MIN) ? -1 : maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends