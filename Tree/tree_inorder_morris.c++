//http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
/*
struct TreeNode {
2     int val;
3     TreeNode *left;
4     TreeNode *right;
5     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
6 };
*/

/*
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。
*/


void inorderMorrisTraversal(TreeNode *root) {
    TreeNode *cur = root, *prev = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)          // 1.
        {
            printf("%d ", cur->val);
            cur = cur->right;
        }
        else
        {
            // find predecessor
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)   // 2.a)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else                       // 2.b)
            {
                prev->right = NULL;
                printf("%d ", cur->val);
                cur = cur->right;
            }
        }
    }
}

/*
空间复杂度：O(1)，因为只用了两个辅助指针。

时间复杂度：O(n)。证明时间复杂度为O(n)，最大的疑惑在于寻找中序遍历下二叉树中所有节点的前驱节点的时间复杂度是多少，
即以下两行代码：

1 while (prev->right != NULL && prev->right != cur)
2     prev = prev->right;

直觉上，认为它的复杂度是O(nlgn)，因为找单个节点的前驱节点与树的高度有关。
但事实上，寻找所有节点的前驱节点只需要O(n)时间。n个节点的二叉树中一共有n-1条边，整个过程中每条边最多只走2次，
一次是为了定位到某个节点，另一次是为了寻找上面某个节点的前驱节点，
如下图所示，其中红色是为了定位到某个节点，黑色线是为了找到前驱节点。所以复杂度为O(n)。
*/
