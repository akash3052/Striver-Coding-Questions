// Note -> This solution passes all the tc because stringstream removes all the extra spaces in between words.
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        stack<string> words;
        string word;
        while(ss>>word){
            words.push(word);
        }
        string res = "";
        while(!words.empty()){
            // For last word, we don't need to give space.
            if(words.size()==1){
                res+= words.top();
                words.pop();
            }else{
                res+=words.top() + " ";
                words.pop();
            }
        }
        return res;
    }    
};
