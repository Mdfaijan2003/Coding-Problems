/*Given a binary tree, determine if it is height-balanced.
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
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
int postOrder(TreeNode *root)
{
  if (!root)
    return 0;

  // 1. Left
  int leftHeight = postOrder(root->left);
  if (leftHeight == -1)
    return -1;

  // 2. Right
  int rightHeight = postOrder(root->right);
  if (rightHeight == -1)
    return -1;

  // 3. Root (check balance)
  if (abs(leftHeight - rightHeight) > 1)
    return -1;

  return 1 + max(leftHeight, rightHeight);
}
bool isBalanced(TreeNode *root)
{
  return postOrder(root) != -1;
}
int main()
{

  return 0;
}