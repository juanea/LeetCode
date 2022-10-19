#include <iostream>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createNode(int data)
{
  TreeNode *newNode = new TreeNode();
  newNode->val = data;
  newNode->left = newNode->right = nullptr;
  return newNode;
};

class Solution
{
public:
  TreeNode *searchBST(TreeNode *root, int val)
  {
    if (root == nullptr || root->val == val)
      return root;
    if (root->val < val)
      return searchBST(root->right, val);
    return searchBST(root->left, val);
  }
  TreeNode *printTree(TreeNode *root)
  {
    if (root == nullptr)
      return root;
    std::cout << root->val << std::endl;
    printTree(root->left);
    printTree(root->right);
  }
};

int main()
{
  TreeNode *root = createNode(4);
  root->left = createNode(2);
  root->right = createNode(7);

  root->left->left = createNode(1);
  root->left->right = createNode(3);

  Solution obj;

  TreeNode *temp = obj.searchBST(root, 2);
  obj.printTree(temp);
  return 0;
}