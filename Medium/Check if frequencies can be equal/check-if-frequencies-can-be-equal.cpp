//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char,int>mp;
        for(int i =0;i<s.length();i++){
            mp[s[i]]++;
        }
        int count=0;
        int x = mp[s[0]];
        for (auto i: mp){
            if (abs(i.second - x)>1){
                return false;
            }else{
                if(abs(i.second - x)==1){
                    count++;
                }
            }
        }
        if (count>1){
            return false;
        }
        return true;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends