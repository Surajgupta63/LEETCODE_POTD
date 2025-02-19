//// Approach Sliding Window
// T.C : O(2n)
// S.C : O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0, j=0;
        int zeros = 0;
        int maxSize1 = 0;

        while(j < n){
            if(nums[j] == 0) zeros++;
            while(zeros > k){
                if(nums[i] == 0) zeros--;
                i++;
            }
            if(zeros <= k){
                maxSize1 = max(maxSize1, j-i+1);
            }
            j++;
        }
        return maxSize1;
    }
};
