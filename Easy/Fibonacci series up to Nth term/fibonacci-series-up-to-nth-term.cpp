//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long mod = 1e9+7;
    vector<int> Series(int n) {
        // Code here
        vector<int>ans;
        ans.push_back(0);
        ans.push_back(1);
        int prev2=0,prev1=1;
        for(int i=2;i<=n;i++) {
            int curr = (prev2+prev1)%mod;
            prev2=prev1;
            prev1=curr;
            ans.push_back(curr);
        }
        return ans;
    }  // Code here
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends