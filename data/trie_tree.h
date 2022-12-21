#pragma once
#include<vector>
#include<iostream>


class node {

public:
	bool end;
	node* next[26];
	char data;
	node() {
		end = false;

		for (int i = 0; i < 26; i++)
			next[i] = NULL;
		 

	}


};
class trie {

public:

	node* trie_tree ;  

	trie() {
		trie_tree = new node;
	}
	 
	void insert(std::string word) {

		int i = 0;

		node* iterator = trie_tree;
		while (i < word.size()) {

			if (iterator->next[word[i] - 'a'] == NULL) {
				iterator->next[word[i] - 'a'] = new node;

				iterator->next[word[i] - 'a']->data = word[i];
			}
		
			iterator = iterator->next[word[i] - 'a'];
			i++;



		}
		iterator->end = true;

	}
	
	std::vector<std::string> search (std::string word) {
		std::vector <std::string> suggestions;
		int i = 0;
		node* it = trie_tree;

		while (i < word.size()) {
			if (it->next[word[i] - 'a'] == NULL)
			{
				std::cout << "no suggestions";
				return suggestions;
			}

			it = it->next[word[i] - 'a'];
			i++;

		}
		


		

		 find_suggestions(it, word, suggestions, "");

		 for (int i = 0; i < suggestions.size(); i++ ) {
			 suggestions[i] = word+suggestions[i];
		 }

		 return suggestions;
	

	}

	void find_suggestions(node* it, std::string &words, std::vector <std::string> &suggestions, std::string current) {


		if (it == NULL) {
			return;

		}
		if (it->end)
			suggestions.push_back(current);

		for (int i = 0; i < 26; i++) {
			    
			if (it->next[i]) {

				find_suggestions(it->next[i], words, suggestions, current + char('a' + i));
			}

		}

	}

	


};
