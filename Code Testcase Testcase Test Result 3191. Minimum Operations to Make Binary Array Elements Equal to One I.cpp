//
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int flipCount = 0;
        vector<bool> flipIndex(n, false);
        int ans = 0;

        for(int i=0; i<n; i++){
            if(i >= 3 && flipIndex[i-3] == true){
                flipCount--;
            }

            if(flipCount % 2 == nums[i]){
                if(i + 3 > n) return -1;
                flipCount++;
                flipIndex[i] = true;
                ans++;
            }
        }

        return ans;
    }
};
