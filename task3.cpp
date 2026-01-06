#include <iostream>
using namespace std;

/* ================================
   1. CẤU TRÚC NODE & TREE
================================ */

struct TreeNode {
    int val;
    TreeNode* tLeft;
    TreeNode* tRight;
};

typedef TreeNode* Tree;

/* ================================
   2. KHỞI TẠO CÂY
================================ */

void initTree(Tree &tree) {
    tree = NULL;
}

/* ================================
   3. CHÈN NODE (INSERT)
================================ */

int insert(Tree &tree, int x) {
    if (tree != NULL) {
        if (x == tree->val)
            return 0;   // Không cho trùng
        else if (x < tree->val)
            return insert(tree->tLeft, x);
        else
            return insert(tree->tRight, x);
    } else {
        tree = new TreeNode;
        tree->val = x;
        tree->tLeft = tree->tRight = NULL;
        return 1;
    }
}

/* ================================
   4. DUYỆT CÂY
================================ */

// NLR - Preorder
void NLR(Tree tree) {
    if (tree != NULL) {
        cout << tree->val << " ";
        NLR(tree->tLeft);
        NLR(tree->tRight);
    }
}

// LNR - Inorder
void LNR(Tree tree) {
    if (tree != NULL) {
        LNR(tree->tLeft);
        cout << tree->val << " ";
        LNR(tree->tRight);
    }
}

// LRN - Postorder
void LRN(Tree tree) {
    if (tree != NULL) {
        LRN(tree->tLeft);
        LRN(tree->tRight);
        cout << tree->val << " ";
    }
}

/* ================================
   5. TÌM KIẾM
================================ */

Tree search(Tree tree, int x) {
    if (tree == NULL || tree->val == x)
        return tree;
    if (x < tree->val)
        return search(tree->tLeft, x);
    return search(tree->tRight, x);
}

/* ================================
   6. TÌM MIN / MAX
================================ */

Tree findMin(Tree tree) {
    while (tree != NULL && tree->tLeft != NULL)
        tree = tree->tLeft;
    return tree;
}

Tree findMax(Tree tree) {
    while (tree != NULL && tree->tRight != NULL)
        tree = tree->tRight;
    return tree;
}

/* ================================
   7. XÓA NODE
================================ */

Tree deleteNode(Tree tree, int x) {
    if (tree == NULL)
        return tree;

    if (x < tree->val)
        tree->tLeft = deleteNode(tree->tLeft, x);
    else if (x > tree->val)
        tree->tRight = deleteNode(tree->tRight, x);
    else {
        // Node có 0 hoặc 1 con
        if (tree->tLeft == NULL) {
            Tree temp = tree->tRight;
            delete tree;
            return temp;
        } 
        else if (tree->tRight == NULL) {
            Tree temp = tree->tLeft;
            delete tree;
            return temp;
        }

        // Node có 2 con
        Tree temp = findMin(tree->tRight);
        tree->val = temp->val;
        tree->tRight = deleteNode(tree->tRight, temp->val);
    }
    return tree;
}

/* ================================
   8. GIẢI PHÓNG BỘ NHỚ
================================ */

void freeTree(Tree &tree) {
    if (tree != NULL) {
        freeTree(tree->tLeft);
        freeTree(tree->tRight);
        delete tree;
        tree = NULL;
    }
}

/* ================================
   9. HÀM MAIN
================================ */

int main() {
    Tree tree;
    initTree(tree);

    int a[] = {10, 5, 15, 3, 7, 12, 18};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++)
        insert(tree, a[i]);

    cout << "Duyet NLR: ";
    NLR(tree);
    cout << endl;

    cout << "Duyet LNR: ";
    LNR(tree);
    cout << endl;

    cout << "Duyet LRN: ";
    LRN(tree);
    cout << endl;

    int x = 7;
    if (search(tree, x))
        cout << "Tim thay " << x << endl;
    else
        cout << "Khong tim thay " << x << endl;

    cout << "Gia tri nho nhat: " << findMin(tree)->val << endl;
    cout << "Gia tri lon nhat: " << findMax(tree)->val << endl;

    tree = deleteNode(tree, 10);
    cout << "Sau khi xoa 10, LNR: ";
    LNR(tree);
    cout << endl;

    freeTree(tree);
    return 0;
}
