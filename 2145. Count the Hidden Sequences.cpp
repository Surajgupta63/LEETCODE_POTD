// T.C: O(n)
// S.C: O(1)
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int minVal = 0, maxVal = 0, curr = 0;
        for(int &diff: differences){
            curr += diff;
            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);

            if((upper - maxVal) - (lower - minVal) + 1 <= 0){
                return 0;
            }
        }

        return (upper - maxVal) - (lower - minVal) + 1;
    }
};
