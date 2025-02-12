// Approach-1 Brute Force (TLE)
// T.C : O(N^2)
// S.C : O(1)
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

// Approach-2 Better Approach (Passed)
// T.C : O(N*K) // K is size of number to calculate sum
// S.C : O(N)
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

        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            int sum = digitSum(nums[i]);
            if(mp[sum] != 0){
                maxValue = max(maxValue, mp[sum] + nums[i]);
            }
            
            mp[sum] = max(mp[sum], nums[i]);
        }

        return maxValue;
    }
};

// Approach-3 Brute Force (TLE)
// T.C : O(N^2)
// S.C : O(1)
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

        vector<pair<int, int>> vec;

        for(int i=0; i<n; i++){
            int sum = digitSum(nums[i]);
            vec.push_back({sum, nums[i]});
        }

        sort(begin(vec), end(vec));

        for(int i=1; i<n; i++){
            if(vec[i-1].first == vec[i].first){
                maxValue = max(maxValue, vec[i-1].second + vec[i].second);
            }
        }

        return maxValue;
    }
};

// Approach-4 Best Approach
// T.C : O(Nlog(N))
// S.C : O(N)
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

        int arrSum[83] = {0};

        for(int i=0; i<n; i++){
            int sum = digitSum(nums[i]);
            if(arrSum[sum] > 0){
                maxValue = max(maxValue, arrSum[sum] + nums[i]);
            }
            
            arrSum[sum] = max(arrSum[sum], nums[i]);
        }

        return maxValue;
    }
};
