#include <map>
#include <algorithm>
#include <string>

int lengthOfLongestSubstring(string s) {
	// find the length of the longest substring without repeating characters
	map<char, int> map;
	int ans = 0;
	int n = s.size(), left = -1;
	for (int i = 0; i < n; i++) {
		if (map.count(s[i]) && map[s[i]] > left)	// map.count(key1) return 0 if not found key1 in map, return 1 if found key1 in map
			left = map[s[i]];	// map[key1] return the value of key1, in this case, it stores the starting index of our substring
		map[s[i]] = i;
		ans = max(ans, i - left);
	}
	return ans;
}
