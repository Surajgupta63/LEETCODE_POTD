// T.C: O(n^2)
// S.C: O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> prevIdx(n, -1);
        int maxLen = 1;
        int maxIdx = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prevIdx[i] = j;
                    }
                    if(dp[i] > maxLen){
                        maxIdx = i;
                        maxLen = dp[i];
                    }
                }
            }
        }

        vector<int> result;
        while(maxIdx != -1){
            result.push_back(nums[maxIdx]);
            maxIdx = prevIdx[maxIdx];
        }

        return result;

    }
};
