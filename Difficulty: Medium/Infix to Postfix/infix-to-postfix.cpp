//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char ch)
    {
        int ans = 0;
        if(ch=='^')
         ans = 3;
        else if(ch == '*' || ch == '/')
         ans =  2;
        else if(ch=='+' || ch == '-')
         ans =  1;
        return ans; 
    }
    string infixToPostfix(string s) {
        // Your code here
        string ans = "";
        stack<char> st;
        for(auto it:s)
        {
            if(it=='(')
             st.push(it);
            else if(iswalnum(it))
            {
                ans+=it;
            }
            else if(it==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    char popped = st.top();
                    st.pop();
                    ans+=popped;
                }
                if(!st.empty()) st.pop();
            }
            else
            {
                while(!st.empty() &&( precedence(it)<=precedence(st.top())))
                {
                    char popped = st.top();
                    st.pop();
                    ans+=popped;
                }
                st.push(it);
            }
        }
        while(!st.empty())
        {
            char popped = st.top();
            st.pop();
            ans+=popped;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends