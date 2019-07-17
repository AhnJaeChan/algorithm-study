class Solution {
public:
    string defangIPaddr(string address) {
        string::iterator iter = address.begin();
        string ret = "";
        for (; iter != address.end(); iter++) {
            if (*iter != '.') {
                ret += *iter;
            }
            else {
                ret += "[.]";
            }

        }
        return ret;
    }
};