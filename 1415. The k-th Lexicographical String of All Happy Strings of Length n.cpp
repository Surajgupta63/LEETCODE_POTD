//// Approach-1 Backtracking
// T.C : O(n*2^n)
// S.C : O(n*2^n)
class Solution {
public:
    void solve(string& curr, int n, vector<string>& ans){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        for(char ch ='a'; ch<='c'; ch++){
            if(!curr.empty() && curr.back() == ch) continue;

            curr.push_back(ch);  // DO
            solve(curr, n, ans); // Explore
            curr.pop_back();     // Undo
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> ans;

        solve(curr, n, ans);

        if(ans.size() < k) return "";

        return ans[k-1];
    }
};

//// Approach-2 Backtracking
// T.C : O(n*2^n)
// S.C : O(n) // Space Optimized
class Solution {
public:
    void solve(string& curr, int& n, string& ans, int& count, int& k){
        if(curr.size() == n){
            count++;
            if(count == k) ans = curr;
            return;
        }

        for(char ch ='a'; ch<='c'; ch++){
            if(!curr.empty() && curr.back() == ch) continue;

            curr.push_back(ch);  // DO
            solve(curr, n, ans, count, k); // Explore
            curr.pop_back();     // Undo
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        string ans = "";
        int count = 0;

        solve(curr, n, ans, count, k);

        return ans;
    }
};
