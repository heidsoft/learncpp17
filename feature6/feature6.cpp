//
// Created by Jake liu on 2024/3/17.
// B+树

#include <stdio.h>
#include <stdlib.h>

// 定义 B+ 树节点结构体
struct BTreeNode {
    int data;
    struct BTreeNode* left;
    struct BTreeNode* right;
    struct BTreeNode* parent;
};

// 创建 B+ 树节点
struct BTreeNode* createNode(int data) {
    struct BTreeNode* node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    if (node == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

// 插入节点
void insertNode(struct BTreeNode** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    if (data < (*root)->data) {
        insertNode(&(*root)->left, data);
    } else if (data > (*root)->data) {
        insertNode(&(*root)->right, data);
    }
}

// 中序遍历
void inorderTraversal(struct BTreeNode* root) {
    if (root!= NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// 查找最小值节点
struct BTreeNode* findMinNode(struct BTreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    struct BTreeNode* current = root;
    while (current->left!= NULL) {
        current = current->left;
    }
    return current;
}

// 查找后继节点
struct BTreeNode* findSuccessor(struct BTreeNode* root) {
    struct BTreeNode* current = root->right;
    while (current->left!= NULL) {
        current = current->left;
    }
    return current;
}

// 删除节点
void deleteNode(struct BTreeNode** root, int data) {
    if (*root == NULL) {
        return;
    }
    if (data < (*root)->data) {
        deleteNode(&(*root)->left, data);
    } else if (data > (*root)->data) {
        deleteNode(&(*root)->right, data);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
            return;
        } else if ((*root)->left == NULL) {
            struct BTreeNode* rightChild = (*root)->right;
            free(*root);
            *root = rightChild;
            rightChild->parent = NULL;
            return;
        } else if ((*root)->right == NULL) {
            struct BTreeNode* leftChild = (*root)->left;
            free(*root);
            *root = leftChild;
            leftChild->parent = NULL;
            return;
        } else {
            struct BTreeNode* successor = findSuccessor(*root);
            successor->left = (*root)->left;
            successor->parent = (*root)->parent;
            if ((*root)->parent == NULL) {
                *root = successor;
            } else if (data < (*root)->parent->data) {
                (*root)->parent->left = successor;
            } else {
                (*root)->parent->right = successor;
            }
            free(*root);
        }
    }
}



// 初始化 B+ 树
void createBTree(struct BTreeNode** root) {
    *root = NULL;
    insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 30);
    insertNode(root, 40);
    insertNode(root, 50);
    insertNode(root, 25);
    insertNode(root, 35);
    insertNode(root, 45);
    insertNode(root, 55);
}

int main() {
    struct BTreeNode* root = NULL;
    createBTree(&root);

    printf("中序遍历：");
    inorderTraversal(root);

    struct BTreeNode* minNode = findMinNode(root);
    printf("最小值节点：%d\n", minNode->data);

    printf("删除节点 35：");
    deleteNode(&root, 35);
    inorderTraversal(root);

    return 0;
}