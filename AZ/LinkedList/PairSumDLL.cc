vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    if(!head || !head->next) return vector<pair<int, int>>();
    vector<pair<int, int>> ret;
    Node *temp = head;
    Node *tail = head;
    
    while(tail->next) {
        tail = tail->next;
    }
    // tail = temp; // end of linked list
    while(temp != tail and tail->next != temp) {
        int s = temp->data + tail->data;
        
        if(s == target) {
            ret.push_back({temp->data, tail->data});
            temp = temp->next;
            tail = tail->prev;
        } else if(s < target) {
            temp = temp->next;
        } else {
            tail = tail->prev;
        }
    }
    return ret;
}
vector<pair<int, int>> findPairsWithGivenSum1(Node *head, int target)
{
    vector<int> t;
    vector<pair<int, int>> ret;
    
    Node *temp = head;
    while(temp) {
        t.push_back(temp->data);
        temp = temp->next;
    }
    
    int i = 0; 
    int j = t.size() - 1;
    
    while(i < j) {
        int s = t[i] + t[j];
        if(s == target) {
            ret.push_back({t[i], t[j]});
            i++;
            j--;
        } else if(s < target) {
            i++;
        } else {
            j--;
        }
    }
    return ret;
}
vector<pair<int, int>> findPairsWithGivenSum0(Node *head, int target)
{
    // code here
    vector<pair<int, int>> ret;
    // unordered_map<int, int> pair_map;
    unordered_set<int> complement_values;
    while(head) {
        int val = head->data;
    
        if(complement_values.find(target - val) == complement_values.end()) {
            complement_values.insert(val);
        } else {
            int x = min(val, target - val);
            int y = target - x;
            ret.push_back({x, y});
            complement_values.erase(target - val);
        }
        head = head->next;
    } 
    sort(ret.begin(), ret.end());
    return ret;
}