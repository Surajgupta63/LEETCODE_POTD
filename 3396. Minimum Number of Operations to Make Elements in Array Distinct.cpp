// Approach-1 
// T.C: O(n^2)
// S.C: O(n)
class Solution {
public:
    bool isDistinct(vector<int>& nums, int s, int n){
        unordered_set<int> st;
        for(int i=s; i<n; i++){
            if(st.find(nums[i]) != st.end()){
                return false;
            }
            st.insert(nums[i]);
        }

        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i = i+3){
            if(isDistinct(nums, i, n)){
                break;
            }
            count++;
        }
        
        return count;
    }
};
