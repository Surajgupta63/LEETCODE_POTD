// T.C: O(n*m)
// S.C: O(number of zeros)
class Solution {
public:
    void setMat(vector<vector<int>>& matrix, int i, int j, int m, int n){
        // set row to 0
        for(int col = 0; col<n; col++){
            matrix[i][col] = 0;
        }
        // set col to 0
        for(int row = 0; row<m; row++){
            matrix[row][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0) q.push({i, j});
            }
        }

        while(!q.empty()){
            auto P = q.front();
            q.pop();
            int i = P.first;
            int j = P.second;
            setMat(matrix, i, j, m, n);
        }

    }
};
