// file header untuk fungsi-fungsi rak

// fungsi untuk mengecek keadaan rak
void cekRak(){
    int nomorOrderRak, flag = 0;
    char decision;
    while (true){
        cout << "Masukkan nomor order\n> ";
        cin >> nomorOrderRak;
        if (!cin.fail()){
            break;
        }
        fail();
        cout << "Input Anda salah!" << endl;
    }
    printEqualSign(50);
    DataPelanggan *helper = rak.arrayRak[(nomorOrderRak - 1)%50];
    while (helper != NULL){
        if (helper->nomorOrder == nomorOrderRak){
            cout << "Rak dengan nomor order " << nomorOrderRak << " ditemukan!" << endl;
            printEqualSign(50);
            helper->printDataPelanggan(helper->AKHIR);
            printEqualSign(50);
            cout << "Jumlah pakaian saat ini: " << helper->jumlahPakaian[helper->AKHIR] << " / " << helper->jumlahPakaian[helper->AWAL] << endl;
            if (helper->jumlahPakaian[helper->AKHIR] != 0){
                printEqualSign(50);
                cout << "Lihat daftar pakaian? (Y/N)\n> ";
                cin >> decision;
                if (decision == 'Y' || decision == 'y')
                    traversalPakaian(helper->listPakaian);
            }
            if (helper->totalBiaya[0] != helper->totalBiaya[1]){
                cout << "Selesaikan pembayaran? (Y/N)\n> ";
                cin >> decision;
                if (decision == 'Y' || decision == 'y'){
                    helper->totalBiaya[0] = helper->totalBiaya[1];
                    cout << "Pembayaran berhasil dilunasi!\n\n";
                }
            }
            flag = 1;
            break;
        } else {
            helper = helper->next;
        }
    }

    if (flag == 0){
        cout << "Rak dengan nomor order " << nomorOrderRak << " tidak ditemukan!\n\n";
    }
}

// fungsi untuk mengambil/ mengosongkan pesanan dari rak
void ambilPesananDariRak(){
    int nomorOrderRak, flag = 0;
    while (true){
        cout << "Masukkan nomor order\n> ";
        cin >> nomorOrderRak;
        if (!cin.fail()){
            break;
        }
        fail();
        cout << "Input Anda salah!" << endl;
    }
    printEqualSign(50);
    DataPelanggan *helper = rak.arrayRak[(nomorOrderRak - 1)%50];
    while (helper != NULL){
        if (helper->nomorOrder == nomorOrderRak){
            if (helper->jumlahPakaian[helper->AKHIR] != helper->jumlahPakaian[helper->AWAL] ||
            helper->totalBiaya[0] != helper->totalBiaya[1]){
                cout << "Pakaian belum dapat diambil!\n\n";
            } else {
                if (rak.arrayRak[nomorOrderRak - 1] == helper){
                    rak.arrayRak[nomorOrderRak - 1] = NULL;
                } else {
                    DataPelanggan *secondHelper = rak.arrayRak[(nomorOrderRak - 1)%50];
                    do {
                        if (secondHelper->next == helper){
                            if (helper->next != NULL){
                                secondHelper = helper->next;
                            } else {
                                secondHelper->next = NULL;
                            }
                            break;
                        } else {
                            secondHelper = secondHelper->next;
                        }
                    } while (secondHelper != NULL);
                }
                cout << "Pelanggan dengan nama " << helper->nama << " telah selesai melakukan laundry!\n\n";
                free(helper);
            }
            flag = 1;
            break;
        } else {
            helper = helper->next;
        }
    }

    if (flag == 0) {
        cout << "Rak dengan nomor order " << nomorOrderRak << " tidak ditemukan!\n\n";
    }
}

// fungsi untuk menu rak
void menuRak(){
    enum enumMenuRak
    {
        CEKRAK=1,
        AMBILPESANANDARIRAK
    };
    int menuSelector = 0;
    system("cls");
    printEqualSign(50);
    cout << "                   Rak Laundry\n";
    printEqualSign(50);
    cout << "1. Cek Nomor Order pada Rak\n"
            "2. Ambil Pesanan dari Rak\n"
            "Masukkan pilihan:\n> ";
    cin >> menuSelector;
    printEqualSign(50);
    switch (menuSelector){
        case CEKRAK:
            cekRak();
            break;
        case AMBILPESANANDARIRAK:
            ambilPesananDariRak();
            break;
        default:
            if (cin.fail()){
                fail();
            }
            cout << "Masukan Anda salah!\n\n";
    }
}