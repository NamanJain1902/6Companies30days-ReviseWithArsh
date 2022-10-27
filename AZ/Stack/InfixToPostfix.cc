int Prec(char ch)
{
    switch (ch) {
        case '+':
        case '-':
            return 1;
    
        case '*':
        case '/':
            return 2;
    
        case '^':
            return 3;
    }
    return -1;
}
string infixToPostfix(string s) {
    // Your code here
    stack<char> st;
    // unordered_map<char, int> priority;
    string res;
    int n = s.length();
    
    for(int i=0; i<n; ++i) {
        
        if(s[i] >= 'a' and s[i] <= 'z') {
            res += s[i];
        } else if(s[i] == '(') {
            st.push('(');
        } else if(s[i] == ')') {
            while(!st.empty() and st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        } else {
            while(!st.empty() and Prec(st.top()) >= Prec(s[i])) {
                res += st.top();
                st.pop();
            }    
            st.push(s[i]);
        }
    }
    
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}