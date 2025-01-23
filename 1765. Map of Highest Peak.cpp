// Using Multi-Source BFS
// T.C : O(m*n) + O(m*n)
// S.C : O(m*n)
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> heightMap(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j] == 1){
                    heightMap[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;

                for(auto &dir : directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && heightMap[new_i][new_j] == -1){
                        heightMap[new_i][new_j] = heightMap[i][j] + 1;
                        q.push({new_i, new_j});
                    }
                }

            }
        }
        return heightMap;
    }
};
