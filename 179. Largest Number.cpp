/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
//String operation, lamda function
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string s = "";
		if (nums.empty())
			return s;
        vector<string> vec;
        for(auto i:nums){
            vec.push_back(to_string(i));
        }
		sort(vec.begin(), vec.end(), [](const string& s1,const string& s2){return s1+s2 > s2+s1;});
        //string res="";
		for(auto i:vec){
            s += i;
        }
        while(s[0] == '0' && s.size() >= 2)
            s.erase(0,1);
        return s;
	}
	
};