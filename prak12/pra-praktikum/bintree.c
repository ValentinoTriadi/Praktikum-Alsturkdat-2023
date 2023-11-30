#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
    BinTree new = (Address) malloc (sizeof(TreeNode));
    if (new != NULL){
        ROOT(new) = root;
        LEFT(new) = left_tree;
        RIGHT(new) = right_tree;
    }
    return new;
}
void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p = NewTree(root,left_tree,right_tree);
}
Address newTreeNode(ElType val){
    Address p = (Address) malloc (sizeof(TreeNode));
    if (p != NULL){
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}
void deallocTreeNode (Address p){
    free(p);
}
boolean isTreeEmpty (BinTree p){
    return (p == NULL);
}
boolean isOneElmt (BinTree p){
    if (isTreeEmpty(p)) return false;
    return (RIGHT(p) == NULL && LEFT(p) == NULL);
}
boolean isUnerLeft (BinTree p){
    return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)));
}
boolean isUnerRight (BinTree p){
    return (!isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}
boolean isBinary (BinTree p){
    return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}
void printPreorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)){
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}
void printInorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)){
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}
void printPostorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)){
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}
void printTree(BinTree p, int h){
    int i;
    if (!isTreeEmpty(p)){
        printf("%d\n", ROOT(p));
        printTreeNow(LEFT(p),h,h);
        printTreeNow(RIGHT(p),h,h);
    }
}
void printTreeNow(BinTree p, int h, int now){
    if (!isTreeEmpty(p)){
        for (int i = 0; i < now; i++){
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        printTreeNow(LEFT(p),h,h+now);
        printTreeNow(RIGHT(p),h,h+now);
    }
}