void cekMesinCuci(){
    cout << "Kapasitas Mesin Cuci Putih saat ini:\n";
    cout << mesinCuciLaundry.kapasitasPutih << " / 10" << endl;
    cout << "Kapasitas Mesin Cuci Warna saat ini:\n";
    cout << mesinCuciLaundry.kapasitasWarna << " / 10" << endl;
}

void isiMesinCuci(){
    if (queueDataPelanggan.head == NULL) {
        cout << "Antrian Pelanggan Kosong!" << endl;
    } else if ((queueDataPelanggan.head->jumlahPakaian[::warna.PUTIH] > (10-mesinCuciLaundry.kapasitasPutih)) ||
        (queueDataPelanggan.head->jumlahPakaian[::warna.BERWARNA] > (10-mesinCuciLaundry.kapasitasWarna))){
        cout << "Mesin Cuci Penuh!" << endl;
    } else {
        DataPelanggan *helpAntrian;
        Pakaian *helpPakaian;
        dequeueAntrian(helpAntrian);
        rakLaundry.isiRak(helpAntrian);
        do {
            helpPakaian = helpAntrian->listPakaian;
            if (helpAntrian->listPakaian->next == NULL){
                helpAntrian->listPakaian = NULL;
            } else {
                helpAntrian->listPakaian = helpAntrian->listPakaian->next;
            }
            helpPakaian->next = NULL;
            mesinCuciLaundry.pushMesinCuci(helpPakaian);
            helpPakaian = NULL;
        } while(helpAntrian->listPakaian!=NULL);
        cout << helpAntrian->nama << " telah dikeluarkan dari antrian pelanggan..." << endl;
        cout << "Rak milik " << helpAntrian->nama << " telah dipersiapkan!" << endl;
    }
}

void menuMesinCuci(){
    enum enumMenuMesinCuci
    {
        CEKMESINCUCI=1,
        ISIMESINCUCI
    };
    int menuSelector = 0;
    system("cls");
    printEqualSign(37);
    cout << "Mesin Cuci\n";
    printEqualSign(37);
    cout << "1. Cek Mesin Cuci\n"
            "2. Isi Mesin Cuci\n"
            "Masukkan pilihan:\n> ";
    cin >> menuSelector;
    switch (menuSelector){
        case CEKMESINCUCI:
            cekMesinCuci();
            break;
        case ISIMESINCUCI:
            isiMesinCuci();
            break;
        default:
            cout << "Masukan Anda salah!" << endl;
    }
}