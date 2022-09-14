#include <iostream>
#include "bstree.h"

using namespace std;


int main()
{

    Btree Bt;
    Bt.create_file();
    int root = 5;
    Bt.insert(root);
    /*
    null_ = to_string(root); // Obtain an adequate space for null_ values
    for (int i = 0; i < null_.size(); i++)
    {
        null_[i] = '.';
    }
    */
    Bt.insert(4);
    Bt.insert(10);
    Bt.insert(200);
    Bt.insert(2000);
    Bt.insert(-2);
    Bt.insert(-10);
    Bt.insert(-600);
    cout << "Tree height: " << Bt.height(Bt.root) << "\n\n"  ;
    Bt.tree_h << "Tree height: " << Bt.height(Bt.root) << "\n\n";
    Bt.tree_v << "Tree height: " << Bt.height(Bt.root) << "\n\n";

    Bt.print_ver(Bt.root, 0);
    cout << "\n\n\n";
    Bt.print_hor(Bt.root);

    return 0;
}