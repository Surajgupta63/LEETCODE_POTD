// T.C: O(n)
// S.C: O(n)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int len = 0;
        for(string& word: words){
            string revWord = word;
            swap(revWord[0], revWord[1]);
            if(mp[revWord] > 0){
                len += 4;
                mp[revWord]--;
            }else{
                mp[word]++;
            }
        }

        for(auto& it: mp){
            string word = it.first;
            int    freq = it.second;
            if(word[0] == word[1] && freq > 0){
                len += 2;
                break;
            }
        }

        return len;
    }
};
