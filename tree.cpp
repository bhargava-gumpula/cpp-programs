#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* AddNode(Node* root, int value) {
    Node* temp_root = root;
    if (root == NULL) {
        root = (Node*) malloc(sizeof(Node));
        
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }

    else {  // root != NULL
        while (true) {
            if (root->value > value) {
                if (root->left != nullptr) {
                    root = root->left;
                    continue;
                }
                
            }
            else {
                if (root->right != nullptr) {
                    root = root->right;
                    continue;
                }
            }
            break;
        }
        Node* temp_node = (Node*) malloc(sizeof(Node));
        temp_node->value = value;
        temp_node->left = nullptr;
        temp_node->right = nullptr;

        if (root->value > value) {
            root->left = temp_node;
        }
        else {
            root->right = temp_node;
        }
        return temp_root;
    }
}   

void DisplayTreeInOrder(Node* root) {
  if (root == NULL) {
    return;
  }

  DisplayTreeInOrder(root->left);
  cout << root->value << " ";
  DisplayTreeInOrder(root->right);

}

void DisplayTreePreOrder(Node* root) {
  if (root == NULL) {
    return;
  }

  cout << root->value << " ";
  DisplayTreePreOrder(root->left);
  DisplayTreePreOrder(root->right);

}

void DisplayTreePostOrder(Node* root) {
  if (root == NULL) {
    return;
  }

  DisplayTreePostOrder(root->left);
  DisplayTreePostOrder(root->right);
  cout << root->value << " ";

}

int main (void) {
    Node* root = NULL;
    root = AddNode(root, 50);
    root = AddNode(root, 25);
    root = AddNode(root, 30);
    root = AddNode(root, 60);
    root = AddNode(root, 55);
    root = AddNode(root, 35);

    DisplayTreeInOrder(root);
    cout << endl;
    DisplayTreePreOrder(root);
    cout << endl;
    DisplayTreePostOrder(root);
}
