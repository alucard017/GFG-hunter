//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        for(auto it:exp)
        {
            if(isalpha(it))
            {
                st.push(string(1,it));
            }
            else
            {
                string operand1 = st.top();
                st.pop();
                string operand2 = st.top();
                st.pop();
                st.push("(" + operand2 + it + operand1 + ")");
            }
        }
        // if(st.size()==1)
        // {
        //     infix = st.top();
        //     st.pop();
        // }
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends