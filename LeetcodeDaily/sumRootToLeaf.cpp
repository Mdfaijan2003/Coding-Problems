#include <bits/stdc++.h>
using namespace std;
int dfs(TreeNode *node, int curr)
{
  if (node == nullptr)
    return 0;

  curr = (curr << 1) | node->val;
  if (node->left == nullptr && node->right == nullptr)
    return curr;

  return dfs(node->left, curr) + dfs(node->right, curr);
}
int sumRootToLeaf(TreeNode *root)
{
  if (root == nullptr)
    return 0;

  return dfs(root, 0);
}
int main()
{

  return 0;
}