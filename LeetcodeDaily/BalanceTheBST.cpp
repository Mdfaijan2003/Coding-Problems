
/*1382. Balance a Binary Search Tree

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int val;

  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Approach --> Find the inorder then apply partition in the inorder to get the balanced bst.

void inOrderTraversal(TreeNode *root, vector<int> &inorder)
{
  if (root == nullptr)
    return;

  TreeNode *current = root;
  inOrderTraversal(current->left, inorder);
  inorder.push_back(current->val);
  inOrderTraversal(current->right, inorder);
}
TreeNode *constructBST(int low, int high, vector<int> &inorder)
{
  if (low > high)
    return nullptr;
  int mid = high - (low + high) / 2;
  TreeNode *root = new TreeNode(inorder[mid]);
  root->left = constructBST(low, mid - 1, inorder);
  root->right = constructBST(mid + 1, high, inorder);
  return root;
}
TreeNode *balanceBST(TreeNode *root)
{
  if (root == nullptr)
    return nullptr;
  vector<int> inorder;
  inOrderTraversal(root, inorder);
  TreeNode *res = constructBST(0,inorder.size(), inorder);

  return res;
}
int main()
{

  return 0;
}