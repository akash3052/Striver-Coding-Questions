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



Time Complexity: O(2^t * k) where t is the target, k is the average length

Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)

Why not (2^n) but (2^t) (where n is the size of an array)?
Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

Space Complexity: O(k*x), k is the average length and x is the no. of combinations
