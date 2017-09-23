/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
//Solution1: 226ms
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> mp;
        int sz = words.size();
        int words_len = words[0].size();
        vector<int> result_vec;
        if(sz == 0)
            return result_vec;
        for(auto w:words){
            int indx=0;
            mp[w]++;
                
        }
        int num=0;
        for(int left=0; left<s.size() - sz*words_len+1;++left){
            map<string,int> mp_copy = mp;
            for(num=0; num<sz; ++num){
                string tmp_s = s.substr(left+num*words_len,words_len);
                if(mp_copy[tmp_s] == 0)
                    break;
                else
                    --mp_copy[tmp_s];
            }
            if(num == sz)
                result_vec.push_back(left);
        }
        return result_vec;
    }
};

//Solution2:
