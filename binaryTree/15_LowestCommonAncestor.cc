#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Node{
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data)
  {
    this->data = data;
  }
};

class Pair{
public:
  Node* node = nullptr;
  int state = 0;

  Pair(Node* node, int state)
  {
    this->node = node;
    this->state = state;
  }
};

int idx = 0;
Node* constructTree(vector<int>& arr){

  if (idx == arr.size() || arr[idx] == -1){
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
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
bool find(Node* node, int data){
  // write your code here
  if(node == NULL) return false;
  if(node->data == data) return true;
  if(find(node->left, data)) return true;
  if(find(node->right, data)) return true;
  return false;
}

vector<int> nodeToRootPath(Node* node, int data){
  // write your code here
  if(!node) return {};
  
  if(node->data == data) {return {data};}
  vector<int> lt = nodeToRootPath(node->left, data);
  if(lt.size() > 0) {
    lt.push_back(node->data);
    return lt;
  }
  vector<int> rt = nodeToRootPath(node->right, data);
  if(rt.size() > 0) {
    rt.push_back(node->data);
    return rt;
  }
  return {};
}

int lca(Node *node, int d1, int d2) {
    vector<int> p1 = nodeToRootPath(node, d1);
    vector<int> p2 = nodeToRootPath(node, d2);

    int i = p1.size() - 1;
    int j = p2.size() - 1;

    while(i >=0  and j >= 0 and p1[i] == p2[i]) {
        i--;
        j--;
    }
    i++;
    j++;

    return p1[i];
}

int main(){
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++){
    string temp;
    cin >> temp;
    if (temp == "n"){
      arr[i] = -1;
    }else{
      arr[i] = stoi(temp);
    }
  }

  Node* root = constructTree(arr);
  int data;
  cin >> data;
  bool found = find(root, data);
  found == 1 ? cout << "true" << endl : cout << "false" << endl;
  vector<int> path = nodeToRootPath(root, data);
  cout << "[";
  for (int i = 0; i < path.size(); i++) {
    cout << path[i];
    if (i != path.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;

  int d1, d2;
  cout << "\nEnter two nodes to be considered for findind lowest common ancestor: ";
  cin >> d1 >> d2;
  cout << "\nLowest Common Ancestor of " << d1 << " and " << d2 << " is " << lca(root, d1, d2) << endl;

  return 0;
}
