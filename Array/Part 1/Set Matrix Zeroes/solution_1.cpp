class Solution {
public:
    void findMarkedIndex(vector<vector<int>> &matrix, unordered_map<int,bool> &markedRow,unordered_map<int,bool> &markedCol, int row, int col){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    markedRow[i] = true;
                    markedCol[j] = true;
                }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,bool> markedRow;
        unordered_map<int,bool> markedCol;
        int row = matrix.size();
        int col = matrix[0].size();
        findMarkedIndex(matrix,markedRow,markedCol,row,col);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(markedRow[i] || markedCol[j])
                    matrix[i][j] = 0;
            }
        }
    }
}; 
