#include <stddef.h>

struct trieNode {
	struct trieNode* letters[26];
	int EOS;
};

int findTrieLetter(struct trieNode* root, char c) {
	if (root->letters[(int)c - 65] == NULL) {
		return 0;
	} else {
		return 1;
	}
}
