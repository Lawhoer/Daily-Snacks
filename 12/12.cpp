#include <iostream>
#include <vector>

using namespace std;


string longestSubstring(string s, int k) {
	int n = s.length();
	int start = 0, end = 0;
	int maxLen = 0;
	int maxStart = 0;
	int count = 0;
	int charCount[26] = {0};
	while (end < n) {
		charCount[s[end] - 'a']++; 
		if (charCount[s[end] - 'a'] == 1) { 
			count++;
		}
		while (count > k) { // 
			charCount[s[start] - 'a']--;
			if (charCount[s[start] - 'a'] == 0) {
				count--;
			}
			start++;
		}
		if (end - start + 1 > maxLen) {
			maxLen = end - start + 1;
			maxStart = start;
		}
		end++;
	}
	return s.substr(maxStart, maxLen);
}

int main() {

    cout << longestSubstring("abcba", 2);

    return 0;
}