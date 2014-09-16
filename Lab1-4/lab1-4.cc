/**
 * Filename: lab1-4.cc
 * Lab: Lab 1 - Imperative programming
 * Authors: Andreas Algovik		890718-0031	I5
 *			Elisabeth Hanning	900419-2325	I5
 * Date: 160914
 * Description: Reads a word store it in a struct and
 * counts how many time the word has been read
 */

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

/**
 * A struct for being able to keep track of the word entered
 * and how many times it has been entered
 */
struct word_entry{
	int count;
	string word;
};

vector<word_entry> insert(string s, vector<word_entry> wordbook);
void print(vector<word_entry> wordbook);

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
			for(auto &i : wordbook){
				if(s.compare(i.word) == 0){
					i.count += 1;
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

/**
 * Creates a word_entry struct for the word and put it in the right alphabetic position
 * in the wordbook
 * @param s The word entered, wordbook the vector containing all the words
 * @return the wordbook with a new word entered
 */
vector<word_entry> insert(string s, vector<word_entry> wordbook){

	word_entry temp;
	temp.word = s;
	temp.count = 1;
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

	return wordbook;

}

/**
 * Print all the words in the wordbook and how many time they appeared
 * @param wordbook The vector containing all the words
 */
void print(vector<word_entry> wordbook){

	cout << setw(10) << "Ord" << setw(10) << "Antal" << endl;

	for(auto &i : wordbook){
 		cout << setw(10) << i.word << setw(10) << i.count << endl;
 	}

}
