//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPossible(vector<int> stalls, int k, int val){
        int pos = stalls[0];
        int count = 1;
        int n = stalls.size();
        for(int i=1;i<n;i++){
            if(pos+val<=stalls[i]){
                count++;
                pos=stalls[i];
                // if(count == k??
            }
        }
        return count>=k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int start = 1;
        int n = stalls.size();
        int ans = 0;
        int end = stalls[n-1]-stalls[0];
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(stalls,k,mid)){
                ans = mid;
                start = mid+1;
            }
            else
             end = mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends