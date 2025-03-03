//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lessthan;
        vector<int> greaterthan;
        vector<int> equal;

        for(int num : nums){
            if(num < pivot){
                lessthan.push_back(num);
            }
            else if(num > pivot){
                greaterthan.push_back(num);
            }else{
                equal.push_back(num);
            }
        }

        int i = 0;

        for(int num : lessthan){
            nums[i] = num;
            i++;
        }
        for(int num : equal){
            nums[i] = num;
            i++;
        }
        for(int num : greaterthan){
            nums[i] = num;
            i++;
        }

        return nums;
    }
};
