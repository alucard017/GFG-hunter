//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        int sumU = 0;
        int sumL = 0;
        int sumD = 0;
        for(int i=0;i<n;i++)
        {
            sumD+=matrix[i][i];
        }
        sumU+=sumD;
        sumL+=sumD;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                sumU+=matrix[i][j];
                sumL+=matrix[j][i];
            }
        }
        return {sumU,sumL};
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends