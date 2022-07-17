class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &res, int index, vector<int> op){
        res.push_back(op);
        // Note -> we are not adding base case because this for loop is doing this.
        // This will not run if index == nums.size()
        for(int i=index;i<nums.size();i++){
            // This if condn is to avoid duplicate subsets.
            if(i!=index && nums[i]==nums[i-1]) 
                continue;
            op.push_back(nums[i]);
            solve(nums,res,i+1,op);
            // Since, we are using the same output vector, we need to pop_back() while returning.
            op.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        vector<int> op;
        int index = 0;
        solve(nums,res,index,op);
        return res;
    }
};
