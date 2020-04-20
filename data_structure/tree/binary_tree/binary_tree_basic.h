//
// Created by thomas on 20-3-27.
//

#ifndef BASICALGORITHM_BINARY_TREE_BASIC_H
#define BASICALGORITHM_BINARY_TREE_BASIC_H
#include<stdlib.h>

typedef float THeroType;

typedef struct BinTNode{
    THeroType value;
    int       flag;

    BinTNode* left;
    BinTNode* right;
}BinTNode,*BinTree;



#endif //BASICALGORITHM_BINARY_TREE_BASIC_H
