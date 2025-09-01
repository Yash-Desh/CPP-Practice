// Author : Yash Deshpande
// Date   : 31-08-2025
// Tutor  : Love Babbar

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

    void deleteWord() {
        // Set the isTerminal to false
        // Empty the space.
    }


};



int main() {
    Trie *t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout<<"ABCD present or not ? "<<t->searchWord("TIM")<<endl;
    return 0;
}