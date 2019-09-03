#include <stdio.h>
#include <stdlib.h>

struct trieNode {
	struct trieNode* letters[26];
	int EOS;
};

void _initTrieNode(struct trieNode*);

void addWord(struct trieNode* root, char* word) {
	int lett = 0;
	strict trieNode* current = root;
	while(*word) {
		lett = ((int) *word) - 65;
		if (current->letters[lett]) {
			current = current->letters[lett];
		} else {
			struct trieNode* new = malloc(sizeof(struct trieNode));
			_initTrieNode(new);
			current->letters[lett] = new;
			current = new;
		}
		word++;
	}
	current->EOS = 1;
}

void _initTrieNode(struct trieNode* node) {
	for (int i = 0; i < 26; i++) {
		node->letters[i] = NULL;
	}
	node->EOS = 0;
}
