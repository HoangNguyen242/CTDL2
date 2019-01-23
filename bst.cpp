#include <iostream>
using namespace std;
#include "tree.h"
int main()
{
        Tree<int> t;
        t.AddChild(10);
        t.AddChild(16);
        t.AddChild(2);
        t.AddChild(8);
        t.AddChild(13);
        //t.AddChild(15);
        //t.AddChild(11);
        // t.AddChild(9);
        // t.AddChild(19);
        // t.AddChild(7);
        //t.InOrder();
        t.PreOrder();
        //t.PostOrder();
        t.remove(13);
        t.PreOrder();
        return 0;
}