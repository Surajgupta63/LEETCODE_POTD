// Approach -1 Brute Force
// T.C: O(n^2)
// S.C: O(1)
class Solution {
public:
    bool isSymmetric(string& s){
        int i = 0;
        int j = s.length()-1;

        int sum1 = 0;
        int sum2 = 0;
        while(i < j){
            sum1 += (int) s[i];
            sum2 += (int) s[j];
            i++;
            j--;
        }

        return sum1 == sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low; i<=high; i++){
            string s = to_string(i);
            if(s.length() % 2 != 0) continue;
            if(isSymmetric(s)) count++;
        }

        return count;
    }
};
