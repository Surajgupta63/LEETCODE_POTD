// Using DFS
// T.C : O(V+E)
// S.C : O(V)
class Solution {
public:
    bool isCycleDFS(vector<vector<int>>& graph, int u, vector<bool> &visited, vector<bool> &inRec){
        visited[u] = true;
        inRec[u] = true;

        for(auto &v : graph[u]){
            if(!visited[v] && isCycleDFS(graph, v, visited, inRec)) return true;
            else if(inRec[v]) return true;
        }
        inRec[u] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, false);
        vector<bool> inRec(V, false);

        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleDFS(graph, i, visited, inRec)){
                continue;
            }
        }

        vector<int> ans;
        for(int i=0; i<V; i++){
            if(!inRec[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Using BFS Kahn's Algorithm (Topological Sort Method)
// T.C : O(V+E)
// S.C : O(V) + O(V*E)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for(int u=0; u<V; u++){
            for(int &v : graph[u]){
                adj[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<bool> isSafeNode(V, false);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            isSafeNode[u] = true;

            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }

        }
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(isSafeNode[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
