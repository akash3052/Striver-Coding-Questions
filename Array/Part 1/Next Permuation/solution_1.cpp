void nextPermutation(vector<int>& nums) {
    int i=nums.size()-2;
    while(i>=0 && nums[i]>=nums[i+1]){
        i--;
    }
    // If the whole sequence is in descending order, then we will not swap, we will simply reverse only.
    if(i>=0){
        int j= nums.size()-1;
        while(nums[j]<=nums[i]){
            j--;
        }
        swap(nums[i],nums[j]);
    }
    reverse(nums.begin()+i+1,nums.end());
}
//Above function time complexity is O(n).

/**Function to reverse the array. TC = O(n)**/

// void reverse(vector<int> &nums, int start, int end){
//   while(start<end){
//     swap(nums[start++],nums[j--]);
//   }
// }

