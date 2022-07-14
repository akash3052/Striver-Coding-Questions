// Note -> we generally start from last index and check 0 in base condn in any dp or recursion problem, 
// but in this solution we have start form 0 and checked for n in base condn. 
void solve(vector<int> &res, vector<int> &num, int indx,int n,int sum){
    if(indx==n){
        res.push_back(sum);
        return;
    }
    solve(res,num,indx+1,n,sum+num[indx]);
    solve(res,num,indx+1,n,sum);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> res;
    int sum =0,indx=0, n =num.size();
    solve(res,num,indx,n,sum);
    sort(res.begin(),res.end());
    return res;
}
