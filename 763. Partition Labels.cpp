// T.C: O(n)
// S.C: O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> lastPos(26, -1);
        vector<int> ans;
        for(int i=0; i<n; i++){
            lastPos[s[i] - 'a'] = i;
        }

        int i=0;
        while(i < n){
            int end = lastPos[s[i]-'a'];
            int j = i;
            while(j < end){
                end = max(end, lastPos[s[j]-'a']);
                j++;
            }
            ans.push_back(j-i+1);
            i = j+1;
        }

        return ans;
    }
};
