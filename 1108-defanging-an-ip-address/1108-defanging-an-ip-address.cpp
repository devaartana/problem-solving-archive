class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        ans.resize(address.size() + 6);

        for(int i = 0, j = 0; i < address.size(); i++){
            if(address[i] == '.') {
                ans[i+j] = '[';
                ans[i+j+2] = ']';
                ans[i+j+1] = address[i];
                j+=2;
            } else {
                ans[i+j] = address[i];
            }
        }

        return ans;
    }
};