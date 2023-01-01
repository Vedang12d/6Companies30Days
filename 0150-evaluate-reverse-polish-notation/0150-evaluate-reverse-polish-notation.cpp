class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int a,b;
        for(string s:tokens){
            if(s.size()>1||isdigit(s[0])){
                stk.push(stoi(s));
                continue;
            }
            a=stk.top();
            stk.pop();
            b=stk.top();
            stk.pop();
            switch(s[0]){
                case '*':
                    stk.push(b*a);
                    break;
                case '/':
                    stk.push(b/a);
                    break;
                case '+':
                    stk.push(b+a);
                    break;
                case '-':
                    stk.push(b-a);
                    break;
            }
        }
        return stk.top();
    }
};