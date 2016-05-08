/*======================================================
    > File Name: bit_tree.cpp
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月14日 星期四 09时18分53秒
 =======================================================*/

#include<iostream>
#include<stdlib.h>

typedef struct TreeNode
{
    char              value;
    struct TreeNode   *Lchild;
    struct TreeNode   *Rchild;
}TreeNode;

class BitTree
{
public:
    void createBitTree(TreeNode **root)
    {
        if(!root)
            return;
        char  ch;
        std::cin>>ch;
        if(ch == '#')
            *root = NULL;
        else
        {
            *root = (TreeNode*)malloc(sizeof(TreeNode)); 
            (*root)->value = ch;
            createBitTree(&((*root)->Lchild));
            createBitTree(&((*root)->Rchild));
        }  
    }
    void PreOrder(TreeNode *root)
    {
        if(root)
        {
            std::cout<<root->value<<" ";
            PreOrder(root->Lchild);
            PreOrder(root->Rchild);
        }
    }
    int BitTreeHigh(TreeNode *root)
    {
        int   h1=0,h2=0;
        if(!root)
            return 0;
        else
        {
            h1 = BitTreeHigh(root->Lchild);
            h2 = BitTreeHigh(root->Rchild);
            return h1 > h2 ? (h1+1):(h2+1);
        }
    }
};

int main()
{
    TreeNode *root;
    BitTree  tree;
    tree.createBitTree(&root);
    tree.PreOrder(root);
    std::cout<<tree.BitTreeHigh(root);
    return 0;
}
