// Using BFS
// T.C: O(m*n)
// S.C : O(m*n)
class Solution {
public:
    typedef pair<int, int> P;
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int BFS(vector<vector<int>>& grid, int row, int col){
        queue<P> q;
        q.push({row, col});

        int ans = grid[row][col];
        while(!q.empty()){
            P p = q.front();
            q.pop();

            int i = p.first;
            int j = p.second;

            for(auto &dir : directions){
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0){
                    q.push({i_, j_});
                    ans += grid[i_][j_];
                    grid[i_][j_] = 0;
                }
            }
            grid[i][j] = -1;
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] > 0){
                    ans = max(ans, BFS(grid, i, j));
                }
            }
        }
        return ans;
    }
};
