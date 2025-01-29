//Approach-1 - Using DFS
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    vector<int> ans;
    bool DFS(unordered_map<int, vector<int>>& adj, int u, int v, vector<bool> &visited){
        visited[u] = true;

        if(u == v) return true;
        for(int &nbr : adj[u]){
            if(visited[nbr]) continue;
            
            if(DFS(adj, nbr, v, visited)) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            vector<bool> visited(V, false);
            if(adj.find(u) != adj.end() && adj.find(v) != adj.end() && DFS(adj, u, v, visited)){
                return {u, v};
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return {};
    }
};
