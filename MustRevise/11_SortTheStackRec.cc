void insertStack(stack<int> &st, int currNum) {
    if(st.empty() || currNum > st.top()) {
        st.push(currNum);
        return;
    }
    
    // if top is greater, remove the top item and recur
    int top = st.top();
    st.pop();
    
    insertStack(st, currNum);
    
    //put back the top element removed earlier
    st.push(top);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(!stack.empty()){
        int top = stack.top();
        stack.pop();
        sortStack(stack);

        insertStack(stack, top);
    }
}
