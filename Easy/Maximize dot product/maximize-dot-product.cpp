//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	 int product(int n,int m,int a[],int b[],int i,int j,int &maxi,vector<vector<int>>&dp)
    {
        
        if(j==0 && i>=0)
        {
            return 0;
        }
        
        if(i==0)
        {
            return INT_MIN;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
       
        int t=(a[i-1]*b[j-1])+product(n,m,a,b,i-1,j-1,maxi,dp);
       
        int nt=product(n,m,a,b,i-1,j,maxi,dp);
        maxi=max(maxi,max(t,nt));
        return dp[i][j]=max(t,nt);
    }
    
    int maxDotProduct(int n, int m, int A[], int B[]) 
    { 
        int maxi=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return product(n,m,A,B,n,m,maxi,dp);
        return maxi;
    } 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends