// file header untuk fungsi-fungsi rak

// fungsi untuk mengecek keadaan rak
void cekRak(){
    int nomorOrderRak, flag = 0;
    cout << "Masukkan nomor order\n> ";
    cin >> nomorOrderRak;

    if (rak.arrayRak[nomorOrderRak-1]!=NULL){
        DataPelanggan *helper = rak.arrayRak[nomorOrderRak-1];
        do {
            if (helper->nomorOrder == nomorOrderRak){
                cout << "Rak dengan nomor order " << nomorOrderRak << " ditemukan!" << endl;
                cout << "Nama pemilik: " << helper->nama << endl;
                cout << "Jumlah pakaian saat ini: " << helper->jumlahPakaian[helper->AKHIR] << endl;
                if (helper->jumlahPakaian[helper->AKHIR]!=0){
                    traversalPakaian(helper->listPakaian);
                }
                flag = 1;
                break;
            } else {
                helper=helper->next;
            }
        } while (helper!=NULL);
        if (flag==0){
            cout << "Rak dengan nomor order " << nomorOrderRak << " kosong!" << endl;
        }
    } else {
        cout << "Rak dengan nomor order " << nomorOrderRak << " kosong!" << endl;
    }
}

void ambilPesananDariRak(){
    int nomorOrderRak, flag = 0;
    cout << "Masukkan nomor order\n> ";
    cin >> nomorOrderRak;

    if (rak.arrayRak[nomorOrderRak - 1] != NULL){
        DataPelanggan *helper = rak.arrayRak[nomorOrderRak - 1];
        do {
            if (helper->nomorOrder == nomorOrderRak){
                if (helper->jumlahPakaian[helper->AKHIR] != helper->jumlahPakaian[helper->AWAL]){
                    cout << "Pakaian belum dapat diambil!" << endl;
                } else {
                    if (rak.arrayRak[nomorOrderRak - 1]->next == NULL){
                        rak.arrayRak[nomorOrderRak - 1] = NULL;
                    } else {
                        DataPelanggan *secondHelper = rak.arrayRak[nomorOrderRak - 1];
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
                    cout << "Pelanggan dengan nama " << helper->nama << " telah selesai melakukan laundry!" << endl;
                    free (helper);
                }
                break;
            } else {
                helper = helper->next;
            }
        } while (helper != NULL);
        if (flag == 0){
            cout << "Rak dengan nomor order " << nomorOrderRak << " kosong!" << endl;
        }
    } else {
        cout << "Rak dengan nomor order " << nomorOrderRak << " kosong!" << endl;
    }
}

void menuRak(){
    enum enumMenuRak
    {
        CEKRAK=1,
        AMBILPESANANDARIRAK
    };
    int menuSelector = 0;
    system("cls");
    printEqualSign(37);
    cout << "Rak Laundry\n";
    printEqualSign(37);
    cout << "1. Cek Nomor Order pada Rak\n"
            "2. Ambil Pesanan dari Rak\n"
            "Masukkan pilihan:\n> ";
    cin >> menuSelector;
    switch (menuSelector){
        case CEKRAK:
            cekRak();
            break;
        case AMBILPESANANDARIRAK:
            ambilPesananDariRak();
            break;
        default:
            cout << "Masukan Anda salah!" << endl;
    }
}