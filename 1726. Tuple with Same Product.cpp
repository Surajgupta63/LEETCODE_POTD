
class Solution {
public:
    
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        if (n < 4)
            return 0;
        unordered_map<long long, int> mp; // it will store the  count of multiplication
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                long long mul = nums[i] * nums[j];
                mp[mul]++;
            }
        }
        long long sum = 0; // it will store the number of pair(combination ) are possible..
        for (auto& num : mp) {
            if (num.second > 1) { 
                sum +=  (num.second)*(num.second - 1) / 2;
            }
        }
        if (sum == 0)
            return 0;
        return 8 * sum;  // each pair can arrange by 8 method 
    }
};
