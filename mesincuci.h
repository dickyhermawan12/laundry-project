// file header untuk fungsi-fungsi mesin cuci

// fungsi untuk mengecek keadaan mesin cuci
void cekMesinCuci(){
    char decision;
    cout << "Kapasitas Mesin Cuci Putih saat ini:\n";
    cout << mesinCuci.kapasitasPutih << " / " << maxCapacity << endl;
    cout << "Kapasitas Mesin Cuci Warna saat ini:\n";
    cout << mesinCuci.kapasitasWarna << " / " << maxCapacity << endl;
    printEqualSign(50);

    if (mesinCuci.kapasitasPutih != 0 || mesinCuci.kapasitasWarna != 0){
        cout << "Lihat daftar pakaian? (Y/N)\n> ";
        cin >> decision;
        if (decision == 'Y' || decision == 'y'){
            if (mesinCuci.kapasitasPutih != 0){
                printEqualSign(50);
                cout << "Mesin Cuci Putih" << endl;
                printEqualSign(50);
                traversalPakaian(mesinCuci.mesinCuciPutih);
            }

            if (mesinCuci.kapasitasWarna != 0){
                printEqualSign(50);
                cout << "Mesin Cuci Warna" << endl;
                printEqualSign(50);
                traversalPakaian(mesinCuci.mesinCuciWarna);
            }
        }
    }
}

// fungsi untuk mengisi pakaian ke mesin cuci
void isiMesinCuci(){
    if (queueDataPelanggan.head == NULL) {
        cout << "Antrian pelanggan kosong!\n\n";
    } else if ((queueDataPelanggan.head->jumlahPakaian[::warna.PUTIH] > (maxCapacity-mesinCuci.kapasitasPutih)) ||
        (queueDataPelanggan.head->jumlahPakaian[::warna.BERWARNA] > (maxCapacity-mesinCuci.kapasitasWarna))){
        cout << "Mesin cuci penuh!\n\n";
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
        cout << helpAntrian->nama << " telah dikeluarkan dari antrian pelanggan...\n";
        cout << "Rak milik " << helpAntrian->nama << " telah dipersiapkan!\n\n";
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
        cout << "Mesin Cuci Kosong!\n\n";
    } else {
        popMesinCuci(mesinCuci.mesinCuciPutih, mesinCuci.kapasitasPutih);
        popMesinCuci(mesinCuci.mesinCuciWarna, mesinCuci.kapasitasWarna);
        cout << "Seluruh pakaian dalam mesin cuci berhasil\n"
                "dikeluarkan dan ditumpuk pada tumpukan setrika!\n\n";
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
    printEqualSign(50);
    cout << "                    Mesin Cuci\n";
    printEqualSign(50);
    cout << "1. Cek Mesin Cuci\n"
            "2. Isi Mesin Cuci\n"
            "3. Keluarkan Pakaian dari Mesin Cuci\n"
            "Masukkan pilihan:\n> ";
    cin >> menuSelector;
    printEqualSign(50);
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
            if (cin.fail()){
                fail();
            }
            cout << "Masukan Anda salah!\n\n";
    }
}