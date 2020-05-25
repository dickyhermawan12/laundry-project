#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

// variabel untuk menyimpan nomor order keseluruhan
int globalNomorOrder = 1;

// file header yang menyimpan objek-objek struct
#include "structs.h"

// prototype fungsi print tanda sama dengan
void printEqualSign(int num);

// prototype fungsi traversal pakaian
void traversalPakaian(Pakaian *&listPakaian);

#include "rak.h"

#include "penerimaan.h"

#include "setrika.h"

#include "mesincuci.h"

#include "config.h"

#include "menu.h"

int main(){
    menu.display();
}

// fungsi untuk melakukan print tanda sama dengan
void printEqualSign(int num){
    for(int i=0; i<num; i++){
        cout << "=";
    }
    cout << endl;
}

// fungsi untuk melakukan traversal pakaian
void traversalPakaian(Pakaian *&listPakaian){
    Pakaian *helpPakaian = listPakaian;
    int no = 1;
    while (helpPakaian != NULL){
        printEqualSign(37);
        cout << "Pakaian ke-" << no << endl;
        cout << "Nomor Order  : " << helpPakaian->nomorOrder << endl;
        cout << "Jenis Pakaian: " << jenis.pakaian[helpPakaian->jenis] << endl;
        cout << "Warna Pakaian: " << warna.pakaian[helpPakaian->warna] << endl;
        printEqualSign(37);
        helpPakaian=helpPakaian->next;
        no++;
    }
}