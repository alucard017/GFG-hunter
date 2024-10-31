//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    void solve(string &ans, string &s,int start, int k){
        if(k==0 || start == s.size()-1){
            return;
        }
        for(int i=start+1;i<s.size();i++){
            char maxi = *max_element(s.begin()+start,s.end());
            if(s[i] > s[start] && s[i] == maxi){
                swap(s[i],s[start]);
                if(ans<s) ans = s;
                solve(ans,s,start+1,k-1);
                swap(s[i],s[start]);
            }
        }
        solve(ans,s,start+1,k);
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
       solve(ans,str,0,k);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends