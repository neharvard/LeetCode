/*
    Leetcode Link               : https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using BFS (edges are unweighted)
//T.C : O(q * (E log(V)) , V = number of vertices and E = number of edges
//S.C : O(V+E)
class Solution {
public:
    int bfs(int n, unordered_map<int, vector<int>>& grp) {
        queue<int> que;
        vector<bool> vis(n, false);

        que.push(0);
        vis[0] = 1;
        int level = 0;

        while (!que.empty()) {
            int sz = que.size();
            while (sz--) {
                int cur_v = que.front();
                que.pop();
                // cout << "cur: " << cur_v << endl;

                if (cur_v == n - 1) return level;

                for (int child : grp[cur_v]) {
                    if (!vis[child]) {
                        que.push(child);
                        vis[child] = 1;
                    }
                }
            }
            level++;
        }

        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>>& queries) {
        int sz = queries.size();
        vector<int> ans(sz);
        unordered_map<int, vector<int>> grp;

        for (int i = 0; i <= n - 2; i++) {
            grp[i].push_back(i + 1);
        }

        for (int i = 0; i < sz; i++) {
            grp[queries[i][0]].push_back(queries[i][1]);

            int dis = bfs(n, grp);
            ans[i] = dis;
        }

        return ans;
    }
};

/*
/// BFS [Not so optimized]
class Solution {
public:
    static const int N = 1e5;
    vector< int > grp[N];
    bool vis[N];
    int level[N];

    void bfs(int source) {
        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while (!q.empty()) {
            int cur_v = q.front();
            q.pop();  //cout<<"cur: "<<cur_v<<endl;

            for (int child : grp[cur_v]) {  //cout<<"child: "<<child<<endl;
                if (!vis[child]) {
                    q.push(child);
                    vis[child] = 1;
                    level[child] = level[cur_v] + 1;
                }
            }
        }
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>&queries) { 
        int sz = queries.size(); vector<int> ans(sz);

        for (int i = 0; i <= n - 2; i++) {
            grp[i].push_back(i + 1);
        }

        for (int i = 0; i < sz; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            grp[x].push_back(y);

            bfs(0);
            // for(int i=0; i<n; i++) cout<<level[i]<<" "; cout<<endl;
            // cout << "ans: " << level[n - 1] << endl;

            ans[i] = level[n - 1];
            memset(vis, false, N);
            memset(level, 0, N);
        }

        return ans;
    }
};
*/
