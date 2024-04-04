//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
         long long mod = 1000000007; 
        long long ans = 0, prev = 0, curr = 0;
        for(int i = 0; i < s.size(); i++)
        {
            curr = (prev * 10)%mod + (s[i]-'0') * (i+1);
            prev = curr%mod;
            ans = (ans + curr)%mod; 
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends