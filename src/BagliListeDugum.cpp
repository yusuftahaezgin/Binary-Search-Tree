// @file         BagliListeDugum.cpp
// @description  ağaçları tutan bağlı listenin düğüm sınıfı
// @course       2. Öğretim B grubu
// @assignment   2.Ödev
// @date         25.12.2024
// @author       Yusuf Taha Ezgin - yusuf.ezgin@ogr.sakarya.edu.tr

#include "BagliListeDugum.hpp"
#include <iostream>
using namespace std;

BagliListeDugum::BagliListeDugum(BST* ilk){
	ilkEleman=ilk;
	sonraki=0;
}