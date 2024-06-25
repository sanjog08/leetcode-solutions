// Amazon | Hard | 224. Basic Calculator

class Solution {
public:
    int calculate(string s) {
        long long int sum = 0;
        int sign = 1;
        stack<pair<int,int>> st;

        for(int i=0; i<s.size();i++){
            if(isdigit(s[i])){
                long long int num = 0;
                while(i<s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += num * sign;
                sign = 1;
            }
            else if(s[i] == '('){
                st.push({sum, sign});
                sum = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                sum = st.top().first + (st.top().second * sum);
                st.pop();

            }
            else if(s[i] == '-'){
                sign = -1 * sign;
            }
        }
        return sum;
    }
};

























// this code is only aplicable for the single operator between any two numbers
// #define ll long long

// class Solution {
// public:
//     int calculate(string s) {
        
//         ll n = 0;
//         int ans = 0;
//         int  m = 1;

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == ' ' || s[i] == '(' || s[i] == ')')   continue;
//             if (s[i] >= 48 && s[i] <= 57) {
//                 n = (n * 10) + ((s[i] - 48) * m);
//             }
//             if (s[i] == 43) {
//                 m = 1;
//                 ans += n;
//                 n = 0;
//             }
//             if (s[i] == 45) {
//                 m = -1;
//                 ans += n;
//                 n = 0;
//             }
//         }
//         return ans+n;
//     }
// };