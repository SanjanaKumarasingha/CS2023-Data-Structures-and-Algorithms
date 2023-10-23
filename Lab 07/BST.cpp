#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  // If root is null return nothing
  if (root == NULL)
    return;
  // first recursion on left child
  traverseInOrder(root->left);
  // Then print the data of the root
  printf("%d " , root->key);
  // After that recursion on right child
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  // If the tree is empty, create a new node and return it
  if (node == NULL) {
    struct node *New_Node = (struct node*) malloc(sizeof(struct node));
    New_Node->key = key;
    New_Node->left = NULL;
    New_Node->right = NULL;
    return New_Node;
  }

  // If the key is less than the node's key, insert it into the left subtree
  if (key < node->key) {
    node->left = insertNode(node->left, key);
  }
  // If the key is greater than the node's key, insert it into the right subtree
  else if (key > node->key) {
    node->right = insertNode(node->right, key);
  }

  // Return the (unchanged) node pointer
  return node;
}

// Helper function to find the node with Maximum key in a subtree
struct node *findMax(struct node *node) {
  struct node *current = node;
  while (current && current->right != NULL) {
    current = current->right;
  }
  return current;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Base case: if the root is null, the key doesn't exist in the tree
  if (root == NULL) {
    return root;
  }

  // If the key is smaller than the root's key, it lies in left subtree
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  }
  // If the key is greater than the root's key, it lies in right subtree
  else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  }
  // If the key is same as root's key, this is the node to be deleted
  else {
    // Case 1: Node has no children or only one child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    // Case 2: Node has two children
    struct node *temp = findMax(root->left);
    root->key = temp->key;
    root->left = deleteNode(root->left, temp->key);
  }
  return root;
}


// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}