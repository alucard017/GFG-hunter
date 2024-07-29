//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool check(char a,char b)
    {
        if(a=='(' && b==')' || a=='{' && b=='}' || a=='[' && b==']')
         return true;
        else 
        return false; 
    }
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        for(auto it:x)
        {
            if(it=='(' || it == '{' || it == '[')
             st.push(it);
            else
            {
                if(st.empty()){
                    return false;
                }
                char popped = st.top();
                st.pop();
                if(!check(popped,it))
                {
                    return false;
                }
                
            }
        }
        if(!st.empty()) return false;
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends