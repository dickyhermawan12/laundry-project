#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

int biayaPaket[2] = {6000,10000};
int globalnomorOrder = 1;

void fail(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printEqualSign(int num){
    for(int i=0; i<num; i++){
        cout << "=";
    }
    cout << endl;
}

enum enumPaket
{
    REGULER=1,
    EXPRESS
};

struct pakaian {
    // enum untuk jenis pakaian
    enum enumJenis
    {
        KAOS=1,
        KEMEJA=2,
        CELANAPENDEK=3,
        CELANAPANJANG=4,
        JAS=5,
        DRESS=6,
        JAKET=7,
        HANDUK=8
    };
    // enum untuk warna pakaian
    enum enumWarna
    {
        PUTIH=1,
        BERWARNA=2
    };
    // member struct pakaian
    int nomorOrder;
    int jenis;
    int warna;
    float berat;
    pakaian* next;
    // constructor
    pakaian(){
        next = NULL;
    }
    // method print keterangan jenis pakaian
    void printJenis(){
        cout << "Jenis pakaian yang diterima:\n"
                "1 - Kaos\n"
                "2 - Kemeja\n"
                "3 - Celana Pendek\n"
                "4 - Celana Panjang\n"
                "5 - Jas\n"
                "6 - Dress\n"
                "7 - Jaket\n"
                "8 - Handuk\n";
    }
    // method print keterangan warna pakaian
    void printWarna(){
        cout << "Pilihan warna pakaian:\n"
                "1 - Putih\n"
                "2 - Berwarna\n";
    }
    // method untuk insersi data pakaian
    void insertDataPakaian(int getNomorOrder){
        nomorOrder = getNomorOrder;
        printJenis();
        cout << "Masukkan jenis pakaian (1-8) :\n> ";
        cin >> jenis;
        printWarna();
        cout << "Masukkan warna pakaian (1/2) :\n> ";
        cin >> warna;
        cout << "Masukkan berat pakaian (gram) :\n> ";
        cin >> berat;
    }

};

struct dataPenerimaan {
    // member struct dataPenerimaan
    int nomorOrder;
    string namaCust;
    string alamat;
    int paket;
    float beratTotal;
    int jumlahPakaian[3];
    double total;
    pakaian* listPakaian;
    dataPenerimaan* next;
    // constructor
    dataPenerimaan(){
        nomorOrder = globalnomorOrder;
        beratTotal = 0;
        for(int i=0; i<3; i++){
            jumlahPakaian[i] = 0;
        }
        total = 0;
        listPakaian = NULL;
        next = NULL;
    }
    // method untuk menghitung total biaya
    void countTotal(float tempBerat, int tempPaket){
        int biaya;
        if (tempPaket==REGULER){
            biaya = biayaPaket[0];
        } else if (tempPaket==EXPRESS){
            biaya = biayaPaket[1];
        }
        total = ceil(tempBerat)*float(biaya);
    }
    // method untuk insersi pakaian
    void insertListPakaian(float &tempBerat){
        pakaian* newPakaian = new pakaian;
        newPakaian->insertDataPakaian(nomorOrder);
        if (listPakaian == NULL){
            listPakaian = newPakaian;
        } else {
            pakaian* helper = listPakaian;
            while(helper->next!=NULL){
                helper=helper->next;
            }
            helper->next = newPakaian;
        }
        tempBerat = newPakaian->berat;
        if (newPakaian->warna==pakaian::enumWarna::PUTIH){
            jumlahPakaian[pakaian::enumWarna::PUTIH]++;
        } else {
            jumlahPakaian[pakaian::enumWarna::BERWARNA]++;
        }
    }
    // method untuk insersi data pelanggan
    void insertDataPelanggan(){
        float tempBerat;
        int count = 1;
        char decision;
        cout << "Masukkan nama pelanggan:\n> ";
        getline(cin, namaCust);
        cout << "Masukkan alamat:\n> ";
        getline(cin, alamat);
        cout << "Pilihan paket:\n"
                "1 - Reguler\n"
                "2 - Ekspress\n"
                "Masukkan paket yang dipilih (1/2):\n> ";
        cin >> paket;
        while(true){
            cout << "Masukkan pakaian ke-" << count << "\n> ";
            insertListPakaian(tempBerat);
            beratTotal+=tempBerat;
            cout << "Apakah Anda ingin menambah pakaian? (Y/N)\n> ";
            cin >> decision;
            if (decision=='Y' || decision=='y'){
                count++;
                continue;
            } else {
                jumlahPakaian[0] = count;
                break;
            }
        }
        beratTotal/=1000;
        countTotal(beratTotal, paket);
        globalnomorOrder++;
    }
    // method untuk mencetak data pelanggan
    void printDataPelanggan(){
        cout << "Nomor Order       : " << nomorOrder << endl;
        cout << "Nama Pelanggan    : " << namaCust << endl;
        cout << "Alamat            : " << alamat << endl;
        if (paket == 1){
            cout << "Paket             : Reguler" << endl;
        } else if (paket == 2){
            cout << "Paket             : Ekspress" << endl;
        }
        cout << "Berat Total (kg)  : " << beratTotal << endl;
        cout << "Jumlah Pakaian    : " << jumlahPakaian[0] << endl;
        cout << "Total Biaya       : " << total << endl;
    }
    // method untuk mengeluarkan pakaian dari list
};

struct antrianPelanggan {
    dataPenerimaan* head;
    dataPenerimaan* tail;

    antrianPelanggan(){
        head = NULL;
        tail = NULL;
    }
} queueDataPenerimaan;

struct rak {
    dataPenerimaan *arrayRak[50];

    rak(){
        for(int i=0; i<50; i++){
            arrayRak[i] = NULL;
        }
    }

    void isiRak(dataPenerimaan *&poppedPelanggan){
        int nomorOrder = poppedPelanggan->nomorOrder;
        nomorOrder--;
        nomorOrder%=50;
        if (arrayRak[nomorOrder]==NULL){
            arrayRak[nomorOrder] = poppedPelanggan;
        } else {
            arrayRak[nomorOrder]->next = poppedPelanggan;
        }
    }
} rakLaundry;

#include "rak.h"

#include "penerimaan.h"

struct mesinCuci {
    int kapasitasPutih;
    int kapasitasWarna;
    pakaian* mesinCuciPutih;
    pakaian* mesinCuciWarna;

    mesinCuci(){
        kapasitasPutih = 0;
        kapasitasWarna = 0;
        mesinCuciPutih = NULL;
        mesinCuciWarna = NULL;
    }

    void pushMesinCuci(pakaian* pakaianMasuk){
        if (pakaianMasuk->warna == pakaian::enumWarna::PUTIH){
            if (kapasitasPutih==0){
                mesinCuciPutih = pakaianMasuk;
            } else {
                pakaianMasuk->next = mesinCuciPutih;
                mesinCuciPutih = pakaianMasuk;
            }
            kapasitasPutih++;
        } else {
            if (kapasitasWarna==0){
                mesinCuciWarna = pakaianMasuk;
            } else {
                pakaianMasuk->next = mesinCuciWarna;
                mesinCuciWarna = pakaianMasuk;
            }
            kapasitasWarna++;
        }
    }
} mesinCuciLaundry;

#include "mesincuci.h"

struct menu {
    int menuSelector;
    enum menuEnum
    {
        TAMBAHPESANAN=1,
        ATURMESINCUCI,
        ATURSETRIKA,
        SIMPANRAK,
        AMBILPESANAN,
        KONFIGURASI,
        KELUAR
    };
    // constructor
    menu(){
        menuSelector = 0;
    }
    // method display menu
    void display(){
        while (true){
            system("cls");
            printEqualSign(37);
            cout << "          LAUNDRY CUAN-CUAN" << endl;
            printEqualSign(37);
            cout << "Menu\n"
                    "1. Antrian Pesanan\n"
                    "2. Atur Mesin Cuci\n"
                    "3. Atur Setrikaan\n"
                    "4. Simpan ke Rak\n"
                    "5. Ambil Pesanan\n"
                    "6. Konfigurasi\n"
                    "7. Keluar\n";
            printEqualSign(37);
            cout << "Pilih Menu > ";
            cin >> menuSelector;
            switch(menuSelector){
                case TAMBAHPESANAN:
                    menuAntrianPesanan();
                    break;
                case ATURMESINCUCI:
                    menuMesinCuci();
                    break;
                case ATURSETRIKA:
                    cout << "Mengatur Setrika" << endl;
                    break;
                case SIMPANRAK:
                    cout << "Menyimpan ke Rak" << endl;
                    break;
                case AMBILPESANAN:
                    menuRak();
                    break;
                case KONFIGURASI:
                    cout << "Memulai Konfigurasi" << endl;
                    break;
                case KELUAR:
                    cout << "Sampai Jumpa Lagi!" << endl;
                    exit(1);
                default:
                    cout << "Masukan Anda salah!" << endl;
            }
            system("pause");
        }
    }
} mainMenu;

int main(){
    mainMenu.display();
}