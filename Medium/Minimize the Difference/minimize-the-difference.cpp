//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        
         
         deque<int>d1;
         deque<int>d2;
         
         for(int i=k;i<n;i++){
             
             while(!d1.empty()&&arr[i]>d1.back()){
                  d1.pop_back();
             }
             
              while(!d2.empty()&&arr[i]<d2.back()){
                  d2.pop_back();
             }
             
             d1.push_back(arr[i]);
             d2.push_back(arr[i]);
         }
         
         
         
         int ans=d1.front()-d2.front();
         
         
         int j=0;
         
         for(int i=k;i<n;i++){
             
             if(d1.front()==arr[i]){
                 d1.pop_front();
             }
             
             if(d2.front()==arr[i]){
                 d2.pop_front();
             }
             
                   while(!d1.empty()&&arr[j]>d1.back()){
                  d1.pop_back();
             }
             
              while(!d2.empty()&&arr[j]<d2.back()){
                  d2.pop_back();
             }
             
             d1.push_back(arr[j]);
             d2.push_back(arr[j]);
             j++;
             
             ans=min(ans,d1.front()-d2.front());
             
         }
         
         return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends