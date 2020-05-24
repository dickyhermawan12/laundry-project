void cekMesinCuci(){
    cout << "Kapasitas Mesin Cuci Putih saat ini:\n";
    cout << mesinCuci.kapasitasPutih << " / 10" << endl;
    cout << "Kapasitas Mesin Cuci Warna saat ini:\n";
    cout << mesinCuci.kapasitasWarna << " / 10" << endl;
}

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
            helpPakaian = NULL;
        } while(helpAntrian->listPakaian!=NULL);
        cout << helpAntrian->nama << " telah dikeluarkan dari antrian pelanggan..." << endl;
        cout << "Rak milik " << helpAntrian->nama << " telah dipersiapkan!" << endl;
    }
}

void keluarkanPakaian(){
    if (mesinCuci.kapasitasPutih == 0 && mesinCuci.kapasitasWarna == 0) {
        cout << "Mesin Cuci Kosong!" << endl;
    }
    else {
        Pakaian *helper;
        Pakaian *pop;
        while (mesinCuci.mesinCuciPutih!=NULL) {
            stackSetrika.jumlahPakaian++;
            mesinCuci.kapasitasPutih--;
            if(mesinCuci.mesinCuciPutih->next == NULL){
                pop = mesinCuci.mesinCuciPutih;
                if(stackSetrika.listPakaian == NULL){
                stackSetrika.listPakaian = pop;
                }
                else {
                pop->next = stackSetrika.listPakaian;
                stackSetrika.listPakaian = pop;
                }
                mesinCuci.mesinCuciPutih = NULL;
            }
            else {
                pop = mesinCuci.mesinCuciPutih;
                mesinCuci.mesinCuciPutih = mesinCuci.mesinCuciPutih->next;
                pop->next = NULL;
                if(stackSetrika.listPakaian == NULL){
                stackSetrika.listPakaian = pop;
                }
                else {
                pop->next = stackSetrika.listPakaian;
                stackSetrika.listPakaian = pop;
                }
            }
        }
        while (mesinCuci.mesinCuciWarna!=NULL){
            stackSetrika.jumlahPakaian++;
            mesinCuci.kapasitasWarna--;
            if(mesinCuci.mesinCuciWarna->next == NULL){
                pop = mesinCuci.mesinCuciWarna;
                if(stackSetrika.listPakaian == NULL){
                stackSetrika.listPakaian = pop;
                }
                else {
                pop->next = stackSetrika.listPakaian;
                stackSetrika.listPakaian = pop;
                }
                mesinCuci.mesinCuciWarna = NULL;
            }
            else {
                pop = mesinCuci.mesinCuciWarna;
                mesinCuci.mesinCuciWarna = mesinCuci.mesinCuciWarna->next;
                pop->next = NULL;
                if(stackSetrika.listPakaian == NULL){
                stackSetrika.listPakaian = pop;
                }
                else {
                pop->next = stackSetrika.listPakaian;
                stackSetrika.listPakaian = pop;
                }
            }
        }
    }
}

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