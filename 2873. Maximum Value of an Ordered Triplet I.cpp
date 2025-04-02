// Approach-1 Brute Force
// T.C: O(n^3)
// S.C: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    long long val = (long long)(nums[i] - nums[j]) * nums[k];
                    ans = max(ans, val);
                }
            }
        }
        return ans;
    }
};

// Approach-2 Better
// T.C: O(n)
// S.C: O(n)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], nums[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], nums[i+1]);
        }

        for(int i=0; i<n; i++){
            long long val = (long long)(leftMax[i] - nums[i]) * rightMax[i];
            ans = max(ans, val);
        }
        return ans;
    }
};

// Approach-3 Optimal
// T.C: O(n)
// S.C: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        long long maxDiff = 0;
        long long maxi = 0;

        for(int i=0; i<n; i++){
            ans = max(ans, maxDiff * nums[i]);
            maxDiff = max(maxDiff, maxi - nums[i]);
            maxi = max(maxi, (long long)nums[i]); 
        }
        return ans;
    }
};
