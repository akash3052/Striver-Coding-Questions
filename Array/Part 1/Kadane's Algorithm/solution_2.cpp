// start and end will store the start and end index of subarray whose sum is maximum.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum =0 , maxSum = INT_MIN;
        int start = 0, end = 0;
        for(int i=0;i<nums.size(); i++){
            currSum += nums[i];
            if(maxSum < currSum ){
                maxSum = currSum;
                end = i;
            }
            if(currSum < 0){
                currSum = 0;
                start = i+1;
            }
                
        }
        cout<<start<<" "<<end<<endl;
        return maxSum;
    }
};
