#ifndef BagliListe_hpp
#define BagliListe_hpp
#include "BagliListeDugum.hpp"
#include "BST.hpp"

class BagliListe{// satırların ilk elemanının adresini veri olarak tutan tek yönlü bağlı liste sınıfı
public:
    BagliListe(); // kurucu fonk
    ~BagliListe();// yok edici fonk (cop kalmamasi icin)
    void ekle(BST* agac);
    void ileriGit(BagliListeDugum*& gecici);
    void geriGit(BagliListeDugum*& gecici);
    int dugumGetir(BagliListeDugum* dugum);
    void sil(BagliListeDugum *& hedef);
    friend ostream& operator<<(ostream& os,BagliListe& liste);

    BagliListeDugum* ilk;
    int baslangicIndeks;
};

#endif