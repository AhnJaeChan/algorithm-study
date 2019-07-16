class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        int fact = 2;
        bool flag = false;
        if (len == 1) return false;
        do {
            if (len % fact == 0) {
                int sub = len / fact;
                string substring = s.substr(0, sub);
                int i;
                for (i = 1; i < fact; i++) {
                    if (substring.compare(s.substr(i * sub, sub)) != 0)
                        break;
                }
                if (i == fact) {
                    flag = true;
                    break;
                }

            }
            fact++;

        } while (fact <= len);
        return flag;
    }
};