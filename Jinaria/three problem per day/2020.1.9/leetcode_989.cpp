class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> k;
        stack<int> s;
        if(K == 0)
            k.push_back(0);
        else{
            while(K != 0){
                s.push(K % 10);
                K /= 10;
            }
            while(!s.empty()){
                k.push_back(s.top());
                s.pop();
            }
        }
        
        auto a_iter = A.rbegin();
        auto k_iter = k.rbegin();
        bool flag = false;
        while(a_iter != A.rend() && k_iter != k.rend()){
            if(flag){
                int t = *a_iter + *k_iter + 1;
                if(t >= 10)
                    s.push(t % 10);
                else{
                    s.push(t);
                    flag = false;
                }
            }
            else{
                int t = *a_iter + *k_iter;
                if(t >= 10){
                    flag = true;
                    s.push(t % 10);
                }
                else{
                    s.push(t);
                }
            }
            a_iter++;
            k_iter++;
        }
        while(a_iter != A.rend()){
            if(flag){
                int t = *a_iter + 1;
                if(t >= 10)
                    s.push(t % 10);
                else{
                    s.push(t);
                    flag = false;
                }
            }
            else{
                s.push(*a_iter);
            }
            a_iter++;
        }
        while(k_iter != k.rend()){
            if(flag){
                int t = *k_iter + 1;
                if(t >= 10)
                    s.push(t % 10);
                else{
                    s.push(t);
                    flag = false;
                }
            }
            else{
                s.push(*k_iter);
            }
            k_iter++;
        }
        if(flag) s.push(1);
        vector<int> ret;
        while(!s.empty()){
            ret.push_back(s.top());
            s.pop();
        }
        return ret;
    }
};