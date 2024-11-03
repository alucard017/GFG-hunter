//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
           int posC = INT_MAX;
           int negC = INT_MIN;
           sort(arr,arr+n);
           int i = 0;
           int j = n-1;
           int sum = 0;
           while(i<j){
               sum = arr[i]+arr[j];
               if(sum==0){
                   return sum;
               }
               else if(sum>0){
                   posC = min(posC,sum);
                   j--;
               }
               else{
                   negC = max(negC,sum);
                   i++;
               }
           }
           if(posC == INT_MAX) return negC;
           else if(negC == INT_MIN) return posC;
           return abs(negC)<posC ? negC : posC;
        }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends