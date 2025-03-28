// Approach-1 Using BFS(TLE)
// T.C: O(Queries * O(m*n))
// S.C: O(m*n)
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int BFS(vector<vector<int>>& grid, int val, int m, int n){
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0]= true;
        int points = 0;

        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto [i, j] = q.front();
                q.pop();

                if(grid[i][j] > val) continue;

                points++;
                for(auto dir: directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_] && grid[i_][j_] < val){
                        q.push({i_, j_});
                        visited[i_][j_] = true;
                    }
                }

            }
        }
        return points;
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int Q = queries.size();

        vector<int> ans(Q, 0);
        for(int i=0; i<Q; i++){
            ans[i] = BFS(grid, queries[i], m, n);
        }
        return ans;
    }
};

// Approach-1 Using Pririty_queue(Accepted)
// T.C: O(m*n * lof(m*n)
// S.C: O(m*n)
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int Q = queries.size();

        vector<int> ans(Q, 0);
        vector<pair<int, int>> sortedQ;
        for(int i=0; i<Q; i++){
            sortedQ.push_back({queries[i], i});
        }

        sort(begin(sortedQ), end(sortedQ)); // O(Qlog(Q))
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int points = 0;

        //O( Qlog(Q) + m*n * log(m*n))
        for(int i=0; i<Q; i++){
            int val = sortedQ[i].first;
            int idx = sortedQ[i].second;
            while(!pq.empty() && pq.top()[0] < val){
                int x = pq.top()[1];
                int y = pq.top()[2];
                pq.pop();
                points++;

                for(auto &dir: directions){
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];
                    if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && !visited[x_][y_]){
                        pq.push({grid[x_][y_], x_, y_});
                        visited[x_][y_] = true;
                    }
                }
            }
            ans[idx] = points;
        }

        return ans;
    }
};
