/* Please use the chemical symbols in the periodic table below when you solve this problem.
   "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
   "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
   "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
   "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
   "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
   "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
   "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
   "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
   "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
   "No", "Lr"   */

/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <set>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int Answer;

const string periodArr[] = {
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
    "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
    "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
    "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
    "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
    "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
    "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
    "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
    "No", "Lr"
};

set<string> periods;

int isPossible(string &s, int idx) {
  if (idx == s.length()) {
    return 0;
  } else if (idx > s.length()) {
    return -1;
  }

  if (periods.find(s.substr(idx, 1)) != periods.end()) {
    return isPossible(s, idx + 1);
  } else if (periods.find(s.substr(idx, 2)) != periods.end()) {
    return isPossible(s, idx + 2);
  } else {
    return -1;
  }
}

int main(int argc, char **argv) {
  int T, test_case;
  string s;

  /*
     The freopen function below opens input.txt file in read only mode, and afterward,
     the program will read from input.txt file instead of standard(keyboard) input.
     To test your program, you may save input data in input.txt file,
     and use freopen function to read from the file when using cin function.
     You may remove the comment symbols(//) in the below statement and use it.
     Use #include<cstdio> or #include <stdio.h> to use the function in your program.
     But before submission, you must remove the freopen function or rewrite comment symbols(//).
   */

  // freopen("input.txt", "r", stdin);

  for (string period : periodArr) {
    transform(period.begin(), period.end(), period.begin(), [](unsigned char c) { return tolower(c); });
    periods.insert(period);
  }

  cin >> T;
  for (test_case = 0; test_case < T; test_case++) {

    Answer = 0;
    /////////////////////////////////////////////////////////////////////////////////////////////
    /*
       Implement your algorithm here.
       The answer to the case will be stored in variable Answer.
     */

    cin >> s;

    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
    Answer = isPossible(s, 0);

    /////////////////////////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << (Answer < 0 ? "NO" : "YES") << endl;
  }

  return 0;//Your program should return 0 on normal termination.
}