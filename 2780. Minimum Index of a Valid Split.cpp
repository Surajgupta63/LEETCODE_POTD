// APproach-1
// T.C: O(n)
// S.C: O(n)
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> leftMap;
        unordered_map<int, int> rightMap;

        for(int &num: nums){
            rightMap[num]++;
        }

        for(int i=0; i<n; i++){
            int num = nums[i];

            leftMap[num]++;
            rightMap[num]--;

            int n1 = i+1;
            int n2 = n-i-1;

            if(leftMap[num]*2 > n1 && rightMap[num]*2 > n2){
                return i;
            }
        }

        return -1;
    }
};
