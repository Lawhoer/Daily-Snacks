#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Trie'ye kelime eklemek için
    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a'; // Harfin Trie'deki çocuk düðümler dizisindeki indeksini belirlemek için, harfin ASCII deðerinden 'a' (ASCII deðeri 97) çýkartýlýr. Bu, harfin alfabetik sýradaki konumunu belirler.
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    // Trie'de kelime aramak için
    bool search(const string& word) {
		TrieNode* current = root;
        for (char ch : word) {
			int index = ch - 'a';
            if (current->children[index] == nullptr) {
				return false;
			}
			current = current->children[index];
		}
		return current->isEndOfWord;
	}
    
    vector<string> autocomplete(const string& prefix) {
        vector<string> result;
        TrieNode* current = root;

        // Prefix'e kadar git
        for (char ch : prefix) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return result; // Prefix yoksa boþ bir vektör döndür
            }
            current = current->children[index];
        }

        // DFS kullanarak otomatik tamamlama yap
        autocompleteDFS(current, prefix, result);

        return result;
    }

private:
    // DFS kullanarak otomatik tamamlama yapmak için yardýmcý fonksiyon
    void autocompleteDFS(TrieNode* node, const string& currentPrefix, vector<string>& result) {
        if (node->isEndOfWord) {
            result.push_back(currentPrefix);
        }

        for (int i = 0; i < 26; ++i) {
            if (node->children[i] != nullptr) {
                autocompleteDFS(node->children[i], currentPrefix + char('a' + i), result);
            }
        }
    }

};


int main() {

    vector<string> wordSet = { "dog", "deer", "deal", "cat", "cab" };
    string query = "de";

    // Trie oluþtur
    Trie trie;
    for (const string& word : wordSet) {
        trie.insert(word);
    }

    vector<string> autocompleteResult = trie.autocomplete(query);

    cout << "Autocomplete results for query '" << query << "':\n";
    for (const string& result : autocompleteResult) {
        cout << result << "\n";
    }
    
    return 0;
}