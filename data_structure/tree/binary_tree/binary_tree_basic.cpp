//
// Created by thomas on 20-3-27.
//

#include "binary_tree_basic.h"
#include "stdio.h"
#include "stdint.h"

BinTNode binTree;

void InitBinTree(BinTree root)
{
    root = NULL;
}

BinTree BuildBinTree(THeroType value, BinTree right, BinTree left)
{
    BinTree tree;
    tree = (BinTree)malloc(sizeof(BinTNode));

    if(tree == NULL)
    {
        printf("Error: generate failed!");
        return NULL;
    }

    tree->value = value;
    tree->left = left;
    tree->right = right;

    return tree;
}


BinTree AddNode(BinTNode* pRoot, THeroType value)
{
    BinTree tree;
    tree = (BinTree)malloc(sizeof(BinTNode));
    if(tree == NULL)
    {
        printf("Error: generate failed!");
        return NULL;
    }

    tree->value = value;
    int insertFlag = 0;

    BinTree pCurrentNode;
    if(pRoot == NULL)
    {
        pRoot = tree;
    }else{
        pCurrentNode = pRoot;
        while (!insertFlag)
        {
            if(value < pCurrentNode->value)
            {
                if(pCurrentNode->left == nullptr)
                {
                    pCurrentNode->left = tree;
                    insertFlag = 1;
                } else{
                    pCurrentNode = pCurrentNode->left;
                }
            }else{
                if(pCurrentNode->right == nullptr)
                {
                    pCurrentNode->right = tree;
                    insertFlag = 1;
                } else{
                    pCurrentNode = pCurrentNode->right;
                }
            }
        }
    }

}

void genericTree(BinTree root, float* pData)
{
    for(int i=0;i<sizeof(pData);i++)
    {
        AddNode(root,pData[i]);
    }
}

void traverse(BinTree root, ){
    printf("%f \n",root->value);
    if(root->right != NULL)
    {
        traverse(root->right);
    }

    if(root->left != NULL)
    {
        traverse(root->left);
    }
}

void calLeaves(BinTree root, int& cnt){
    if(root == NULL){return ;}

    cnt++;
    if(root->left == NULL && root->right == NULL){
        return ;
    }

    if(root->left != NULL)
    {
        calLeaves(root->left,cnt);
    }

    if(root->right != NULL)
    {
        calLeaves(root->right,cnt);
    }

    return;
}

int calDepth(BinTree root){
    int rdepth = 0; //根节点深度 

    int lval = 0; //左子树深度 
    int rval = 0; //右子树深度 

    if(!root) //当到达叶子节点的左子树或右子树或整棵树为空树时 
    {
        rdepth=-1;
    }
    else
    {
        lval = calDepth(root->left);//遍历左子树 
        rval = calDepth(root->right); //遍历右子树

        rdepth=1+(lval>rval?lval:rval);
    }

    return rdepth;
}


float data[10] = {0,1,3,7,1,2,4,0,6,9};
int main(void)
{
    printf("Hello this is binary tree basic!\n");
    InitBinTree(&binTree);

    genericTree(&binTree, data);
    traverse(&binTree);

    int nodeCnt = 0;
    calLeaves(&binTree,nodeCnt);
    printf("%d \n",nodeCnt);

    int depth = calDepth(&binTree);
    printf("%d \n",depth);


}

