// T.C: O(n)
// S.C: O(n)
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long goodCount = 0;
        long long pairs = 0;
        int n = nums.size();
        int i=0, j=0;

        while(j<n){
            pairs += mp[nums[j]];
            mp[nums[j]]++;
            while(pairs >= k){
                goodCount += n-j;
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }
            j++;
        }

        return goodCount;
    }
};
