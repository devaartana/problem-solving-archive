class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ans;

        for(string email:emails){
            int i = 0;
            string name = "";

            for(; !(email[i] == '+' || email[i] == '@') ; i++) {
                if(email[i] != '.') {
                    name.push_back(email[i]);
                } 
            }

            for(;email[i] != '@'; i++);

            name.append(email.substr(i, email.length()));
        
            ans.insert(name);
        }

        return ans.size();
    }
};