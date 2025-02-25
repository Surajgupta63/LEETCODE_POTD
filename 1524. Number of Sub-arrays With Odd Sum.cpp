// Aproach-1 Using Prefix Sum
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixSum(n);

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            prefixSum[i] = sum;
        }

        int even = 1;
        int odd = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            if(prefixSum[i] % 2 == 0){
                even++;
                ans = (ans + odd) % MOD;
            }
            else if(prefixSum[i] % 2 != 0){
                odd++;
                ans = (ans + even) % MOD;
            }
        }

        return ans;
    }
};
