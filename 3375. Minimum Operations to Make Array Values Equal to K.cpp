// T.C: O(n)
// S.C: O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            if(nums[i] > k && st.find(nums[i]) == st.end()){
                count++;
            }
            if(nums[i] < k) return -1;
            
            st.insert(nums[i]);
        }

        return count;
    }
};
