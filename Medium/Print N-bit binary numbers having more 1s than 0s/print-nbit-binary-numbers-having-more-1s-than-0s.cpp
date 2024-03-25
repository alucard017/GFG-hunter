//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void solve(string temp,set<string>& s,int c,int c1,int n)
{
    if(temp.length()==n)
    {
        if(s.find(temp)==s.end() && c>=c1)
        {
            s.insert(temp);
        }
        return;
    }
    solve(temp+"1",s,c+1,c1,n);
    if(c1+1<=c)
    {
    solve(temp+"0",s,c,c1+1,n);
    }
}
    vector<string> NBitBinary(int n)
    {
        string temp="";
        set <string>s;
        solve(temp,s,0,0,n);
        vector<string> ans;
        for(auto i: s)
        {
            ans.push_back(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends