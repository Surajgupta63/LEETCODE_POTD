// T.C: O(n)
// S.C: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        long long maxi = 0;
        long long maxDiff = 0;

        for(int i=0; i<n; i++){
            ans = max(ans, maxDiff * nums[i]);
            maxDiff = max(maxDiff, maxi - nums[i]);
            maxi = max(maxi, (long long)nums[i]);
        }

        return ans;
    }
};
