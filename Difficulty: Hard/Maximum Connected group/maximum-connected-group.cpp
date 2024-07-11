//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisJointSet{
public:
	vector<int>size, parent;
	// Constructor
	DisJointSet(int n){
		size.resize(n+1,1);
		parent.resize(n+1,0);
		for(int i = 0; i<n+1; i++) parent[i]=i;
	}

	int findParent(int node){
		if(node == parent[node])
			return node;
		return parent[node] = findParent(parent[node]);
	}

	void unionBySize(int u, int v){
		int ul_u = findParent(u);
		int ul_v = findParent(v);
		if(ul_v == ul_u) return;

		if(size[ul_v]>size[ul_u]){
			parent[ul_u] = ul_v;
			size[ul_v] += size[ul_u];
		}
		else {
			parent[ul_v] = ul_u;
			size[ul_u] += size[ul_v];
		}
	}
};



class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        DisJointSet ds(n*m);
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i = 0;i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k<4; k++){
                        int nr = i+dr[k];
                        int nc = j+dc[k];
                        if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == 1){
                          
                            ds.unionBySize(i*n+j, nr*n + nc);
                        }
                    }    
                }
                
            }
        }
   
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    set<int>st;
                    for(int k = 0; k<4; k++){
                        int nr = i+dr[k];
                        int nc = j+dc[k];
                        if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == 1){
                            st.insert(ds.findParent(nr*n + nc));
                        }
                    }
                    int curr = 1;
                    for(auto it: st){
                        curr += ds.size[it];
                    }
                    ans = max(ans, curr);
                }else{
                    ans = max(ans, ds.size[ds.findParent(i*n+j)]);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends