#include<iostream>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;
class Node{
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data){
    this->data = data;
  }
};

class Pair {
public:
  Node* node = nullptr;
  int state = 0;
  Pair(){}
  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
  }
};

int idx = 0;
Node* constructTree(vector<int>& arr){
    if (idx == arr.size() || arr[idx] == -1){
    idx++;
    return nullptr;
  }Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

void display(Node* node){
  if (node == nullptr)
    return;
  string str = "";
  str += node->left != nullptr ? to_string(node->left->data) : ".";
  str += " <- " + to_string(node->data) + " -> ";
  str += node->right != nullptr ? to_string(node->right->data) : ".";
  cout << str << endl;
  display(node->left);
  display(node->right);
}

void levelOrder(Node* node) {
  // write your code here
    stack<Pair> st;
    st.emplace(node, 1);
    string pre, in, post;

    while(!st.empty()){
        Pair top = st.top();

        if(top.state == 1){
            pre += to_string(top.data) + " ";
            top.state++;
            if(top->left){
                st.emplace(top.node->left, 1);
            }

        } else if(top.state == 2){
            in += to_string(top.data) + " ";
            top.state++;
            if(top->right){
                st.emplace(top.node->right, 2);
            }
        } else if(top.state == 3){
            post += to_string(top.data) + " ";
            st.pop();
        }
    }

    cout << pre << "\n" << in << "\n" << post << "\n";  
}
/*

  queue<Node*> q;
  q.push(node);
  int n = 1;
  while(!q.empty()){
    n = q.size();
    while(n--){
      Node *tp = q.front();
      q.pop();
      cout << tp->data << " ";
      if(tp->left) q.push(tp->left);
      if(tp->right) q.push(tp->right);
    }
    cout << endl;
  }
*/
int main(){
    int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    if (temp == "n"){
      arr[i] = -1;
    }else{
      arr[i] = stoi(temp);
    }
  }
  Node* root = constructTree(arr);
  levelOrder(root);
}

