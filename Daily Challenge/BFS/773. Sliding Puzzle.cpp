/*
    Company Tags                : Airbnb
    Leetcode Link               : https://leetcode.com/problems/sliding-puzzle/description
*/


/******************************************** C++ ********************************************/
//Approach - BFS (asking for minimum moves - and problem different states)
//T.C : O(6!) : The puzzle has 6 ! = 720 possible permutations of the board, as there are 6 tiles, including the blank tile (0). 
  //In the worst case, BFS explores all permutations.
//S.C : O(6!) All states are stored in map
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";

        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                start += to_string(board[i][j]);
            }
        }
      
        string target = "123450";

        queue<string>que;
        que.push(start);

        unordered_map<int, vector<int>> ump;
        ump[0] = {1, 3};
        ump[1] = {0, 2, 4};
        ump[2] = {1, 5};
        ump[3] = {0, 4};
        ump[4] = {1, 3, 5};
        ump[5] = {2, 4};

        unordered_set< string > vis;
        vis.insert(start);
        
        int level = 0;
        while(!que.empty()){
            int n = que.size();
            // cout<<"nnn: "<<n<<endl;

            while(n--){
                string curr = que.front();
                que.pop(); //cout<<"curr: "<<curr<<endl;

                if(curr == target) return level;
                
                int zeroIndex = curr.find('0');
                // cout<<"zero: "<<zeroIndex<<endl;

                for(int idx : ump[zeroIndex]){
                    string newState = curr;
                    swap(newState[idx], newState[zeroIndex]);
                    // cout<<"curr11: "<<newState<<endl;

                    if(vis.find(newState) == vis.end()){
                        que.push(newState);
                        vis.insert(newState);
                    }
                }
            }

            level++;
        }

        return -1;
    }
};
