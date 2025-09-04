// Author : Yash Deshpande
// Date   : 31-08-2025
// Tutor  : Love Babbar

// ###############################
// Trie Fundamentals
// 1. Insertion
// 2. Search
// 3. Deletion
// ###############################

#include <iostream>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i=0; i<26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }

};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        // Base Case.
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Assumption: All the characters are in upper case
        int index = word[0] - 'A';

        // Check if the character is already present 
        TrieNode* child;
        if(root->children[index] != nullptr) {
            // Present 
            child = root->children[index];
        }
        else {
            // Absent
            child = new TrieNode (word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        // Calls the recursive utility function
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            return root->isTerminal;
        }

        // Assumption: All the characters are in upper case
        int index = word[0] - 'A';

        TrieNode *child;
        if(root->children[index] != nullptr) {
            child = root->children[index];
        }
        else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    // Returns true if root has no children.
    bool isEmpty(TrieNode* root) {
        for(int i=0; i<26; i++) {
            if(root->children[i] != NULL) {
                return false;
            }
        }
        return true;
    }

    TrieNode* deleteUtil(TrieNode* root, string word, int depth = 0) {
        // Base Case.
        if(root == NULL) {
            return NULL;
        }

        // For processing the last character in the word.
        if(depth == word.size()) {
            if(root->isTerminal) {
                root->isTerminal = false;
            }

            if(isEmpty(root)) {
                delete root;
                root = nullptr;
            }
            return root;
        }

        int index = word[depth] - 'A';
        root->children[index] = deleteUtil(root->children[index], word, depth + 1);

        if (isEmpty(root) && !root->isTerminal) {
            delete (root);
            root = NULL;
        }

        return root;
    }

    void deleteWord(string word) {
        deleteUtil(root, word, 0);
    }

};

int main() {
    Trie *t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout<<"ABCD present or not ? "<<t->searchWord("ABCD")<<endl;
    t->deleteWord("ABCD");
    cout<<"ABCD present or not ? "<<t->searchWord("ABCD")<<endl;
    return 0;
}

/* 

############################## Complexities Explained ##############################

1. Insertion
TC : O(N) where N is the length of the word.
Each character is processed in a single recursive function call.

2. Searching
TC : O(N) where N is the length of the word.
Each character is processed in a single recursive function call.


*/