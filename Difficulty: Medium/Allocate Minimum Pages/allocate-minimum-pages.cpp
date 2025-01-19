//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isPossible(vector<int> arr, int k, int mid){
        int pos = arr[0];
        int i = 1;
        int count = 1;
        int n = arr.size();
        if(n<k) return false;
        while(i<n){
            if(pos+arr[i]<=mid){
                pos+=arr[i];
            }
            else{
                count++;
                if(count>k)
                 return false;
                pos = arr[i];
            }
            i++;
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int start = *max_element(arr.begin(),arr.end());
        int end = accumulate(arr.begin(),arr.end(),0);
        int ans = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(arr,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else
             start = mid+1;
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

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends