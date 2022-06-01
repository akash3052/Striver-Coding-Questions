// In this solution, I am not storing from which index to which index I am considering the subarray.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum =0 , maxSum = INT_MIN;
        for(auto num : nums){
            currSum += num;
            if(maxSum < currSum ){
                maxSum = currSum;
            }
            if(currSum < 0)
                currSum = 0;
        }
        return maxSum;
    }
};
