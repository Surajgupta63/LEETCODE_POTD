// Approach-1 Brute Force (TLE)
class Solution {
public:
    int digitSum(int num){
        int sum = 1;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int maxValue = -1;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int sum_i = digitSum(nums[i]);
            for(int j=i+1; j<n; j++){
                int sum_j = digitSum(nums[j]); 
                if(sum_i == sum_j){
                    maxValue = max(maxValue, nums[i]+nums[j]);
                }
            }
        }

        return maxValue;
    }
};
