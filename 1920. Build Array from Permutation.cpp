// T.C: O(n)
// S.C: O(1) 
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = nums[nums[i]];
        }

        return ans;
    }
};
