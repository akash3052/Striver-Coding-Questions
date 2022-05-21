class Solution
{
public:
    void solve(vector<int> &res, vector<int> input , int op){
        if(input.size()==0){
            res.push_back(op);
            return;
        }
        int op1 = op;
        int op2 = op+input[0];
        input.erase(input.begin());
        solve(res,input,op1);
        solve(res,input,op2);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        int op = 0;
        solve(res,arr,op);
        return res;
    }
};
