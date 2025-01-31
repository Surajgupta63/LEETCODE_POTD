//Approach-1 Brute Force
// T.C : O(n^4) ---> TLE
// S.C : O(n^2)
class Solution {
public:
    int n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited){
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]) return 0;

        visited[i][j] = true;
        int island = 1;

        for(auto &dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            island += DFS(grid, i_, j_, visited);
        }
        return island;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int maxArea = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    grid[i][j] = 1;

                    vector<vector<bool>> visited(n, vector<bool>(n, false));
                    int currMaxArea = 0;
                    for(int a=0; a<n; a++){
                        for(int b=0; b<n; b++){
                            if(grid[a][b] == 1 && !visited[a][b]){
                                currMaxArea = max(currMaxArea, DFS(grid, a, b, visited));
                            }
                        }
                    }
                    grid[i][j] = 0;
                    maxArea = max(maxArea, currMaxArea);
                }
            }
        }
        return maxArea == 0 ? n*n : maxArea;
    }
};
