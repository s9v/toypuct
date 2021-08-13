#include <iostream>
#include <algorithm>
#define  ln(X)		(int)X.length()
using namespace std;

int t;
string freq;
pair<int, char> freq2[26];
string text;
char decode[26];

int main() {
	cin >> t;
	getline(cin, freq); // dummy
	
	while (t--) {
		getline(cin, freq);
		getline(cin, text);
		
		for (int i = 0; i < 26; i++)
			freq2[i] = make_pair(0, i+'a');
		
		for (int i = 0; i < ln(text); i++)
			if (isalpha(text[i]))
				freq2[ tolower(text[i])-'a' ].first++;
		
		sort(freq2, freq2+26);
		
		for (int i = 0; i < 26; i++)
			decode[freq2[i].second-'a'] = freq[i];
		
		for (int i = 0; i < ln(text); i++) {
			if (isalpha(text[i]))
				cout << char(islower(text[i]) ?tolower(decode[tolower(text[i])-'a']) :toupper(decode[tolower(text[i])-'a']));
			else
				cout << text[i];
		}
		cout << "\n";
	}
	
	return 0;
}
