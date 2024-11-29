/*
    Leetcode Link               : https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using Dijkstra's Algorothm) - STORING RESULT IN 2D Matrix
//T.C : O(m*n log(m*n))
//S.C : O(m*n)
class Solution {
public:
    #define P pair<int, pair<int, int> >
    vector< vector<int>>directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector< vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<P, vector<P>, greater<P> >pq;

        pq.push({grid[0][0], {0,0}}); // {value, {i, j}};
        dist[0][0] = 0;

        while(!pq.empty()){
           auto curr = pq.top();
           pq.pop();

           int time = curr.first;
           int row = curr.second.first;
           int col = curr.second.second;

           if(row == m-1 && col == n-1) return dist[m-1][n-1];

           if(vis[row][col]) continue;
           vis[row][col] = true;
           
           for(auto &dir : directions){
              int r = row + dir[0];
              int c = col + dir[1];

              if(r >= m || r<0 || c < 0 || c >= n || vis[r][c]) continue;

              if(grid[r][c] <= time+1){
                dist[r][c] = time + 1;
              }
              else if((grid[r][c] - time) % 2 == 0){
                dist[r][c] = grid[r][c] + 1;
              }
              else dist[r][c] = grid[r][c];

              pq.push({dist[r][c], {r, c}});
           }

        }

        return -1;
        
    }
};
