class Solution {
public:
    // DP approach
    int brute(vector<int> &height) {
        int n = height.size();
        vector<int> lmx(n), rmx(n);
        lmx[n-1] = height[n-1];
        rmx[0] = height[0];
        int ans = 0;
        
        for(int i=1; i<n; ++i) {
            lmx[n-i-1] = max(lmx[n-i], height[n-i-1]);
            rmx[i] = max(rmx[i-1], height[i]);
        }
        for(int i=0; i<n; ++i) {
            if(height[i] >= max(lmx[i], rmx[i]))    continue;
            ans += (min(lmx[i], rmx[i]) - height[i]);
        }
        return ans;
    }
    int trap3(vector<int>& height)
    {
        // return brute(height);
        return trap2(height);
    }
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
    int stacks(vector<int> &height) {
        stack<int> st;
        st.push(0);
        int amount = 0;
        int n = height.size();
        for(int i=1 ;i<n; ++i){
            if(height[i] > height[st.top()]) {
                st.pop();
                int distance = i - st.top() - 1;
                int bounded_height = min(height[i], height[st.top()]) - height[st.top()];
                amount += distance * bounded_height;
            }        
            st.push(i);
        }
        return amount;
        
    }int trap2(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}
    int trap1(vector<int>& height) {
        // buy and sell stock II
        // collect every dip and ups
        int n = height.size();
        int start = 0;
        int end = 0;
        int idx = 0;
        while(height[idx] == 0){
            idx++;
            continue;
        }
        if(idx == n-1) return 0; 
        
        int sum = 0;
        for(int i=idx+1; i<n; ++i)  {
            int left_max=0, right_max=0;
            for(int j=i; j>=0; j--){
                left_max = max(left_max, height[j]);
            }
            for(int j=i; j<n; ++j){
                right_max = max(right_max, height[j]);
            }
            // if(height[i] < height[i-1] and height[i] < height[i+1])
            sum += (min(left_max, right_max) - height[i]);
        }
        return sum;
    }
};
