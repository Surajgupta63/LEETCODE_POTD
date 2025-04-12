// T.C: O(10^d * nlog(n))
// S.C: O(10^d * n) for set
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;
        long long ans = 0;
        int d = (n+1)/2;
        int start = pow(10, d-1);
        int end = pow(10, d) - 1;

        for(int num=start; num<=end; num++){
            string leftHalf = to_string(num);
            string full = "";
            string rightHalf = "";
            if(n % 2 == 0){
                rightHalf = leftHalf;
            }else{
                rightHalf = leftHalf.substr(0, d-1);
            }

            reverse(rightHalf.begin(), rightHalf.end());
            full = leftHalf + rightHalf;

            long long number = stoll(full);
            if(number % k != 0) continue;

            sort(full.begin(), full.end());
            st.insert(full);
        }

        vector<int> factorial(11, 1);
        for(int i=1; i<11; i++){
            factorial[i] = factorial[i-1] * i;
        }

        for(const string& s: st){
            vector<int> freq(10, 0);
            for(const char& ch: s){
                freq[ch - '0']++;
            }

            int totalDigits = s.length();
            int zeroDigits = freq[0];
            int nonZeroDigits = totalDigits - zeroDigits;
            
            long long permutation = nonZeroDigits * factorial[totalDigits-1];
            for(int i=0; i<10; i++){
                permutation /= factorial[freq[i]];
            }

            ans += permutation;
        }

        return ans;
    }
};
