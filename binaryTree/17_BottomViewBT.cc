 vector<int> topView(Node *root)
    {
        //Your code here
        // same as bottom up with a condition that if key exists that don't overwrite in map
        
        queue<pair<Node*, int>> qp;
        qp.push({root, 0});
        vector<int> ret;
        map<int, int> m;
        
        while(!qp.empty()) {
            pair<Node*, int> t= qp.front();
            qp.pop();
            if(m.find(t.second) == m.end()){
                m[t.second] = t.first->data;
            }
            
            if(t.first->left){
                qp.emplace(t.first->left, t.second - 1);
            }
            if(t.first->right){
                qp.emplace(t.first->right, t.second + 1);
            }
            
        }
        
        for(auto x: m){
            ret.push_back(x.second);
        }
        return ret;
    }
vector <int> bottomView(Node *root) {
    // Your Code Here
    queue<pair<Node*, int>> qp;
    qp.emplace(root, 0);
    map<int, int> m;

    while(!qp.empty()) {
        pair<Node*, int> t = qp.front();
        m[t.second] = t.first->data;
        qp.pop();

        if(t.first->left){
            qp.emplace(t.first->left, t.second-1);
        }

        if(t.first->right){
            qp.emplace(t.first->right, t.second+1);
        }

    }

    vector<int> ret;
    for(auto x: m){
        ret.push_back(x.second);
    }
    return ret;
}
