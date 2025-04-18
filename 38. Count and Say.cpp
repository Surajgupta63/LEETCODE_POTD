// T.C: O(N)
// S.C: O(1)
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string say = countAndSay(n-1);

        string ans = "";
        int m = say.length();
        for(int i=0; i<m; i++){
            int count = 1;
            char ch = say[i];
            while(i < m-1 && say[i] == say[i+1]){
                count++;
                i++;
            }

            ans += to_string(count) + ch;
        }
        
        return ans;
    }
};
