//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        unordered_map<int, vector<int> > mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]].push_back(i);
    }

    sort(arr,arr+n);
    int maxi = INT_MIN;
    int temp = n;

    for (int i = 0; i < n; i++) {
        if (temp > mp[arr[i]][0]) {
            temp = mp[arr[i]][0];
        }
        maxi = max(
            maxi,
            mp[arr[i]][mp[arr[i]].size() - 1]
                - temp);
    }
    return maxi;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends