// file header untuk fungsi-fungsi mesin cuci

// fungsi untuk mengecek keadaan mesin cuci
void cekMesinCuci(){
    char decision;
    cout << "Kapasitas Mesin Cuci Putih saat ini:\n";
    cout << mesinCuci.kapasitasPutih << " / 10" << endl;
    cout << "Kapasitas Mesin Cuci Warna saat ini:\n";
    cout << mesinCuci.kapasitasWarna << " / 10" << endl;

    cout << "Lihat daftar pakaian? (Y/N)\n> ";
    cin >> decision;
    if (decision == 'Y' || decision == 'y'){
        printEqualSign(37);
        cout << "Mesin Cuci Putih" << endl;
        traversalPakaian(mesinCuci.mesinCuciPutih);
        printEqualSign(37);
        cout << "Mesin Cuci Warna" << endl;
        traversalPakaian(mesinCuci.mesinCuciWarna);
    }
}

// fungsi untuk mengisi pakaian ke mesin cuci
void isiMesinCuci(){
    if (queueDataPelanggan.head == NULL) {
        cout << "Antrian Pelanggan Kosong!" << endl;
    } else if ((queueDataPelanggan.head->jumlahPakaian[::warna.PUTIH] > (10-mesinCuci.kapasitasPutih)) ||
        (queueDataPelanggan.head->jumlahPakaian[::warna.BERWARNA] > (10-mesinCuci.kapasitasWarna))){
        cout << "Mesin Cuci Penuh!" << endl;
    } else {
        DataPelanggan *helpAntrian;
        Pakaian *helpPakaian;
        dequeueAntrian(helpAntrian);
        rak.isiRak(helpAntrian);
        do {
            helpPakaian = helpAntrian->listPakaian;
            if (helpAntrian->listPakaian->next == NULL){
                helpAntrian->listPakaian = NULL;
            } else {
                helpAntrian->listPakaian = helpAntrian->listPakaian->next;
            }
            helpPakaian->next = NULL;
            mesinCuci.pushMesinCuci(helpPakaian);
        } while(helpAntrian->listPakaian!=NULL);
        cout << helpAntrian->nama << " telah dikeluarkan dari antrian pelanggan..." << endl;
        cout << "Rak milik " << helpAntrian->nama << " telah dipersiapkan!" << endl;
    }
}

// fungsi untuk mengeluarkan pakaian dari mesin cuci sesuai jenisnya
void popMesinCuci(Pakaian *&jenisMesinCuci, int &kapasitas){
    Pakaian *helpPakaian;
    while (kapasitas != 0){
        helpPakaian = jenisMesinCuci;
        if (kapasitas == 1){
            jenisMesinCuci = NULL;
        } else {
            jenisMesinCuci = jenisMesinCuci->next;
        }
        helpPakaian->next = NULL;
        stackSetrika.pushStackSetrika(helpPakaian);
        kapasitas--;
    };
}

// fungsi untuk mengeluarkan pakaian dari mesin cuci
void keluarkanPakaian(){
    if (mesinCuci.kapasitasPutih == 0 && mesinCuci.kapasitasWarna == 0) {
        cout << "Mesin Cuci Kosong!" << endl;
    } else {
        popMesinCuci(mesinCuci.mesinCuciPutih, mesinCuci.kapasitasPutih);
        popMesinCuci(mesinCuci.mesinCuciWarna, mesinCuci.kapasitasWarna);
        cout << "Seluruh pakaian dalam mesin cuci berhasil dikeluarkan dan ditumpuk pada tumpukan setrika!" << endl;
    }
}

// fungsi menu mesin cuci
void menuMesinCuci(){
    enum enumMenuMesinCuci
    {
        CEKMESINCUCI=1,
        ISIMESINCUCI,
        KELUARKANPAKAIAN
    };
    int menuSelector = 0;
    system("cls");
    printEqualSign(37);
    cout << "Mesin Cuci\n";
    printEqualSign(37);
    cout << "1. Cek Mesin Cuci\n"
            "2. Isi Mesin Cuci\n"
            "3. Keluarkan Pakaian dari Mesin Cuci\n"
            "Masukkan pilihan:\n> ";
    cin >> menuSelector;
    switch (menuSelector){
        case CEKMESINCUCI:
            cekMesinCuci();
            break;
        case ISIMESINCUCI:
            isiMesinCuci();
            break;
        case KELUARKANPAKAIAN:
            keluarkanPakaian();
            break;
        default:
            cout << "Masukan Anda salah!" << endl;
    }
}