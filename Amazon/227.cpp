// Amazon | Medium | 227. Basic Calculator II

class Solution {
public:
    int calculate(string s) {
        
        int n = 0, p;
        vector<int> num, op;

        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            if (s[i] >= 48 && s[i] <= 57) {
                int j = i;
                while (s[j] >= 48 && s[j] <= 57) {
                    n *= 10;
                    n += (s[j] - 48);
                    j++;
                }
                num.push_back(n);
                n = 0;
                i = j-1;
            }
            if (s[i] == 42)  op.push_back(s[i]);
            if (s[i] == 43)  op.push_back(s[i]);
            if (s[i] == 45)  op.push_back(s[i]);
            if (s[i] == 47)  op.push_back(s[i]);

            i++;
        }

        // printing the arrays
        cout << "before any operations :--\n";
        for (auto it : num) 
            cout << it << ", ";
        cout << "\n";
        for (auto o : op) 
            cout << o << ", ";
        cout << "\n\n";

        // perform the * and / operations
        for (int j = 0; j < op.size(); j++) {
            if (op[j] == 43 || op[j] == 45)  continue;
            if (op[j] == 42) {
                int temp = num[j] * num[j+1];
                num[j] = -1;
                num[j+1] = temp;
            }
            if (op[j] == 47) {
                int temp = num[j] / num[j+1];
                num[j] = -1;
                num[j+1] = temp;
            }
        }

        // printing the arrays
        cout << "after * and / operations :--\n";
        for (auto it : num) 
            cout << it << ", ";
        cout << "\n";
        for (auto o : op) 
            cout << o << ", ";
        cout << "\n\n";

        // now it's time to do + and - operations 
        i = 0;
        while (i < op.size()) {
            if (op[i] == 42 || op[i] == 47) {
                i++;
                continue;
            }
            if (i < op.size() && op[i] == 43) {
                int temp;
                int k = i+1;
                while (num[k] == -1) {
                    k++;
                }
                temp = num[i] + num[k];
                num[i] = -1;
                num[k] = temp;
                i = k - 1;
            }
            if (i < op.size() && op[i] == 45) {
                int temp;
                int k = i+1;
                while (num[k] == -1) {
                    k++;
                }
                temp = num[i] - num[k];
                num[i] = -1;
                num[k] = temp;
                i = k - 1;
            }

            i++;
        }


        // printing the arrays
        cout << "after + and - operations also :--\n";
        for (auto it : num) 
            cout << it << ", ";
        cout << "\n";
        for (auto o : op) 
            cout << o << ", ";
        cout << "\n\n";

        return num[num.size()-1];
    }
};