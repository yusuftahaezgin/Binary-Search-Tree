#ifndef BST_HPP
#define BST_HPP

#include "BSTDugum.hpp"
#include <cmath>
#include <iomanip>
class BST{
public:
	BST();
	~BST();

	void ekle(char veri);
	bool bul(char veri);
	void aynalama();
	int degerHesapla();
	void levelorder();
	int yukseklik();
	void Temizle();
	bool bosMu();
	BSTDugum* getKok() const; //kokun get fonksiyonu
private:
	BSTDugum* kok;
	void aynalama(BSTDugum* kok);
	int degerHesapla(BSTDugum* kok,bool solMu);
	void yazdirGorsel(BSTDugum* kok);
	void PrintLevel(BSTDugum* kok, int level, int boslukSol, int araBosluk);
	void noktaYazdir(BSTDugum* kok, int level, int boslukSol, int araBosluk);
	void altNoktaYazdir(BSTDugum* kok, int level, int boslukSol, int araBosluk);
	void levelorder(BSTDugum* kok);
	int yukseklik(BSTDugum *kok);
	void DugumSil(BSTDugum* &kok);
	bool bul(char veri,BSTDugum* aktifDugum);	
	void ekle(char veri,BSTDugum* &aktifDugum);
};

#endif