//Approach - 1 (Brute Force TLE)
//T.C : O((m*n) * s*(m+n)) , where s = arr.size() which is (m*n)
//S.C : O(m*n)
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

//Approach - 2 (Better Approach)
//T.C : O(m*n)
//S.C : O((m*n) + m + n)
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, pair<int, int>> mp;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        for(int i=0; i<arr.size(); i++){
            int val = arr[i];
            auto [row, col] = mp[val];
            
            rowCount[row]++;
            colCount[col]++;

            if(rowCount[row] == n || colCount[col] == m) return i;
        }

        return -1;
    }
};

//Approach - 3 (Best Approach)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]] = i;
        }

        int minInd = INT_MAX;
        for(int i=0; i<m; i++){
            int maxInd = INT_MIN;
            for(int j=0; j<n; j++){
                maxInd = max(maxInd, mp[mat[i][j]]);
            }
            minInd = min(minInd, maxInd);
        }
        for(int i=0; i<n; i++){
            int maxInd = INT_MIN;
            for(int j=0; j<m; j++){
                maxInd = max(maxInd, mp[mat[j][i]]);
            }
            minInd = min(minInd, maxInd);
        }

        return minInd;
    }
};
