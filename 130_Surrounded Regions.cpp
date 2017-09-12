/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
//use DFS technology
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        using it_type = vector<char>:iterator;
        int cfg_row = board.size();
        int cfg_col = board[0].size();
        vector<it_type,it_type> pos();
        
    }
    bool is_finished(vector<int> right,int &indx,int len){
        for(int i=0; i<right.size(); ++i){
            if(i < len){
                indx = i;
                return false;
            }
        }
        indx = right.size();
        return true;
    }
    void update_index(vector<vector<char>> bo,vector<vector<char>::iterator,> &left, vector<int> &right, bool update_left, int len){
        bool is_finished = true;
        int j=0;
        for(int i = 0; i<left.size(); ++i){
            if(right[i] == len) {
                continue;
            }
            j= find_fisrt_of('O',bo[i],right[i]);
            if(j == )
        }
    }
};