// Approach - 1 my approach
// T.C: O(n);
// S.C: O(n)
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        unordered_map<int, int> mp;
        int topmax = -1;
        int topnum = -1;
        for(int& num: tops){
            mp[num]++;
            if(mp[num] > topmax){
                topmax = mp[num];
                topnum = num;
            }
        }
        mp.clear();
        int bottommax = -1;
        int bottomnum = -1;
        for(int& num: bottoms){
            mp[num]++;
            if(mp[num] > bottommax){
                bottommax = mp[num];
                bottomnum = num;
            }
        }

        int count = 0;
        int ans = 0;
        if(topnum == bottomnum && topmax >= bottommax){
            for(int i=0; i<n; i++){
                if(bottoms[i] == topnum && tops[i] != topnum){
                    count++;
                }
            }

            ans = (topmax + count) == n ? count : -1;
        }else{
            for(int i=0; i<n; i++){
                if(tops[i] == bottomnum && bottoms[i] != bottomnum){
                    count++;
                }
            }
            ans = (bottommax + count) == n ? count : -1;
        }

        cout<<bottomnum<<" " <<count<<endl;

        return ans;
    }
};

// Approach - 2 by MIK
// T.C: O(6*n);
// S.C: O(1)
class Solution {
public:

    int findSwap(vector<int>& tops, vector<int>& bottoms, int num, int n){
        int topswap = 0;
        int bottomswap = 0;

        for(int i=0; i<n; i++){
            if(tops[i] != num && bottoms[i] != num) return -1;
            else if(tops[i] != num) topswap++;
            else if(bottoms[i] != num) bottomswap++;
        }

        return min(topswap, bottomswap);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = INT_MAX;

        for(int i=1; i<=6; i++){
            int swap = findSwap(tops, bottoms, i, n);
            if(swap != -1) ans = min(swap, ans);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
