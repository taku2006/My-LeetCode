/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/
//Solution1: enumeration, cost too much time
/*
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        sort(nums.begin(),nums.end());
        int cnt=0;
        cnt += select_cand(nums,target);
        return cnt;
    }
    int select_cand(vector<int>& num, int tar){
        if(num.empty())
            return 0;
        if(tar == 0)
            return 0;
        int cnt = 0;
        for(auto it: num){
            if(it < tar)
                cnt += select_cand(num, tar - it);
            else if(it == tar)
                cnt += 1;
        }
        return cnt;
    }
};
*/
//Solution2: use dynamic planning
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
       
        vector<int> dp(target+1);
        dp[0] = 1;
        for(int i=1; i<=target;++i){
            for(auto w:nums){
                if(w <= i) dp[i] += dp[i-w];
            }
        }
        
        return dp[target];
    }
};
