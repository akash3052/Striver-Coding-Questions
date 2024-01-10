void solve(int index, int n, int k, vector<int> &arr, 
            vector<int> row, vector<vector<int>> &res, int sum){
    if(index >=n ){
        if(sum == k){
            res.push_back(row);
        }
        return;
    }
    solve(index+1, n, k, arr, row, res, sum);
    row.push_back(arr[index]);
    solve(index+1, n, k, arr, row, res, sum+arr[index]);
    row.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int> row;
    vector<vector<int>> res;
    solve(0, n, k,  arr, row, res, 0);
    return res;
}
