class Solution {
public:
    std::vector<std::string> letterMap = {"abc", "def", "ghi", "jkl",
                                          "mno", "pqrs", "tuv", "wxyz"};

    std::vector<std::string> ans;
    std::string temp;

    void helper(std::string& digits, int count) {
        if (count == digits.size()) {
            ans.push_back(temp);
            return;
        }

        int index = digits[count] - '0' - 2;
        for (int i = 0; i < letterMap[index].size(); i++) {
            temp.push_back(letterMap[index][i]);
            helper(digits, count + 1);
            temp.pop_back();
        }
    }
    std::vector<std::string> letterCombinations(std::string digits) {
        if(digits.size() > 0) helper(digits, 0);
        return ans;
    }
};
