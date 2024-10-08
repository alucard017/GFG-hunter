//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

vector<int> primes(1000000,1);
class Solution {
  public:
    
    void sieve(){}
    void fun(int n) {
        primes[0] = primes[1] = 0;
        for(int i=2;i*i<=n;i++)
        {
            if(primes[i])
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    primes[j] = 0;
                }
            }
        }
    }

    vector<int> findPrimeFactors(int N) {

        fun(N);
        // Write your code her
        vector<int> ans;
        for(int i=2;i<=N;i++)
        {
            if(primes[i])
            {
                while(N%i==0){
                ans.push_back(i);
                N/=i;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends