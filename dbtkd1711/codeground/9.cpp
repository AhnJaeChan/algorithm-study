#include <iostream>
#include <ctype.h>

using namespace std;

string symbols[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
   "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
   "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
   "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
   "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
   "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
   "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
   "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
   "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
   "No", "Lr"};

int Answer;

int solve(string sentence) {
	int i, j;
	int size = sizeof(symbols) / sizeof(string);
	bool * d = new bool[sentence.length() + 1] {0, };

	d[0] = 1;

	for(j = 0 ; j < size ; j++) {
		if(symbols[j].length() == 1) {
			if(sentence[0] - 'a' == symbols[j][0] - 'A')
				d[1] = 1;
		}
	}

	for(i = 1 ; i < sentence.length() ; i++) {
		for(j = 0; j < size ; j++) {
			if(symbols[j].length() == 1) {
				if(d[i] == 1 && sentence[i] - 'a' == symbols[j][0] - 'A')
					d[i+1] = 1;
			}
			else {
				if(d[i - 1] == 1 && sentence[i-1] - 'a' == symbols[j][0] - 'A' && sentence[i] == symbols[j][1])
					d[i+1] = 1;
			}
		}
	}

	if(d[sentence.length()] == 1)
		return 1;
	else
		return 0;

}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		string sentence;
		cin >> sentence;
		Answer = solve(sentence);

		cout << "Case #" << test_case+1 << endl;
		if(Answer == 0)
			cout << "NO" << endl;
	 	else
			cout << "YES" << endl;

	}

	return 0;//Your program should return 0 on normal termination.
}
