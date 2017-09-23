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

//Solution2: use shift_window, 23ms for total 169 tests
//modifications: 
//1.use map to replace unordered_map will get 16ms result;
//2. user map , and another copy map to replace the restore the whole map operation, will get 19ms;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result_vec;
        if(s.empty() || words.empty())
            return result_vec;
        unordered_map<string,int> mp;
        int sz = words.size();
        int words_len = words[0].size();
        int total_len = s.size();
        //build the hash table
        for(auto w:words){
            int indx=0;
            mp[w]++;       
        }
        int left,right;
        string tmp_s;
        for(int i=0; i< words_len;++i){
            left = right = i;
            while(right + words_len - 1 < total_len && left + sz*words_len - 1 < total_len){
                tmp_s = s.substr(right,words_len);
                auto indx = mp.find(tmp_s);
                if(indx == mp.end() ){//not valid word
                    //restore the mp count
                    for(int i = left;i<right;i= i+words_len){
                        mp[s.substr(i,words_len)]++;
                    }
                    left = right + words_len;
                    right = right + words_len;
                }
                else{
                    //valid word but used
                    if(indx -> second == 0){
                        //need to find the duplicate word and relocate the window
                        string shift_word;
                        while(left < right){
                            shift_word = s.substr(left,words_len);
                            left = left + words_len;
                            if(tmp_s.compare(shift_word) == 0) break;
                            mp[shift_word]++;
                        }
                        right = right + words_len;
                    }
                    else{
                    //valid word and not used
                        --mp[tmp_s];
                        right = right + words_len;
                    }
                }
                if(right == left + sz*words_len){//find the valid window
                    result_vec.push_back(left);
                    mp[s.substr(left,words_len)]++;
                    left = left + words_len;
                }
            }
            //restore the whole map
            while(left < right){
                mp[s.substr(left,words_len)]++;
                left = left + words_len;
            }
        }
        return result_vec;
    }
};