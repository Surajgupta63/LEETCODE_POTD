// Approach Brute Force ~ TLE
// T.C: O(t*length of string)
// S.C: O(length of string)
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1000000007;
        while(t--){
            string temp = "";
            for(int i=0; i<s.length(); i++){
                if(s[i] == 'z'){
                    temp += "ab";
                }
                else{
                    temp += ++s[i];
                }
            }
            s = temp;
        }

        return s.length() % mod;
    }
};

// Approach Optimal
// T.C: O(t*O(26)) ~ O(t)
// S.C: O(26) ~ O(1)
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1000000007;
        vector<int> mp(26, 0);

        for(char& ch: s){
            mp[ch - 'a']++;
        }

        while(t--){
            vector<int> temp(26, 0);
            for(int i=0; i<26; i++){
                char ch = i + 'a';
                int count = mp[i];
                if(ch == 'z'){
                    temp['a' - 'a'] = (temp['a' - 'a'] + count) % MOD; 
                    temp['b' - 'a'] = (temp['b' - 'a'] + count) % MOD; 
                }else{
                    temp[(ch+1) - 'a'] = (temp[(ch+1) - 'a'] + count) % MOD;
                }
            }
            mp = move(temp);
        }

        int totalCount = 0;
        for(int i=0; i<26; i++){
            totalCount = (totalCount + mp[i]) % MOD;
        }
        
        return totalCount;
    }
};
