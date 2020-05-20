#include <iostream>
#include <limits>
//Masukkan header lain di antara ini


//
using namespace std;

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

int biayaPaket[2] = {6000,10000};
int globalnomorOrder = 1;

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
    // karakteristik pakaian
    int jenis;
    int warna;
    float berat;
    pakaian* next = NULL;

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

    void printWarna(){
        cout << "Pilihan warna pakaian:\n"
                "1 - Putih\n"
                "2 - Berwarna\n";
    }

    void insertDataPakaian(){
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
    int nomorOrder = globalnomorOrder;
    string namaCust;
    string alamat;
    int paket;
    float beratTotal=0;
    int jumlahPakaian;
    double total=0;
    pakaian* listPakaian = NULL;
    dataPenerimaan* next = NULL;

    void countTotal(float tempBerat, int tempPaket){
        int biaya;
        if (tempPaket==REGULER){
            biaya = biayaPaket[0];
        } else if (tempPaket==EXPRESS){
            biaya = biayaPaket[1];
        }
        total = tempBerat*float(biaya);
    }

    void insertListPakaian(float &tempBerat){
        pakaian* newPakaian = new pakaian;
        newPakaian->insertDataPakaian();
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
    }

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
                jumlahPakaian = count;
                break;
            }
        }
        beratTotal/=1000;
        countTotal(beratTotal, paket);
        globalnomorOrder++;
    }

    void printDataPelanggan(){
        cout << "Nomor Order       : " << nomorOrder << endl;
        cout << "Nama Pelanggan    : " << namaCust << endl;
        cout << "Alamat            : " << alamat << endl;
        if (paket == 1){
            cout << "Paket             : Reguler" << endl;
        } else if (paket == 2) {
            cout << "Paket             : Ekspress" << endl;
        }
        cout << "Berat Total (kg)  : " << beratTotal << endl;
        cout << "Jumlah Pakaian    : " << jumlahPakaian << endl;
        cout << "Total Biaya       : " << total << endl;
    }
};

void insertListPelanggan(dataPenerimaan *&antrianPelanggan){
    dataPenerimaan* newPelanggan = new dataPenerimaan;
    cin.ignore();
    newPelanggan->insertDataPelanggan();
    if (antrianPelanggan == NULL){
        antrianPelanggan = newPelanggan;
    } else {
        dataPenerimaan* helper = antrianPelanggan;
        while(helper->next!=NULL){
            helper=helper->next;
        }
        helper->next = newPelanggan;
    }
}

void lihatAntrianPelanggan(dataPenerimaan* antrianPelanggan){
    dataPenerimaan* helper = antrianPelanggan;
    int count = 1;
    if (helper == NULL){
        cout << "Antrian Kosong!" << endl;
    } else {
        do {
            printEqualSign(37);
            cout << "                " << count << endl;
            printEqualSign(37);
            helper->printDataPelanggan();
            printEqualSign(37);
            helper=helper->next;
            count++;
        } while(helper!=NULL);
    }
}

void menuAntrianPesanan(dataPenerimaan *&antrianPelanggan){
    enum enumMenuAntrianPesanan
    {
        TAMBAHPELANGGAN=1,
        LIHATANTRIAN
    };
    int menuSelector = 0;
    system("cls");
    printEqualSign(37);
    cout << "Antrian Pesanan\n";
    printEqualSign(37);
    cout << "1. Tambah Pelanggan\n"
            "2. Lihat Antrian\n"
            "Masukkan pilihan:\n> ";
    cin >> menuSelector;
    switch (menuSelector){
        case TAMBAHPELANGGAN:
            insertListPelanggan(antrianPelanggan);
            break;
        case LIHATANTRIAN:
            lihatAntrianPelanggan(antrianPelanggan);
            break;
        default:
            cout << "Masukan Anda salah!" << endl;
    }
}

class menu {
    private:
        int menuSelector;
        dataPenerimaan* antrianPelanggan;
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
    public:
        menu(){
            menuSelector = 0;
            antrianPelanggan = NULL;
        }

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
                        menuAntrianPesanan(antrianPelanggan);
                        break;
                    case ATURMESINCUCI:
                        cout << "Mengatur Mesin Cuci" << endl;
                        break;
                    case ATURSETRIKA:
                        cout << "Mengatur Setrika" << endl;
                        break;
                    case SIMPANRAK:
                        cout << "Menyimpan ke Rak" << endl;
                        break;
                    case AMBILPESANAN:
                        cout << "Mengambil Pesanan" << endl;
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


