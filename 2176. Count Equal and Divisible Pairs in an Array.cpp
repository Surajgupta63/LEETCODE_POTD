// T.C: O(n^2)
// S.C: O(1)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] == nums[j] && (i*j) % k == 0){
                    count++;
                }
            }
        }

        return count;
    }
};

// T.C: O(n * (log(k) + sqrt(k)))
// S.C: O(n)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }

        unordered_set<int> factorsOfK;
        for(int f=1; f*f<=k; f++){ // O(sqrt(k))
            if(k % f == 0){
                factorsOfK.insert(f);
                factorsOfK.insert(k/f);
            }
        }

        for(auto& [num, indices]: mp){
            unordered_map<int, int> prevFactor;
            for(int i: indices){
                int GCD = gcd(i, k); // O(log(k))
                int j = k/GCD;
                count += prevFactor[j];

                for(int f: factorsOfK){ // O(sqrt(k))
                    if(i % f == 0){
                        prevFactor[f]++; 
                    }
                }
            }
        }

        return count;
    }
};
