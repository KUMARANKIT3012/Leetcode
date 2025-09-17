class Solution {
public:
    unordered_map<string, bool> memo;

    bool parseBoolExpr(string expression) {
        return eval(expression);
    }

    bool eval(string exp) {
        if (exp == "t") return true;
        if (exp == "f") return false;
        if (memo.count(exp)) return memo[exp];

        char op = exp[0]; 
        string inside = exp.substr(2, exp.size() - 3);

        vector<string> parts;
        int bal = 0;
        string cur = "";
        for (char c : inside) {
            if (c == ',' && bal == 0) {
                parts.push_back(cur);
                cur = "";
            } else {
                if (c == '(') bal++;
                if (c == ')') bal--;
                cur.push_back(c);
            }
        }
        if (!cur.empty()) parts.push_back(cur);

        bool result;
        if (op == '!') {
            result = !eval(parts[0]);
        } else if (op == '&') {
            result = true;
            for (auto &p : parts) {
                if (!eval(p)) {
                    result = false;
                    break;
                }
            }
        } else { // op == '|'
            result = false;
            for (auto &p : parts) {
                if (eval(p)) {
                    result = true;
                    break;
                }
            }
        }

        return memo[exp] = result;
    }
};
