// T.C : O(n*n)
// S.C : O(n*n);
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq((n*n) + 1, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                freq[grid[i][j]]++;
            }
        }

        vector<int> ans(2);

        for(int i=1; i<=n*n; i++){
            if(freq[i]==0){
                ans[1] = i;
            }
            if(freq[i] > 1){
                ans[0] = i;
            }
        }

        return ans;
    }
};
