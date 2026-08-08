class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> l(m, -1);
        int i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                l[j] = i;
                --j;
            }
            --i;
        }
        vector<int> ans;
        ans.reserve(m);

        bool s = true;
        j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                ++j;
            } else if (s && (j == m - 1 || i < l[j + 1])) {
                s = false;
                ans.push_back(i);
                ++j;
            }
        }
        if (j == m) {
            return ans;
        }
        return {};
    }
};