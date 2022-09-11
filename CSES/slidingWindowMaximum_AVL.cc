class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> ret;
        map<int, int> mp;
        int n = arr.size();
        for(int i=0; i<k;  ++i) {
            mp[arr[i]]++;
        }
        if(!mp.empty())
        ret.push_back(mp.rbegin()->first);
        
        for(int i=k; i<n; ++i) {
            mp[arr[i-k]]--;
            if(mp[arr[i-k]] == 0) {
                mp.erase(arr[i-k]);
            }
            mp[arr[i]]++;
            if(!mp.empty())
            ret.push_back(mp.rbegin()->first);
        }
        return ret;
    }

    vector<int> maxSlidingWindow1(vector<int>& arr, int k) {
        deque<int> dq;
        int n = arr.size();
        vector<int> ret;

        for(int i=0; i<k; ++i) {
            while(!dq.empty() and arr[i] >= arr[dp.back()]) {
                dp.pop_back();
            }
            dq.push_back(i);
        }

        for(int i=k; i<n; ++i) {
            ret.push_back(arr[dp.front()]);

            while(!dq.empty() and dq.front() <= i - k) {
                dp.pop_front();
            }

            while(!dq.empty() and arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }
        ret.push_back(arr[dq.front()]);
        return ret;
    }
  
    vector<int> maxSlidingWindow1(vector<int>& arr, int k) {
        
        // create a priority queue (Max Heap) of pair of int
        // first of the pair is the element of the array
        // and second is the index
        priority_queue<pair<int,int>> p;
        // create a vector to store the result
        vector<int>res;
        // add all the elements in the first window to the PQ
        for(int i = 0; i < k; i++)
            p.push({arr[i],i});
        // add the max element of first window to the res vector
        res.push_back(p.top().first);
        // start iteration from the second window
        for(int i = k; i < arr.size(); i++)
        {
            // add the element into the PQ
            p.push({arr[i],i});
            // remove all the elments which are not in the current window
            // current window is from [i-k+1 , i]
            while(!(p.top().second > i-k))
                p.pop();
            // add the max element in the PQ to the res
            res.push_back(p.top().first);
        }
        // return the result
        return res;
        
    }
};
class Solution2 {
public:
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq(k);

        for(int i=0; i<k; ++i) {
            while(!dq.empty() and nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        vector<int> ret;
        for(int i=k; i<n; ++i) {
            ret.push_back(nums[dq.front()]);
            
            while(!dq.empty() and dq.front() <= i - k)
                dq.pop_front();
            
            while(!dq.empty() and nums[i] >= nums[dq.back()])
                dq.pop_back();
            
            
            dq.push_back(i);
        }
        
        ret.push_back(nums[dq.front()]);
        
        return ret;
    }
};
