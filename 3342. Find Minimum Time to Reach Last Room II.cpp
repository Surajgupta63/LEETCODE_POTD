// Approach using Dijkstra' Algo
// T.C: O(n*mlog(n*m)
// S.C: O(n*m)
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        typedef pair<int, pair<int, int>> P;
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int size = pq.size();

            while(size--){
                int t = pq.top().first;
                int i = pq.top().second.first;
                int j = pq.top().second.second;
                pq.pop();

                if(i == n-1 && j == m-1){
                    return t;
                }

                for(auto& dir: directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < m){
                        int ct = (i_ + j_) % 2 == 0 ? 2: 1;
                        int mt = ct + max(t, moveTime[i_][j_]);
                        if(mt < result[i_][j_]){
                            result[i_][j_] = mt;
                            pq.push({mt, {i_, j_}});
                        }
                    }
                }
            }
        }

        return result[n-1][m-1];
    }
};
