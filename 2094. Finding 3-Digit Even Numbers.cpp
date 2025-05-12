// T.C: O(n^3 + klog(k))
// S.C: O(k)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size(); 
        unordered_set<int> st;
        vector<string> permu;
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
