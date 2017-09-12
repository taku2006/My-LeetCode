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

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int sz = nums.size();
        int* can_num = new int[sz];
        for(int i=0; i<sz;++i){
            can_num[i] = 0;
        }
        sort(nums.begin(),nums.end());
        int cnt=0;
        cnt += select_cand(nums,nums.size(),target,can_num,nums.size());
        return cnt;
    }
    int select_cand(vector<int>& num, int right,int tar,int* can_num,int len){
        if(num.empty())
            return 0;
        int cnt = 0;
        
        if(right == 0 || tar < *(num.begin())){//end the recursive involve
            return 0;
        }
        
        int can_value = num[right-1];
        int div = tar/can_value;
        int rem = tar%can_value;
        int tar_tmp = tar;
        int div_cnt = 0;
        while(div_cnt <= div){
            tar_tmp = tar - div_cnt * can_value;
            can_num[right - 1] = div_cnt;
            if(tar_tmp == 0){
                cnt += calc_num(can_num,len);
                return cnt;
            }//the last combinations
                
            cnt += select_cand(num, right-1,tar_tmp, can_num,len);
            //--div;
            ++div_cnt;
        }
        
        return cnt;
    }
    int calc_num(int* can_num,int len){
        int total=0;
        int dividend=1;
        for(int i=0 ; i<len ; ++i){
            total += can_num[i];
            dividend *= cal_factorial(can_num[i]);
        }
        return cal_factorial(total)/dividend;
    }
    int cal_factorial(int num){
        int res=1;
        if(num == 0)
            return 1;
        for(int i=1;i<=num;++i){
            res = res * i;
        }
        return res;
    }
          
};
