class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        std::vector<std::vector<int>> tab(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));

        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    tab[i][j] = tab[i - 1][j - 1] + 1;  
                } else {
                    tab[i][j] = std::max(tab[i - 1][j], tab[i][j - 1]);
                }
            }
        }

        return tab[text1.size()][text2.size()];
    }
};
