/*
https://leetcode.com/problems/distinct-subsequences/description/
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
//Solution1: DP algorithm. Time Limit Exceed
//Description: f(x+S,x+T) = f(S,x+T) + f(S,T);
class Solution {
public:
	int numDistinct(string s, string t) {
		return dfs_numDistinct(s, 0, t, 0);
	}
	int dfs_numDistinct(string& s, int l, string& t, int r) {
		if (r == t.size()) return 1;
		else if (l >= s.size()) return 0;
		while (l<s.size()) {
			if (s[l] == t[r]) break;
			l++;
		}
		if (s.size() - l < t.size() - r ) return 0;
		return dfs_numDistinct(s, l+1, t, r + 1) + dfs_numDistinct(s, l+1, t, r);
	}
};
//Solution2: DP algorithm.
//https://leetcode.com/problems/distinct-subsequences/discuss/
//Description: use one array to store the dp result from bottom to up
class Solution {
public:
	int numDistinct(string s, string t) {
		vector<vector<int>> vec;
        vector<int> tmp(s.size()+1,1);
        vec.push_back(tmp);
        for(int i=0;i<t.size();++i){
            tmp[0] = 0;
            for(int j=0;j<s.size();++j){
                if(s[j]==t[i]) tmp[j+1] = vec[i][j] + tmp[j];
                else tmp[j+1] = tmp[j];
            }
            vec.push_back(tmp);
        }
        return *((*vec.rbegin()).rbegin());
	}
};