/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/
//Solution 1: my solution. the Space complexity is O(n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> zero_vec(n,0);
        set<int> s_row;
        set<int> s_col;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j] == 0){
                    s_row.insert(i);
                    s_col.insert(j);
                }
            }
        }
        for(int i=0;i<m;++i){
            if(s_row.find(i) != s_row.end())
                matrix[i] = zero_vec;
            else{
                for(int j=0;j<n;++j){
                    if(s_col.find(j) != s_col.end())
                        matrix[i][j] = 0;
                }
            }
        }
    }
};