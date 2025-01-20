// BruteForce --GET TLE--
class Solution {
public:

    int isRowPainted(int row, vector<vector<int>>& mat){
        for(int col = 0; col<mat[0].size(); col++){
            if(mat[row][col] > 0) return false;
        }

        return true;
    }
    int isColPainted(int col, vector<vector<int>>& mat){
        for(int row = 0; row<mat.size(); row++){
            if(mat[row][col] > 0) return false;
        }

        return true;
    }

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, pair<int, int>> mp;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        for(int i=0; i<arr.size(); i++){
            int val = arr[i];
            auto [row, col] = mp[val];
            mat[row][col] = -1;

            if(isRowPainted(row, mat) || isColPainted(col, mat)) return i;
        }

        return -1;
    }
};
