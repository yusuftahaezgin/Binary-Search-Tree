// @file         BST.cpp
// @description  ikili arama ağacı sınıfı
// @course       2. Öğretim B grubu
// @assignment   2.Ödev
// @date         25.12.2024
// @author       Yusuf Taha Ezgin - yusuf.ezgin@ogr.sakarya.edu.tr

#include "BST.hpp"
BST::BST(){
	kok=0;
}

BSTDugum* BST::getKok() const {
    return kok;
}

int BST::yukseklik(){
	return yukseklik(kok);
}

int BST::yukseklik(BSTDugum *kok){
	if(kok==NULL) return -1;
	return 1+max(yukseklik(kok->sol),yukseklik(kok->sag));
}

bool BST::bul(char veri){
    return bul(veri,kok);
}

bool BST::bul(char arananVeri,BSTDugum* aktifDugum){
    if(aktifDugum==NULL) return false;
	else if(arananVeri < aktifDugum->veri)
		bul(arananVeri,aktifDugum->sol);
	else if(arananVeri > aktifDugum->veri)
		bul(arananVeri,aktifDugum->sag);
	else return true;
}

void BST::ekle(char veri){
    if (kok == nullptr) {
        kok = new BSTDugum(veri);
    } else {
        return ekle(veri, kok);
    }

}
void BST::ekle(char veri,BSTDugum* &aktifDugum){
    if(aktifDugum==NULL) aktifDugum=new BSTDugum(veri);
	else if(veri < aktifDugum->veri)
		ekle(veri,aktifDugum->sol);
	else if(veri > aktifDugum->veri)
		ekle(veri,aktifDugum->sag);
	else return;
}


void BST::levelorder(BSTDugum* kok) {
	if(kok==0) return;
    int h = yukseklik();
    for (int level = 0; level <= h; level++) {
        int boslukSol = pow(2, h - level + 1) - 1;
        int araBosluk = pow(2, h - level + 2) - 1;
        PrintLevel(kok, level, boslukSol, araBosluk);
        cout << endl;
		noktaYazdir(kok, level, boslukSol, araBosluk);
		cout<<endl;
		altNoktaYazdir(kok, level, boslukSol, araBosluk);
		cout<<endl;
    }
}

void BST::PrintLevel(BSTDugum* kok, int level, int boslukSol, int araBosluk) {
    if (level == 0) { 
        for (int i = 0; i < boslukSol; i++) cout << " ";  // Sol boşluk
        if (kok != NULL)
            cout << kok->veri;
        else
            cout << " ";  // Boş düğüm
    } else {
        if (kok == NULL) {
            // herhangi bir seviyedeki düğüm yoksa bile onun yerine de yine boşluk ekledim simetrik olması için
            PrintLevel(NULL, level - 1, boslukSol, araBosluk);
            PrintLevel(NULL, level - 1, araBosluk, araBosluk);
        } else {
            PrintLevel(kok->sol, level - 1, boslukSol, araBosluk);
            PrintLevel(kok->sag, level - 1, araBosluk, araBosluk);
        }
    }
}

void BST::noktaYazdir(BSTDugum* kok, int level, int boslukSol, int araBosluk) {// tam yapamadım noktaları yazdırma kısmını
    if (level == 0) {
        if (kok == NULL) {
            for (int i = 0; i < boslukSol*2+1; i++) cout << " ";
        } else {
            if (kok->sol != NULL) {
                for (int i = 0; i < boslukSol / 2; i++) cout << " ";
                cout<<".";
                for (int i = 0; i < (boslukSol / 2); i++) cout << ".";
                cout<<".";
                if (kok->sag != NULL) {
                    for (int i = 0; i < (boslukSol / 2); i++) cout << ".";
                    cout<<".";
                } else {
                    for (int i = 0; i < boslukSol; i++) cout << " ";
                    cout<<" ";
                }
            }
            else if (kok->sag != NULL) {
                for (int i = 0; i < (boslukSol / 2) ; i++) cout << " ";
                cout<<" ";
                for (int i = 0; i < (boslukSol / 2); i++) cout << " ";
                cout<<".";
                for (int i = 0; i < (boslukSol / 2); i++) cout << ".";
                cout<<".";
            }
            else{
                 for (int i = 0; i < (boslukSol / 2) ; i++) cout << " ";
                cout<<" ";
                for (int i = 0; i < (boslukSol / 2); i++) cout << " ";
                cout<<" ";
                for (int i = 0; i < (boslukSol / 2); i++) cout << " ";
                cout<<" ";
            }
        }
    } else {
        if (kok == NULL) {
            noktaYazdir(NULL, level - 1, boslukSol, araBosluk);
            noktaYazdir(NULL, level - 1, araBosluk, araBosluk);
        } else {
            noktaYazdir(kok->sol, level - 1, boslukSol, araBosluk);
            noktaYazdir(kok->sag, level - 1, boslukSol, araBosluk);
        }
    }
}

void BST::altNoktaYazdir(BSTDugum* kok, int level, int boslukSol, int araBosluk) {// tam yapamadım noktaları yazdırma kısmını
    if (kok == NULL) return; 
    
    if (level == 0) { 
        for (int i = 0; i < boslukSol / 2; i++) cout << " ";  // Sol boşluk
        if (kok->sol != NULL) {
            cout << ".";
        } else {
            cout << " ";
        }
        for (int i = 0; i < araBosluk / 2; i++) cout << " ";
        if (kok->sag != NULL) {
            cout << ".";
        } else {
            cout << " ";
        }
    } else {
        altNoktaYazdir(kok->sol, level - 1, boslukSol, araBosluk);
        altNoktaYazdir(kok->sag, level - 1, araBosluk, araBosluk);
    }
}


void BST::aynalama(BSTDugum* kok) {
    if (kok == NULL) return;

    BSTDugum* temp = kok->sol;
    kok->sol = kok->sag;
    kok->sag = temp;

    aynalama(kok->sol);
    aynalama(kok->sag);
}
void BST::aynalama() {
    return aynalama(kok);
}


int BST::degerHesapla(BSTDugum* kok,bool solMu) {
	if (kok == NULL) return 0;
	
    int toplamDeger = 0;
	if(solMu==true)
	{
		toplamDeger=2*kok->veri;
	}
	else{
		toplamDeger=kok->veri;
	}

    toplamDeger += degerHesapla(kok->sol, true);   
    toplamDeger += degerHesapla(kok->sag, false); 

    return toplamDeger;
}

int BST::degerHesapla() {
    return degerHesapla(kok,false);
}

void BST::levelorder(){
	return levelorder(kok);
}

		
void BST::DugumSil(BSTDugum* &kok){
	BSTDugum* silinecek =kok;
	if(kok->sag==NULL) kok=kok->sol;
	else if(kok->sol==NULL) kok=kok->sag;
	else{
		silinecek=kok->sol;
		BSTDugum *parent=kok;
		while(silinecek->sag!=NULL){
			parent=silinecek;
			silinecek=silinecek->sag;
		}
		kok->veri=silinecek->veri;
		if(parent==kok) kok->sol=silinecek->sol;
		else parent->sag=silinecek->sol; 
	}
	delete silinecek;
}

bool BST::bosMu(){
	return kok==NULL;
}
		

void BST::Temizle(){
	while(!bosMu()) DugumSil(kok);
}

BST::~BST(){
	Temizle();
}