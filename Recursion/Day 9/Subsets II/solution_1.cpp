class Solution {
public:
    // In this question, [4,1,4] and [1,4,4] is considered as same but in subset, order is not important. 
    // So, 
    // 1.either first sort the input array and then find all the possible subsequences or 
    // 2.While inserting the output in the set, first sort the output and then insert so that [4,1,4] and [1,4,4] will become [1,4,4] (and will be not considered different)
    void solve(set<vector<int>> &res, vector<int> input, vector<int> output){
        if(input.size() == 0){
            res.insert(output);
            return;
        }
        vector<int> op1 = output;
        vector<int> op2 = output;
        op2.push_back(input[0]);
        input.erase(input.begin());
        //excluding the first element of input
        solve(res,input,op1);
        //including the first element of input
        solve(res,input,op2);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> output; 
        sort(nums.begin(),nums.end());
        solve(res,nums,output);
        vector<vector<int>> final_res;
        for(auto it=res.begin();it!=res.end();it++)
            final_res.push_back(*it);
        return final_res;
    }
};
