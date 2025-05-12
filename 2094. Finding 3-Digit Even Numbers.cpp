// T.C: O(n^3 + klog(k))
// S.C: O(k)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size(); 
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i==j || k == j || i==k) continue;
                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(num >= 100 && num % 2 == 0){
                        st.insert(num);
                    }
                }
            }
        }

        vector<int> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());

        return ans;
    }
};

// T.C: O(10*9*8) ~ O(1)
// S.C: O(10) ~ O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size(); 
        vector<int> ans;
        vector<int> freq(10, 0);
        for(int& digit: digits){
            freq[digit]++;
        }

        for(int i=1; i<=9; i++){
            if(freq[i] == 0) continue;
            freq[i]--;
            for(int j=0; j<=9; j++){
                if(freq[j] == 0) continue;
                freq[j]--;
                for(int k=0; k<=8; k=k+2){
                    if(freq[k] == 0) continue;
                    freq[k]--;
                    int num = i*100 + j*10 + k;
                    ans.push_back(num);
                    freq[k]++;
                }
                freq[j]++;
            }
            freq[i]++;
        }

        return ans;
    }
};
