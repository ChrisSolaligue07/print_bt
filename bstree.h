//
// Created by chris on 14/09/2022.
//

#ifndef PRINT_TREE_BSTREE_H
#define PRINT_TREE_BSTREE_H
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <queue>



#define globalspace 5
//std::ofstream tree_h;
//std::ofstream tree_v;
//std::string null_;

struct BTnode
{
    int val;
    BTnode *izq;
    BTnode *der;
    BTnode(int val)
    {
        this->val = val;
        izq = nullptr;
        der = nullptr;
    }
};

class Btree
{
public:
    BTnode *root;
    Btree();
    bool find(BTnode *&tmp, BTnode *&node_ant, int val);
    void insert(int val);
    int height(BTnode *node);

    void print_ver(BTnode *root, int spacesi);
    void print_hor(BTnode *node, int i, int alt_actual, int &spacesi, int &spacesii);
    void print_hor(BTnode *root);

    void create_file();

    std::ofstream tree_h;
    std::ofstream tree_v;
};
#endif //PRINT_TREE_BSTREE_H
