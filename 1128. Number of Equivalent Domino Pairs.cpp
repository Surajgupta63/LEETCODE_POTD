// T.C: O(n)
// S.C: O(n)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        map<pair<int, int>, int> mp;
        int pairs = 0;

        for(int i=0; i<n; i++){
            if(dominoes[i][0] > dominoes[i][1]) swap(dominoes[i][0], dominoes[i][1]);
            pairs += mp[{dominoes[i][0], dominoes[i][1]}];
            mp[{dominoes[i][0], dominoes[i][1]}]++;
        }

        return pairs;
    }
};

// T.C: O(n)
// S.C: O(100)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        vector<int> freq(100, 0);
        int pairs = 0;
        
        for(int i=0; i<n; i++){
            if(dominoes[i][0] > dominoes[i][1]) swap(dominoes[i][0], dominoes[i][1]);
            int num = dominoes[i][0] * 10 + dominoes[i][1];
            pairs += freq[num];
            freq[num]++;
        }

        return pairs;
    }
};
