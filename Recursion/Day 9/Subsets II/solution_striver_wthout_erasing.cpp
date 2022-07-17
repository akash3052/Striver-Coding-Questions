class Solution {
public:
    void solve(vector<int> &nums, set<vector<int>> &allSubsets, int index, int n, vector<int> op){
        // In base cond, instead of checking input.size() == 0, we are checking whether index has become n(which means we have reached beyond last element).
        if(index == n){
            allSubsets.insert(op);
            return;
        }
        // In this solution, we are not erasing input, rahter we are just increment index instead of deleting the first element of input.
        op.push_back(nums[index]);
        solve(nums,allSubsets,index+1,n,op);
        //Before calling next recursive call, we need to pop_back because we are using the same output vector and in the 2nd recursive call, 
        //we don't want to include input[index].
        op.pop_back();
        solve(nums,allSubsets,index+1,n,op);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> allSubsets;
        int indx=0, n=nums.size();
        vector<int> op;
        // If we will not sort here, we will have to sort it in solve() func before inserting it in the allSubsets.
        sort(nums.begin(),nums.end());
        solve(nums,allSubsets,indx,n,op);
        for(auto it=allSubsets.begin();it!=allSubsets.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};
