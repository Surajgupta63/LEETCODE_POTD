// T.C: O(n^3)
// S.C: O(1)
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int count = 0;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                int cond1 = abs(arr[i] - arr[j]);
                if(cond1 <= a){
                    for(int k=j+1; k<n; k++){
                        int cond2 = abs(arr[j] - arr[k]);
                        int cond3 = abs(arr[i] - arr[k]);
                        if(cond2 <= b && cond3 <= c) count++;
                    }
                }
            }
        }
        return count;
    }
};
