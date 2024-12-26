// @file         BagliListe.cpp
// @description  ağaçları tutan bağlı liste sınıfı
// @course       2. Öğretim B grubu
// @assignment   2.Ödev
// @date         25.12.2024
// @author       Yusuf Taha Ezgin - yusuf.ezgin@ogr.sakarya.edu.tr

#include "BagliListe.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

BagliListe::BagliListe()
{
    ilk=0;
    baslangicIndeks=0;
}

BagliListe::~BagliListe()
{
    BagliListeDugum *gec=ilk;
    while(gec!=0){ 
        BagliListeDugum* sil=gec;
        gec=gec->sonraki;
        delete sil->ilkEleman;
        delete sil;
    }
}

void BagliListe::ekle(BST* agac)
{
    BagliListeDugum* yeni=new BagliListeDugum(agac);
    if(ilk==0){ // bagli listede hic eleman yoksa
        ilk=yeni;  
    }
    else{
        BagliListeDugum* gec=ilk;
    
        while(gec->sonraki!=0){
            gec=gec->sonraki;
        }

        gec->sonraki=yeni;
    }
}

void BagliListe::sil(BagliListeDugum *&hedef)
{
    if (!ilk || !hedef)
        return;

    if (ilk == hedef)
    {
        BagliListeDugum *silinecek = ilk;
        ilk = ilk->sonraki;
        delete silinecek->ilkEleman; 
        delete silinecek;           
        hedef = ilk;
    }
    else if(hedef->sonraki==0){

        BagliListeDugum* onceki = nullptr;
        BagliListeDugum* silinecek = ilk;

        while (silinecek != nullptr && silinecek != hedef) {
            onceki = silinecek;
            silinecek = silinecek->sonraki;
        }

        if (onceki != nullptr) {
            hedef = onceki;
        }
        hedef->sonraki=0;
        delete silinecek->ilkEleman; 
        delete silinecek;
    }
    else
    {
        BagliListeDugum *gecici = ilk;
        while (gecici->sonraki && gecici->sonraki != hedef)
        {
            gecici = gecici->sonraki;
        }
        if (gecici->sonraki)
        {
            BagliListeDugum *silinecek = gecici->sonraki;
            gecici->sonraki = silinecek->sonraki;
            delete silinecek->ilkEleman;
            delete silinecek;           
            hedef = gecici->sonraki;
        }
    }
}


void BagliListe::ileriGit(BagliListeDugum*& gecici) {
    if (gecici != nullptr && gecici->sonraki != nullptr) {
        gecici = gecici->sonraki; 
    }
    int dugumIndex = dugumGetir(gecici);

    int limit = 10;

    if (dugumIndex >= baslangicIndeks+limit) {
        baslangicIndeks += limit; 
    }

}

void BagliListe::geriGit(BagliListeDugum*& gecici) {
    if (gecici == nullptr || gecici == ilk) {
        return;
    }

    BagliListeDugum* prev = nullptr;
    BagliListeDugum* temp = ilk;

    while (temp != nullptr && temp != gecici) {
        prev = temp;
        temp = temp->sonraki;
    }

    if (prev != nullptr) {
        gecici = prev;
    }


    int dugumIndex = dugumGetir(gecici);

    int limit = 10;

    if (dugumIndex < baslangicIndeks) {

        baslangicIndeks -= limit; 

    }
}

