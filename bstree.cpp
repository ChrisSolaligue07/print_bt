#include "bstree.h"
#include <iostream>

Btree::Btree()
{
    root = nullptr;
}

bool Btree::find(BTnode *&tmp, BTnode *&node_ant, int val)
{
    for (auto i = root; i; tmp = i)
    {
        if (val == i->val)
        {
            return false;
        }
        node_ant = i;
        i = (val < i->val) ? i->izq : i = i->der;
    }
    return true;
}

void Btree::insert(int val)
{
    if (root == nullptr)
    {
        root = new BTnode(val);
        return;
    }
    else
    {
        BTnode *node = nullptr;
        BTnode *node_ant = nullptr;
        if (find(node, node_ant, val))
        {
            node = new BTnode(val);
            if (val < node_ant->val)
            {
                node_ant->izq = node;
                return;
            }
            else if (val > node_ant->val)
            {
                node_ant->der = node;
                return;
            }
            return;
        }
        else
        {
            std::cout << "El dato existe" << std::endl;
            return;
        }
    }
}

int Btree::height(BTnode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        int leftHeight = height(node->izq);
        int rightHeight = height(node->der);
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

void Btree::print_ver(BTnode *root, int spacesi)
{
    if (root == nullptr) {
        return;
    }
    spacesi += globalspace;
    print_ver(root->der, spacesi);
    std::cout << std::endl;
    tree_v << std::endl;
    for (int i = globalspace; i < spacesi; i++)
    {
        std::cout << " ";
        tree_v << " ";
    }
    std::cout << root->val << std::endl;
    tree_v << root->val << std::endl;
    print_ver(root->izq, spacesi);
}

void Btree::print_hor(BTnode *node, int i, int alt_actual, int &spacesi, int &spacesii)
{
    if (i == alt_actual)
    {
        if (node != nullptr)
        {
            tree_h << std::setw(spacesi) << node->val;
            std::cout << std::setw(spacesi) << node->val;
        }
        else
        {
            tree_h << std::setw(spacesi) << "...";
            std::cout << std::setw(spacesi) << "...";
        }
        spacesi = spacesii;
        return;
    }
    else
    {
        if (node == nullptr)
        {
            print_hor(node, i + 1, alt_actual, spacesi, spacesii);
            print_hor(node, i + 1, alt_actual, spacesi, spacesii);
            return;
        }
        print_hor(node->izq, i + 1, alt_actual, spacesi, spacesii);
        print_hor(node->der, i + 1, alt_actual, spacesi, spacesii);
    }
}

void Btree::print_hor(BTnode *root)
{
    int alt = height(root);
    int j = -1;
    int ji = -2;
    for (int i = 0; i < alt; i++)
    {
        int a = pow(2, alt - (j++));  // j = j + 1;
        int b = pow(2, alt - (ji++)); // ji = ji + 1;
        print_hor(root, 1, i + 1, a, b);
        std::cout << "\n";
        tree_h << "\n";
    }
}

void Btree::create_file()
{
    tree_h.open("horizontal_tree.txt");
    tree_v.open("vertical_tree.txt");
}