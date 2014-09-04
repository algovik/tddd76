#include <iostream>
#include <vector>
using namespace std;



struct word_entry{  
    int count;  
	string word;
};

bool cmp(const word_entry& leftword, const word_entry& rightword){
	return leftword.word < rightword.word;
} 

vector<word_entry> insert(string s, vector<word_entry> wordbook){

	word_entry temp;
	temp.word = s;
	temp.count = 1;

	//Funkar ej
	// for(int i = 0; i < wordbook.size(); i++) {
	//	if(s < wordbook[i].word){
	//		wordbook.push_back(word_entry());
	//		wordbook.insert(wordbook.begin()+i, temp);
	//		break;
	//	}
	//
	//}
	
	//Funkar
	//wordbook.push_back(temp);
	//sort(wordbook.begin(), wordbook.end(), cmp);
	return wordbook;
}

void print(vector<word_entry> wordbook){
	cout << "\t Ord \t Antal" << endl << endl;
	
	for(int i = 0; i < wordbook.size(); i++) {
		cout <<  "\t" << wordbook[i].word <<  "\t" << wordbook[i].count << endl; 
	}
}



int main(){
	vector<word_entry> wordbook;
	string s;
	
	while(cin >> s){
		for(int i = 0; i < s.size(); i++) {
			s[i] = tolower(s[i]);
		}
	
		if(wordbook.empty()){
		wordbook = insert(s, wordbook);
		}else{
			bool exists = false;
			for(int i = 0; i < wordbook.size(); i++) {
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