ostream &operator<<(ostream &os, BagliListe &liste) 
{
    int limit = 10;
    BagliListeDugum *mevcut = liste.ilk;
    while (true)
    {
        
        system("cls");

        BagliListeDugum *gecici = liste.ilk;
        int index = 0;

        
        int dugumIndex = 0;

        BagliListeDugum* temp = liste.ilk;

        while (temp != nullptr) {
            if (temp == mevcut) break;
            temp = temp->sonraki;
            dugumIndex++;
        }
        // Yazdırma aralığını belirle

        int baslangic = (dugumIndex / limit) * limit;//10

        int bitis = baslangic + limit;//20

        // İlk düğümü yazdırma konumuna ilerle

        for (int i = 0; i < baslangic && gecici != nullptr; i++) {
            gecici = gecici->sonraki;
            //index++;
        }

        index=baslangic;
        while(gecici!=0 && index<bitis)
        {   for(int i=0;i<11;i++){
            os<<".";
            }
            os<<setw(4);
            gecici=gecici->sonraki;
            index++;
        }
        os<<endl;
        gecici=liste.ilk;
        index=baslangic;
        for (int i = 0; i < baslangic; i++) {
            gecici = gecici->sonraki;
        }
        while(gecici!=0 && index<bitis)
        {   
            os<<setw(1)<<"."<<setw(9)<<gecici<<"."<<setw(3)<<"   ";
            gecici=gecici->sonraki;
            index++;
        }
        os<<endl;
        gecici=liste.ilk;
        index=baslangic;
        for (int i = 0; i < baslangic; i++) {
            gecici = gecici->sonraki;
        }
        while(gecici!=0 && index<bitis)
        {   for(int i=0;i<11;i++){
            os<<".";
            }
            os<<setw(4);
            gecici=gecici->sonraki;
            index++;
        }
        os<<endl;
        gecici=liste.ilk;
        index=baslangic;
        for (int i = 0; i < baslangic; i++) {
            gecici = gecici->sonraki;
        }
        while(gecici!=0 && index<bitis)
        {   os<<setw(1)<<"."<<setw(8)<<gecici->ilkEleman->degerHesapla()<<setw(1)<<" ."<<setw(3)<<"   ";
            gecici=gecici->sonraki;
            index++;
        }
        os<<endl;
        gecici=liste.ilk;
        index=baslangic;
        for (int i = 0; i < baslangic; i++) {
            gecici = gecici->sonraki;
        }
        while(gecici!=0 && index<bitis)
        {   for(int i=0;i<11;i++){
            os<<".";
            }
            os<<setw(4);
            gecici=gecici->sonraki;
            index++;
        }
        os<<endl;
        gecici=liste.ilk;
        index=baslangic;
        for (int i = 0; i < baslangic; i++) {
            gecici = gecici->sonraki;
        }
        while(gecici!=0 && index<bitis)
        {  os<<setw(1)<<"."<<setw(9)<<gecici->sonraki<<"."<<setw(3)<<"   ";
            gecici=gecici->sonraki;
            index++;
        }
        os<<endl;
        gecici=liste.ilk;
        index=baslangic;
        for (int i = 0; i < baslangic; i++) {
            gecici = gecici->sonraki;
        }
        while(gecici!=0 && index<bitis)
        {   for(int i=0;i<11;i++){
            os<<".";
            }
            os<<setw(4);
            gecici=gecici->sonraki;
            index++;
        }
        os<<endl;
        gecici=liste.ilk;
        index=baslangic;
        for (int i = 0; i < baslangic; i++) {
            gecici = gecici->sonraki;
        }
        while(gecici!=0 && index<bitis)
        {   if(index==dugumIndex){
                os<<setw(11)<<"^^^^^^^^^^^   ";
            }
            else{
                os<<setw(11)<<"              ";
            }
            gecici=gecici->sonraki;
            index++;
        }
        os<<endl;
        gecici=liste.ilk;
        index=baslangic;
        for (int i = 0; i < baslangic; i++) {
            gecici = gecici->sonraki;
        }
        while(gecici!=0 && index<bitis)
        {   if(index==dugumIndex){
                os<<setw(11)<<"|||||||||||   ";
            }
            else{
                os<<setw(11)<<"              ";
            }
            gecici=gecici->sonraki;
            index++;
        }
        os<<endl<<endl<<endl;

        if(mevcut!=0) mevcut->ilkEleman->levelorder();
        //os << "\n\nMevcut dugum: " << mevcut << endl;
        os << "\nKontroller:" << endl;
        os << "  'a': Onceki dugume git" << endl;
        os << "  'd': Sonraki dugume git" << endl;
        os << "  's': Secili dugumu sil" << endl;
        os << "  'w': Secili dugumu aynala" << endl;
        os << "  'q': Cikis" << endl;

        char secim;
        cout<<"secim:..";
        cin>>secim;

        if (secim == 'q')
        {
            break;
        }
        else if (secim == 'a')
        {
            liste.geriGit(mevcut);
        }
        else if (secim == 'd')
        {
            liste.ileriGit(mevcut);
        }
        else if (secim == 's')
        {
            liste.sil(mevcut);
        }
        else if (secim == 'w')
        {
            if(mevcut!=0)mevcut->ilkEleman->aynalama();
        }
    }

    

    return os;
}

int BagliListe::dugumGetir(BagliListeDugum* dugum) {

    int index = 0;

    BagliListeDugum* gec =ilk;

    while (gec != nullptr) {

        if (gec == dugum) {
            return index;
        }

        gec = gec->sonraki;

        index++;

    }

    return 0; // Düğüm bulunamadıysa

}
