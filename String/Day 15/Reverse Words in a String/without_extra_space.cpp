class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right =  s.length()-1;
        string ans = "", temp = "";
        while(left <= right){
            if(s[left] != ' '){
                temp+=s[left];
            }else{
                if(ans=="")
                    ans = temp;
                else{
                    // adding temp at the starting of the ans so that it will automatically become reversed at last.
                    // Run the code and print ans and temp for better understanding.
                    ans = temp+" "+ans;
                }
                temp = "";
            }
            left ++;
        }
        if(temp!=""){
            if(ans == "")
                ans = temp;
            else
                ans = temp+" "+ans;
        }
        return ans;
    }
};
