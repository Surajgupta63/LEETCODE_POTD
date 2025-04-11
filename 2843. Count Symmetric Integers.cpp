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

// Approach -2 Optimal
// T.C: O(n)
// S.C: O(1)
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int i=low; i<= high; i++){
            if(i >= 10 && i <= 99 && i % 11 == 0) count++;
            else if(i >= 1000 && i <= 9999){
                int d1 = (i/1000);
                int d2 = (i/100) % 10;
                int d3 = (i/10) % 10;
                int d4 = i % 10;

                if(d1 + d2 == d3 + d4) count++;
            }
        }

        return count;
    }
};
