/*
    Company Tags  		: Google, Amazon, Microsoft, Uber, Apple, Snapchat
    Frequency     		: 80%
    Leetcode Link 		: https://leetcode.com/problems/valid-sudoku/
*/

//Approach-1 (Naive and simplest using 3 iterations of the sudoku)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // each row wise check
        for(int r=0; r<9; r++){
            set<int>st;
            for(int c=0; c<9; c++){
                if(board[r][c] == '.') continue;
                if(st.find(board[r][c]) != st.end()){
                    // cout<<"1: "<<"r:"<<r<<" c:"<<c<<" bb:"<<board[r][c]<<endl;
                    return false;
                } 
                st.insert(board[r][c]);
            }
        }

        // each col wise check
        for(int c=0; c<9; c++){
            set<int>st;
            for(int r=0; r<9; r++){
                if(board[r][c] == '.') continue;
                if(st.find(board[r][c]) != st.end()){
                    // cout<<"2: "<<"r:"<<r<<" c:"<<c<<" bb:"<<board[r][c]<<endl;
                    return false;
                } 
                st.insert(board[r][c]);
                // cout<<board[r][c]<<" ";
            } 
            // cout<<endl;
        }

        // square wise check
        for(int r=0; r<9; r += 3){
            for(int c=0; c<9; c += 3){
                set<int>st;
                for(int i=r; i<r+3; i++){
                    for(int j=c; j<c+3; j++){
                        if(board[i][j] == '.') continue;
                        if(st.find(board[i][j]) != st.end()){
                            // cout<<"3: "<<"i:"<<i<<" j:"<<j<<" bb:"<<board[i][j]<<endl;
                            return false;
                        } 
                        st.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};


//Approach-2 (One iteration using hashmap and indexing boxes)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string>st;
        string temp;

        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c] == '.') continue;

                string val = string(1, board[r][c]);
                int x = r/3;
                int y = c/3;

                string rowKey = val + "_r_" + to_string(r);  //cout<<"t1:"<<rowKey<<endl;
                string colKey = val + "_c_" + to_string(c);  //cout<<"t2:"<<colKey<<endl;
                string boxKey = val + "_box_" + to_string(x) + "_" + to_string(y);  //cout<<"t3:"<<boxKey<<endl;

                if(st.count(rowKey) || st.count(colKey) || st.count(boxKey)) return false;

                st.insert(rowKey);
                st.insert(colKey);
                st.insert(boxKey);
            }
        }

        return true;
    }
};

