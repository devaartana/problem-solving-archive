class Solution {
public:
    bool isOperator(string &s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int evalRPN(vector<string>& tokens) {
        vector<int> st(tokens.size());

        int pointer = 0;
        for(string &token : tokens) {
            if(isOperator(token)) {
                switch(token[0]) {
                    case '+':
                        st[pointer - 2] += st[pointer - 1];
                        break;
                    case '-':
                        st[pointer - 2] -= st[pointer - 1];
                        break;
                    case '/':
                        st[pointer - 2] /= st[pointer - 1];
                        break;
                    case '*':
                        st[pointer - 2] *= st[pointer - 1];
                        break;
                    default:
                        break;
                } 

                pointer--;
            } else st[pointer++] = stoi(token);
        }

        return st[pointer - 1];
    }
};