#include <iostream>
#include <vector>
using namespace std;

struct word_entry{  
    int count;  
	string word;
};

bool cmp(const word_entry& lw, const word_entry& rw){
	return lw.word < rw.word;
} 

vector<word_entry> insert(string s, vector<word_entry> wordbook){

	word_entry temp;
	temp.word = s;
	temp.count = 1;

	// Sätter in på rätt plats direkt
	bool inserted = false;
	for(vector<word_entry>::iterator it = wordbook.begin(); it != wordbook.end(); ++it){
		if(s.compare(it->word) < 0){
			wordbook.insert(it, temp);
			inserted = true;
			break;
		}
	}
	if(!inserted){
		wordbook.push_back(temp);
	}

	// Sätter in och sorterar sen
	// wordbook.push_back(temp);
	// sort(wordbook.begin(), wordbook.end(), cmp);
	return wordbook;
}

void print(vector<word_entry> wordbook){
	cout << "\t Ord \t Antal" << endl << endl;
	
	//Tydligen mer korrekt för C++
	for(vector<word_entry>::iterator it = wordbook.begin(); it != wordbook.end(); ++it){
		cout << "\t" << it->word << "\t" << it->count << endl;
	}

	//C++11
	// for(auto &i : wordbook){
	// 	cout << "\t" << i.word << "\t" << i.count << endl; 
	// }

	//Funkar
	// for(int i = 0; i < wordbook.size(); ++i) {
	// 	cout <<  "\t" << wordbook[i].word <<  "\t" << wordbook[i].count << endl; 
	// }
}



int main(){
	vector<word_entry> wordbook;
	string s;
	
	while(cin >> s){
		for(int i = 0; i < s.size(); ++i) {
			s[i] = tolower(s[i]);
		}
	
		if(wordbook.empty()){
			wordbook = insert(s, wordbook);
		}else{
			bool exists = false;
			for(int i = 0; i < wordbook.size(); ++i) {
				if(s.compare(wordbook[i].word) == 0){
				wordbook[i].count += 1;
					exists = true;
				}
			}
			if(!exists){
				wordbook = insert(s, wordbook);
			}
 		}
	}
	print(wordbook);
	return 0;
}