class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool jewel[26 * 2];
        int num = 0;
        fill_n(jewel, 26 * 2, false);
        for (int i = 0; i < J.length(); i++) {
            if (J[i] >= 'A' && J[i] <= 'Z') {
                jewel[J[i] - 'A' + 26] = true;
            }
            else {
                jewel[J[i] - 'a'] = true;
            }
        }
        for (int i = 0; i < S.length(); i++) {
            if (S[i] >= 'A' && S[i] <= 'Z') {
                if (jewel[S[i] - 'A' + 26]) num++;
            }
            else {
                if (jewel[S[i] - 'a']) num++;
            }
        }
        return num;
    }
};