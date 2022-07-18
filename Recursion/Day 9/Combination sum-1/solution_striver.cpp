class Solution {
public:
    void solve(vector<vector<int>> &res, vector<int> &input, vector<int> op, int index,int target){
        if(index == input.size()){
            if(target==0){
                 res.push_back(op);
            }
            return;
        }
        if(input[index]<=target){
            op.push_back(input[index]);
            solve(res,input,op,index,target-input[index]);
            op.pop_back();

        }
        solve(res,input,op,index+1,target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> op;
        int index =0;
        // Without sorting.
        // sort(candidates.begin(),candidates.end());
        solve(res,candidates,op,index,target);
        return res;
    }
};
