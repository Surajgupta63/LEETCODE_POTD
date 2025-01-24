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
