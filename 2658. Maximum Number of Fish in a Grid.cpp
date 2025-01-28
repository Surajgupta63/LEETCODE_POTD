// Approach-1 Using (BFS)
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

// Approach-2 Using (DFS)
// T.C: O(m*n)
// S.C : O(m*n)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int DFS(vector<vector<int>>& grid, int row, int col){
        int ans = grid[row][col];
        grid[row][col] = 0;

        for(auto &dir : directions){
            int row_ = row + dir[0];
            int col_ = col + dir[1];
            if(row_ >= 0 && row_ < m && col_ >= 0 && col_ < n && grid[row_][col_] > 0){
                ans += DFS(grid, row_, col_);
            } 
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        // O(m*n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] > 0){
                    ans = max(ans, DFS(grid, i, j));
                }
            }
        }
        return ans;
    }
};

// Approach-3 (Using DSU)
// T.C : O(m*n * alpha(m*n))
// S.C : O(m*n)
class Solution {
public:
    vector<int> parent;
    vector<int> fishSize;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;

        if(fishSize[x_parent] > fishSize[y_parent]){
            parent[y_parent] = x_parent;
            fishSize[x_parent] += fishSize[y_parent];
        }else{
            parent[x_parent] = y_parent;
            fishSize[y_parent] += fishSize[x_parent];
        }
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        parent.resize(m*n);
        fishSize.resize(m*n, 0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int idx = i * n + j;
                parent[idx] = idx;
                fishSize[idx] = grid[i][j];
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] > 0){
                    int parent_idx = i * n + j;
                    for(auto &dir : directions){
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0){
                            int nbr_idx = i_ * n + j_;
                            Union(parent_idx, nbr_idx);
                        }
                    }
                }
            }
        }
        return *max_element(fishSize.begin(), fishSize.end());
    }
};
