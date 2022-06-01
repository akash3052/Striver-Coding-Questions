//Method 1 : counting sort

//Counting occurences of each of the unique elements present in the array and then storing them in the array using their count.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zeros=0,ones=0,twos=0;
        for(auto x:nums)
        {
            if(x==0)
                zeros++;
            else if(x==1)
                ones++;
            else
                twos++;
        }
        for(int i=0;i<zeros;i++)
            nums[i]=0;
        for(int i=zeros;i<zeros+ones;i++)
            nums[i]=1;
        for(int i=zeros+ones;i<zeros+ones+twos;i++)
            nums[i]=2;
        
    }
};
