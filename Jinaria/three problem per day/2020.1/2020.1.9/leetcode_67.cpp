class Solution {
public:
    string addBinary(string a, string b) {
        string::reverse_iterator a_iter = a.rbegin();
        string::reverse_iterator b_iter = b.rbegin();
        bool flag = false;
        stack<char> s;
        while(a_iter != a.rend() && b_iter != b.rend()){
            if(flag){
                if(*a_iter == '1'){
                    if(*b_iter == '1'){
                        s.push(1);
                    }
                    else{
                        s.push(0);
                    }
                }
                else{
                    if(*b_iter == '1'){
                        s.push(0);
                    }
                    else{
                        s.push(1);
                        flag = false;
                    }
                }
            }
            else{
                if(*a_iter == '1'){
                    if(*b_iter == '1'){
                        flag = true;
                        s.push(0);
                    }
                    else{
                        s.push(1);
                    }
                }
                else{
                    if(*b_iter == '1'){
                        s.push(1);
                    }
                    else{
                        s.push(0);
                    }
                }
            }
            a_iter++;
            b_iter++;
        }
        while(a_iter != a.rend()){
            if(flag){
                if(*a_iter == '1'){
                    s.push(0);
                }
                else{
                    s.push(1);
                    flag = false;
                }
            }
            else{
                if(*a_iter == '1'){
                    s.push(1);
                }
                else{
                    s.push(0);
                }
            }
            a_iter++;
        }
        while(b_iter != b.rend()){
            if(flag){
                if(*b_iter == '1'){
                    s.push(0);
                }
                else{
                    s.push(1);
                    flag = false;
                }
            }
            else{
                if(*b_iter == '1'){
                    s.push(1);
                }
                else{
                    s.push(0);
                }
            }
            b_iter++;
        }
        if(flag) s.push(1);
        string ret = "";
        while(!s.empty()){
            if(s.top())
                ret += "1";
            else
                ret += "0";
            s.pop();
        }
        return ret;
    }
};