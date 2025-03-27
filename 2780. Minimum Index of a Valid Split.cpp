// Approach-1
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

// Approach-2 (Majority Element -> Boore More Concept)
// T.C: O(n)
// S.C: O(1)
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int maj = -1;
        int count = 0;
        for(int &num: nums){
            if(count == 0){
                maj = num;
                count = 1;
            }else if(num == maj){
                count++;
            }else{
                count--;
            }
        }

        int majCount = 0;
        for(int &num: nums){
            if(num == maj){
                majCount++;
            }
        }

        count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == maj){
                count++;
            }

            int remMajCount = majCount - count;
            int n1 = i+1;
            int n2 = n-i-1;

            if(count*2 > n1 && remMajCount*2 > n2) return i;
        }

        return -1;
    }
};
