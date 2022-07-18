class Solution {
public:
    void solve(vector<vector<int>> &res, vector<int> &input, vector<int> op, int index,int target){
        if(index == input.size())
            return;
        if(target==0){
            res.push_back(op);
            return;
        }
        // Since, we have sort the input, so if input[index] > target, then input[index+1] will also be greater than target, 
        // that's why we are not going beyond index and not making recursive call on index+1 if input[index] > target.
        if(input[index]<=target){
            op.push_back(input[index]);
            solve(res,input,op,index,target-input[index]);
            op.pop_back();
            solve(res,input,op,index+1,target);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> op;
        int index =0;
        // Sorting the input to reduce recursive call.
        sort(candidates.begin(),candidates.end());
        solve(res,candidates,op,index,target);
        return res;
    }
};
