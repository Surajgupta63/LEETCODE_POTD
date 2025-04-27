// T.C: O(n)
// S.C: O(1)
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n-2; i++){
            if(nums[i] + nums[i+2] == nums[i+1]/2.0) count++;
        }

        return count;
    }
};
