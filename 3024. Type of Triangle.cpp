// T.C: O(3)
// S.C: O(3)
class Solution {
public:
    string triangleType(vector<int>& nums) {
        if((nums[0] + nums[1]) <= nums[2] || (nums[0] + nums[2]) <= nums[1] || (nums[2] + nums[1]) <= nums[0]){
            return "none";
        }

        unordered_map<int, int> mp;
        for(int& num: nums){
            mp[num]++;
        }


        if(mp.size() == 3){
            return "scalene";
        }
        else if(mp.size() == 2){
            return "isosceles";
        }

        return "equilateral";
    }
};

// T.C: O(1)
// S.C: O(1)
class Solution {
public:
    string triangleType(vector<int>& nums) {
        if((nums[0] + nums[1]) <= nums[2] || (nums[0] + nums[2]) <= nums[1] || (nums[2] + nums[1]) <= nums[0]){
            return "none";
        }

        if(nums[0] == nums[1] && nums[1] == nums[2]){
            return "equilateral";
        }
        else if(nums[0] != nums[1] && nums[1] != nums[2] && nums[0] != nums[2]){
            return "scalene";
        }

        return "isosceles";
    }
};
