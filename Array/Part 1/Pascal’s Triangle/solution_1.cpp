//we need to insert 1 at the begining and also at the end.
//And for the remaining elements (except 1st and last element) in a row , we are adding adjacent elements of previous row.
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res(n);
        if(n==0)
            return res;
        res[0].push_back(1);
        if(n==1)
            return res;
        res[1].push_back(1);
        res[1].push_back(1);
        if(n==2)
            return res;
        for(int i=2;i<n;i++)
        {
            res[i].push_back(1);
            for(int j=0;j<res[i-1].size()-1;j++)
            {
                //Adding adjacent elements of previous row.
                res[i].push_back(res[i-1][j]+res[i-1][j+1]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};
