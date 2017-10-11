/*
https://leetcode.com/problems/range-sum-query-mutable/description/

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/
//Use the Binary Indexed Tree
//1. reference : https://leetcode.com/problems/range-sum-query-mutable/discuss/

//Solution 1, use BIT algorithm with 2n space. Test Pass with 86ms
//Solution 2, use BIT algorithm with n space. Test Pass with 122ms
class NumArray {
public:
	NumArray(vector<int> nums) {
        //this->nums = nums;
		bit_vec.resize(nums.size() + 1, 0);
		for (int i = 1; i<bit_vec.size(); ++i) {
			int range = i & (-i);
			int sum = 0;
			for (int j = i; j > i - range; --j) {
				sum += nums[j-1];
			}
			bit_vec[i] = sum;
		}
	}

	void update(int i, int val) {
        int ori_val = _get_val(i);
		int inc = val - ori_val;
        //nums[i] = val;
        int pos = i+1;
        int range = pos & (-pos);
		while (pos < bit_vec.size()) {
			bit_vec[pos] += inc;
			pos += range;
			range = pos & (-pos);
		}
	}

	int sumRange(int i, int j) {
		return (_getSum(j) - _getSum(i - 1));
	}
private:
	vector<int> bit_vec;
    //vector<int> nums;
	int _getSum(int i) {
		int sum = 0;
		i++;
		while (i>0) {
			sum += bit_vec[i];
			i = i - (i & (-i));
		}
		return sum;
	}
	//find the original value by sub all the left childs.
    int _get_val(int i){
        int right = ++i;
        int left = right - (right & -right)/2;
        int val = bit_vec[right];
        while(left < right){
            val -= bit_vec[left];
            left = left + max(1,(left&-left)/2);
        }
        return val;
    }
};