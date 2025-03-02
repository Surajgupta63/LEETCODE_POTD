// T.C : O(nlog(n))
// S.C : O(n)
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> mp;

        for(auto& nums : nums1){
            int id = nums[0];
            int val = nums[1];

            mp[id] = val;
        }
        for(auto& nums : nums2){
            int id = nums[0];
            int val = nums[1];

            mp[id] += val;
        }

        vector<vector<int>> ans;

        for(auto &it : mp){
            int id = it.first;
            int val = it.second;

            ans.push_back({it.first, it.second});
        }

        sort(begin(ans), end(ans));

        return ans;

    }
};
