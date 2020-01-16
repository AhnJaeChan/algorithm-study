class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool flag = true;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else if(c == ')'){
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else{
                    flag = false;
                    break;
                }
            }
            else if(c == ']'){
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else{
                    flag = false;
                    break;
                }
            }
            else if(c == '}'){
                if(!st.empty() && st.top() == '{')
                    st.pop();
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(!st.empty())
            flag = false;
        return flag;
    }
};