// Approach-1 Using Stack
// T.C : O(N)
// S.C : O(N)
class Solution {
public:
    string clearDigits(string s) {
        string ans;
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i])){
                st.pop(); // O(1)
            }else{
                st.push(s[i]); // O(1)
            }
        }

        if(st.empty()) return ans;

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};
