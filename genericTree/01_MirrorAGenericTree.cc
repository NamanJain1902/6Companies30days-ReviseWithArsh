#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Node

{

public:

  int data = 0;

  vector<Node *> children;



  Node(int data)

  {

    this->data = data;

  }

};

void display(Node *node)
{
  string s = "";
  s += to_string(node->data) + " -> ";
  for (Node *child : node->children)
  {
    s += to_string(child->data) + ", ";
  }

  cout << s << "." << endl;

  for (Node *child : node->children)
  {
    display(child);
  }
}

Node *constructor01(vector<int> &arr)

{

  if (arr.size() == 0)

    return NULL;



  vector<Node *> stack;

  stack.push_back(new Node(arr[0]));



  Node *root = stack[0];



  for (int i = 1; i < arr.size(); i++)

  {

    if (arr[i] != -1)

    {

      Node *node = stack.back();

      Node *nnode = new Node(arr[i]);



      node->children.push_back(nnode);

      stack.push_back(nnode);

    }

    else

      stack.pop_back();

  }

  return root;

}

Node *linearize(Node *node)
{
//   write code here
}

void mirrorTree(Node *node){
    
    for(Node *child: node->children){
        mirrorTree(child);
    }

    reverse(node->children.begin(), node->children.end());
    /*
        int i=0;
        int j = node->children.size();
        while(i < j){
            swap(node->children[i], node->children[j]);
            i++; j--;
        }
    */
}
void solve()
{
    /*
24
10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1
    */
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node * root=constructor01(arr);
    
//  linearize(root);
  
  mirrorTree(root);
  display(root);
}

int main()
{
    solve();
    return 0;
}



