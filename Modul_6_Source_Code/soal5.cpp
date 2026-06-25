#include <iostream>
#include <string>
#include "RedBlackTree.h"
using namespace std;

void preOrder(const RedBlackTree::Node* node) {
    if (node->isNil) return;
    cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(const RedBlackTree::Node* node) {
    if (node->isNil) return;
    inOrder(node->left);
    cout << node->key << " ";
    inOrder(node->right);
}

void postOrder(const RedBlackTree::Node* node) {
    if (node->isNil) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->key << " ";
}

int main() {
    RedBlackTree rbt;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int angka;
        cin >> angka;

        if (!rbt.contains(angka)) {
            rbt.insert(angka);
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        string query;
        cin >> query;

        if (rbt.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan." << endl;
            continue;
        }

        if (query == "PREORDER") {
            cout << "[Preorder] : ";
            preOrder(rbt.root());
            cout << endl;
        }
        else if (query == "INORDER") {
            cout << "[Inorder] : ";
            inOrder(rbt.root());
            cout << endl;
        }
        else if (query == "POSTORDER") {
            cout << "[Postorder] : ";
            postOrder(rbt.root());
            cout << endl;
        }
        else if (query == "ALL") {
            cout << "[Preorder] : ";
            preOrder(rbt.root());
            cout << endl;

            cout << "[Inorder] : ";
            inOrder(rbt.root());
            cout << endl;

            cout << "[Postorder] : ";
            postOrder(rbt.root());
            cout << endl;
        }
    }

    return 0;
}