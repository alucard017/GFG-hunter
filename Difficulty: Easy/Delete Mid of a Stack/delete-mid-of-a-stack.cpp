//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void del(stack<int> &st,int n)
    {
        if(n==1)
        {
            st.pop();
            return;
        }
        int temp = st.top();
        st.pop();
        del(st,n-1);
        st.push(temp);
        return;
    }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s, int sizeOfStack) {
        int n;
        // code here..
        if(sizeOfStack&1)
        {
            n = (sizeOfStack+1)/2;
        }
        else
         n = (sizeOfStack/2)+1;
         
        del(s,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends