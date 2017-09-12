/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

//Solution 1: normal 
class Solution {
public:
    string reverseWords(string s) {
        string rev_s(s);
        if(s.empty())
            return rev_s;
        std::size_t left = 0;
        std::size_t right;
        right = rev_s.find(" ",left);
        while(right != string::npos){
            reverse(rev_s.begin()+left,rev_s.begin()+right);
            left = right + 1;
            right = rev_s.find(" ",left);
        }
        reverse(rev_s.begin()+left,rev_s.end());
        return rev_s;
    }
};

//Solution 2: use istream
class Solution {
public:
    string reverseWords(string s) {
        string res="",tmp="";
        istringstream in(s);
        while(in >> tmp){
            reverse(tmp.begin(),tmp.end());
            res += tmp + " ";
        }
        res.pop_back();
        return res;
    }
};