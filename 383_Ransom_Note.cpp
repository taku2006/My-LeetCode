/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

//Solution 1
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.empty())
            return true;
        if(magazine.empty() && !ransomNote.empty()){
            return false;
        }
        string mag_tmp(magazine);
        size_t loc; 
        for(string::iterator it=ransomNote.begin(); it != ransomNote.end(); ++it){
            loc = mag_tmp.find_first_of(*it);
            if(loc == string::npos){
                return false;
            }
            mag_tmp = mag_tmp.erase(loc,1);
        }
        return true;
    }
};