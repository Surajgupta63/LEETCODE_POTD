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

//Approach-3 (DSU - Union Find with Path compression)
//T.C : O(n * alpha(n))
//S.C : O(n)
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }else{
            parent[x_parent] = y_parent;
            rank[y_parent] += rank[x_parent];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        parent.resize(V+1);
        rank.resize(V+1, 0);

        for(int i=1; i<=V; i++){
            parent[i] = i;
        }

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int u_parent = find(u);
            int v_parent = find(v);

            if(u_parent == v_parent) return {u, v};

            Union(u, v);
        }
        return {};
    }
};
