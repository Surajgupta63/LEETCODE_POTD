// Approach Using Stack
// T.C = O(N*K)
// S.C = O(N)
class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;

        for(int i=0; i<s.length(); i++){
            st.push(s[i]);
            if(st.top() == part[part.length()-1]){
                int size = part.length();
                string temp = "";
                while(size > 0 && !st.empty() && st.top() == part[size-1]){
                    temp += st.top();
                    st.pop();
                    size--;
                }

                if(size != 0){
                    for(int j=temp.length()-1; j>=0; j--){
                        st.push(temp[j]);
                    }
                }
            }
        }

        if(st.empty()) return "";

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};
