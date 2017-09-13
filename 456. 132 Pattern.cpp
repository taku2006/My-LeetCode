/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]

Output: False

Explanation: There is no 132 pattern in the sequence.
Example 2:
Input: [3, 1, 4, 2]

Output: True

Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:
Input: [-1, 3, 2, 0]

Output: True

Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
*/
//Violent Solution. 945ms
/*
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //vector<int> num_item(nums);
        if(nums.empty() || nums.size() < 3){
            return false;
        }
        //bool finded = false;
        vector<int>::iterator pos;
        //vector<int>::iterator left_min_pos;
        //vector<int>::iterator left_max_pos;
        int left_min=nums[0];
        //int right_min=0,right_max=0;
        for(auto pos = nums.begin() + 1 ; pos < nums.end() ; ++pos ){
            if(*pos <= left_min)
                left_min = *pos;
            else{
                for(auto right = pos + 1; right < nums.end(); ++right){
                    if(*right > left_min && *right < *pos)
                        return true;
                }
            }
        }
        return false;
            
    }
};
*/
//Solution 2: O(n)
//refer to 
//https://discuss.leetcode.com/topic/67881/single-pass-c-o-n-space-and-time-solution-8-lines-with-detailed-explanation
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        int max_k = INT_MIN;
        stack<int> s;
        bool max_k_valid = false;
        for(auto i = nums.end()-1;i>=nums.begin();--i){
            if(s.empty()){
                s.push(*i);
                //max_k = *i;
            }
            else if(!max_k_valid) {
                while(!s.empty()){
                    if(s.top() < *i){
                        max_k = s.top();
                        s.pop();
                        //s.push(*i);
                        max_k_valid = true;
                    }
                    else{
                        //s.push(*i);
                        break;
                    }
                }
                s.push(*i);
            }
            else {
                if(*i < max_k)
                    return true;
                else{
                    while(!s.empty()){
                        if(s.top() < *i){
                            max_k = s.top();
                            s.pop();
                            //s.push(*i);
                            max_k_valid = true;
                        }
                        else
                            break;
                    }
                    s.push(*i);
                }
            }
        }
        return false;
    }
};