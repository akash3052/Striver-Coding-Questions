class Solution {
public:
    void solve(set<vector<int>> &alluniquesubsets, vector<int> &input, vector<int> op, int index, int target){
        if(index == input.size()){
            if(target==0){
                alluniquesubsets.insert(op);
            }
            return;
        }
        if(input[index] <= target){
            op.push_back(input[index]);
            solve(alluniquesubsets,input,op,index+1,target-input[index]);
            op.pop_back();
            solve(alluniquesubsets,input,op,index+1,target);
        }else{
            solve(alluniquesubsets,input,op,index+1,target);
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> alluniquesubsets;
        vector<int> op;
        int index=0;
        sort(candidates.begin(),candidates.end());
        solve(alluniquesubsets,candidates,op,index,target);
        vector<vector<int>> res;
        for(auto it=alluniquesubsets.begin();it!=alluniquesubsets.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};
