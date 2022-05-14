//2nd solution (3 solutions exists)

//TC= O((m*n)*(m+n))and SC=O(1)
class Solution {
public:
    int value=-1000000001;
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> columns,rows;
        int row=matrix.size(),col=matrix[0].size();
        // traversing the matrix and at the same time updating the entire row and column with value.
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    for(int k=0;k<col;k++)
                    {
                        if(matrix[i][k]!=0)
                        {
                            matrix[i][k]=value;
                        }
                    }
                        
                    for(int k=0;k<row;k++)
                    {
                        if(matrix[k][j]!=0)
                            matrix[k][j]=value;
                    }
                        
                }
            }
        }
        
        //Again we traverse the matrix and check whether any cell belong to that particular row or column in which element with value 0 is present.(by using set rows and columns)
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==value)
                    matrix[i][j]=0;
            }
        }
    }
};
