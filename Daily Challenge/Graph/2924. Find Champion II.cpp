/*
    Leetcode Link               : https://leetcode.com/problems/find-champion-ii
*/


/************************************************************ C++ ************************************************/
//Approach-1:  Simple track visited node
//T.C : O(N)
//S.C : O(N)
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        bool vis[n];
        memset(vis, false, n);
        for (int i = 0; i < edges.size(); i++) {
            vis[edges[i][1]] = true;
        }

        int ans = -1;

        for (int i = 0; i < n; i++) { // cout<<"i:"<<i<<" vis:"<<vis[i]<<endl;
            if (!vis[i]) {
                if (ans == -1) ans = i;
                else return -1;
            }
        }

        return ans;
    }
};


//Approach-2:  Use DFS
//T.C : O(N + M)
//S.C : O(N)
class Solution {
public:
    static const int N = 1e5;
    vector<int> grp[N];
    bool vis[N];

    void dfs(int source) {
        // cout<<"source: "<<source<<endl;
        for (auto child : grp[source]) { // cout<<"child: "<<child<<endl;
            if (vis[child]) continue;

            vis[child] = true;
            dfs(child);
        }
    }

    int findChampion(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            grp[edges[i][0]].push_back(edges[i][1]);
        }

        for (int i = 0; i < n; i++) {
            dfs(i);
        }

        int ans = -1;

        for (int i = 0; i < n; i++) { // cout<<"i:"<<i<<" vis:"<<vis[i]<<endl;
            if (!vis[i]) {
                if (ans == -1) ans = i;
                else return -1;
            }
        }

        return ans;
    }
};
