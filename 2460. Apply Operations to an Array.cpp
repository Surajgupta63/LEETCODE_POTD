// T.C : O(n) 
// S.C : O(1)
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        int i=0, j=0;

        vector<int> ans;

        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                ans.push_back(nums[i]);
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};
