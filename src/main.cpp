// @file         main.cpp
// @description  Main
// @course       2. Öğretim B grubu
// @assignment   2.Ödev
// @date         25.12.2024
// @author       Yusuf Taha Ezgin - yusuf.ezgin@ogr.sakarya.edu.tr

#include "BST.hpp"
#include "BagliListe.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void DosyaOku(const string& dosyaAdi, BagliListe* liste){
    ifstream file(dosyaAdi);

    if (!file.is_open()) {
        cout << "Dosya açma başarısız." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        BST* agac = new BST();
        istringstream ss(line);
        char ch;
        //cout<<liste->satirSayisi<<" ";
        while (ss >> ch) {
            agac->ekle(ch);
            //cout<<dliste->genSayisi<<" ";   
        }
        //cout<<endl;
		//cout << "Kok dugum adresi: " << agac->getKok() << endl;
        liste->ekle(agac);   
    }
    file.close();
}

int main(){

	BagliListe* liste = new BagliListe();
	DosyaOku(".\\doc\\agaclar.txt", liste);
    cout<<*liste; 

    delete liste;
    return 0;
}