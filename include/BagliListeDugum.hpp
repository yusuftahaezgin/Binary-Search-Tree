#ifndef BagliListeDugum_hpp
#define BagliListeDugum_hpp

#include <iostream>
#include "BST.hpp"

using namespace std;

class BagliListeDugum{// her bir satirdaki agacin ilk elemanin adresini veri olarak tutan bagli liste 

public: 
    BagliListeDugum(BST* ilk);
    BST* ilkEleman;
    BagliListeDugum* sonraki;
};


#endif