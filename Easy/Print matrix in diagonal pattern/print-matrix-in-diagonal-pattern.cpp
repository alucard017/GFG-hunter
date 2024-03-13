//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int z=0;
        int n=mat.size();
        vector<int> res (n*n);
         
        //upper triangular
        for(int i=0;i<n;i++){
            int j=0, k=i;
            for(int m=0;m<=i;m++){
                if(i%2==0){ 
                    res[z++]=mat[k][j];
                }
                else{
                    res[z++]=mat[j][k];
                } 
                k--,j++;    
            }
        }
        
        z=n*n-1;
        // lower triangular
        for(int i=n-1, p=0;i>0;i--, p++){
            int j=n-1, k=i;
            for(int m=i;m<n;m++){
                if(p%2==0){
                    res[z--]=mat[k][j];
                }
                else{
                    res[z--]=mat[j][k];
                }
                k++,j--;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends