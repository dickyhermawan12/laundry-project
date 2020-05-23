void cekRak(){
    int nomorOrderRak, flag = 0;;
    cout << "Masukkan nomor order\n> ";
    cin >> nomorOrderRak;

    if (rakLaundry.arrayRak[nomorOrderRak-1]!=NULL){
        DataPelanggan *helper = rakLaundry.arrayRak[nomorOrderRak-1];
        do {
            if (helper->nomorOrder == nomorOrderRak){
                cout << "Rak dengan nomor order " << nomorOrderRak << " ditemukan!" << endl;
                cout << "Nama pemilik: " << helper->nama << endl;
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
            cout << "Under construction!" << endl;
            break;
        default:
            cout << "Masukan Anda salah!" << endl;
    }
}