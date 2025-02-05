// T.C : O(N)
// S.C : O(1)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        
        int i = 0;
        int n = s1.length();
    
        vector<int> idx;
        while(i < n){
            if(idx.size() > 2) return false;

            if(s1[i] != s2[i]){
                idx.push_back(i);
            }
            i++;
        }

        if(idx.size() == 2) swap(s1[idx[0]], s1[idx[1]]);
        else return false;

        return s1 == s2 ? true : false;
    }
};
