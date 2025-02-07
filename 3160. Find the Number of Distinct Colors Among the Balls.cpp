// Using Map
// T.C : O(N)
// S.C : O(N)
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_map<int, int> colorCount;

        vector<int> ans;

        for(int i=0; i<queries.size(); i++){
            int x = queries[i][0];
            int y = queries[i][1];

            if(ballColor.count(x)){
                int prevColor = ballColor[x];
                colorCount[prevColor]--;

                if(colorCount[prevColor] == 0){
                    colorCount.erase(prevColor);
                }
            }

            ballColor[x] = y;
            colorCount[y]++;
            
            ans.push_back(colorCount.size());
        }
        return ans;
    }
};
