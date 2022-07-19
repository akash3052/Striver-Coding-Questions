class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string word = "";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                stk.push(word);
                word = "";
            }else{
                word+=s[i];
            }
        }
        // Last word has not been pushed, that's why pushed it in below line.
        stk.push(word);
        string res = "";
        // Don't need to give space after last word, that's why iterating the stack before the last word and after the while loop adding the last word.
        while(stk.size() != 1){
            res+=stk.top() + " ";
            stk.pop();
        }
        res+=stk.top();
        return res;
    }
};
