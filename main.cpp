#include <iostream>

struct node
{
    node* right;
    node* left;
    int value;
};

class binaryTree
{
public:
    binaryTree() {
        root = nullptr;
    };

    void add(int value)
    {
        if (root == nullptr) {
            root = new node();
            root->value = value;
            return;
        }

        node* current = root;
        node* previous;

        while (current != nullptr)
        {
            previous = current;
            if (current->value > value)
                current = current->left;
            else if (current->value < value)
                current = current->right;
            else
                break;
        }

        if (value > previous->value)
        {
            previous->right = new node();
            previous->right->value = value;
        }
        else if (value < previous->value)
        {
            previous->left = new node();
            previous->left->value = value;
        }
    }

    static void printSubtree(node *currentNode)
    {
        if(currentNode->left != nullptr)
            printSubtree(currentNode->left);

        std::cout << currentNode->value << " ";

        if(currentNode->right != nullptr)
            printSubtree(currentNode->right);
    }

    void print()
    {
        printSubtree(root);
    }
private:
    node *root;
};

int main() {
    binaryTree* tree = new binaryTree();

    int number;
    std::cout << "Enter numbers (enter 0 to finish):\n";
    std::cin >> number;
    while (number != 0)
    {
        tree->add(number);
        std::cin >> number;
    }

    std::cout << "Sorted numbers: ";
    tree->print();

    delete tree;
    return 0;
}
