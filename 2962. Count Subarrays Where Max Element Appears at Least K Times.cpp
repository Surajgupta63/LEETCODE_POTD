// T.C: O(n)
// S.C: O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int count = 0;

        int i=0;
        int j=0;
        while(j < n){
            if(nums[j] == maxVal) count++;
            while(i < n && count >= k ){
                if(nums[i] == maxVal) count--;
                ans += n - j;
                i++;
            }
            j++;
        }
        return ans;
    }
};
