class Solution {
public:
    bool isVaildStk(char s , stack<char> &stk){
        if(!stk.empty() && stk.top()=='(' && s == ')' ){
            stk.pop();
            return true;
        }
        if(!stk.empty() &&stk.top()=='[' && s == ']' ) { 
            stk.pop();
            return true;
        }
         if(!stk.empty() && stk.top()=='{' && s == '}'){
            stk.pop();
            return true;
        }
        return false;
    }


    bool isValid(string s) {
    stack<char> stk ; 
    for(int i = 0 ; i <s.size();i++){
        if((s[i]=='[')|| 
        (s[i]=='(' )
        || s[i]=='{'){
        stk.push(s[i]);
        }else{
         if(!isVaildStk(s[i],stk))
         return false; 
        }
    }
    return stk.empty();
    }
};
