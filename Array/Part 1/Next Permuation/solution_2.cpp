class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int indx1=n-1,indx2=n-1;
        int i;
        //Finding the breakpoint (nums[i]<nums[i+1]) let's say indx1 
        for(i=n-1;i>=1;i--)
        {
            if(nums[i]>nums[i-1])
            {
                indx1=i-1;
                break;
            }
        }
        
        //This is edge case when we don't find any breakpoint .
        if(i==0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        //Finding first element from right greater than nums[indx1] ..let's say indx2 
        for(int i=n-1;i>=indx1+1;i--)
        {
            if(nums[i]>nums[indx1])
            {
                indx2=i;
                break;
            }
        }
        
        swap(nums[indx1],nums[indx2]);
        //From indx1+1 , it will be sorted in descending order . So , we will simply reverse it to get the ascending order. 
        reverse(nums.begin()+indx1+1,nums.end());
    }
};
