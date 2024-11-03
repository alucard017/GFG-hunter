//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int minDiff = INT_MAX;
        int i = 0;
        int j = n-1;
        int ans_i = -1;
        int ans_j = -1;
        while(i<j){
            int sum = arr[j]+arr[i];
            int diff = abs(sum-k);
            if(diff < minDiff){
                minDiff = diff;
                ans_i = i;
                ans_j = j;
            }
            if(sum==k){
                return {arr[i],arr[j]};
            }
            else if(sum<k){
                i++;
            }
            else{
                j--;
            }
        }
        return {arr[ans_i],arr[ans_j]};
        
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, k);
        cout << ans[0] << " " << ans[1] << "\n";
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends