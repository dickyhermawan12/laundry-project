// file header untuk fungsi menu

// dealokasi memori seluruh pointer
void purge(){
    if (queueDataPelanggan.head != NULL){
        DataPelanggan *helper;
        while (queueDataPelanggan.head != NULL){
            helper = queueDataPelanggan.head;
            queueDataPelanggan.head = queueDataPelanggan.head->next;
            free(helper);
        }
        delete helper;
    }

    if (mesinCuci.mesinCuciPutih != NULL){
        Pakaian *helper;
        while (mesinCuci.mesinCuciPutih != NULL){
            helper = mesinCuci.mesinCuciPutih;
            mesinCuci.mesinCuciPutih = mesinCuci.mesinCuciPutih->next;
            free(helper);
        }
        delete helper;
    }

    if (mesinCuci.mesinCuciWarna != NULL){
        Pakaian *helper;
        while (mesinCuci.mesinCuciWarna != NULL){
            helper = mesinCuci.mesinCuciWarna;
            mesinCuci.mesinCuciWarna = mesinCuci.mesinCuciWarna->next;
            free(helper);
        }
        delete helper;
    }

    if (stackSetrika.listPakaian != NULL){
        Pakaian *helper;
        while (stackSetrika.listPakaian != NULL){
            helper = stackSetrika.listPakaian;
            stackSetrika.listPakaian = stackSetrika.listPakaian->next;
            free(helper);
        }
        delete helper;
    }

    for (int i=0; i<50; i++){
        if (rak.arrayRak[i] != NULL){
            DataPelanggan *helper = rak.arrayRak[i];
            while (rak.arrayRak[i] != NULL){
                helper = rak.arrayRak[i];
                rak.arrayRak[i] = helper->next;
                free(helper);
            }
            delete helper;
        }
        delete rak.arrayRak[i];
    }
}

// struct menu
struct Menu {
    int menuSelector;
    // enum untuk pilihan menu
    enum menuEnum
    {
        TAMBAHPESANAN=1,
        ATURMESINCUCI,
        ATURSETRIKA,
        AMBILPESANAN,
        KONFIGURASI,
        CARAPAKAI,
        KELUAR
    };
    // constructor
    Menu(){
        menuSelector = 0;
    }
    // method display menu
    void display(){
        while (true){
            system("cls");
            printEqualSign(50);
            cout << "                LAUNDRY SOBAT CUAN" << endl;
            printEqualSign(50);
            cout << "Menu\n"
                    "1. Antrian Pesanan\n"
                    "2. Atur Mesin Cuci\n"
                    "3. Atur Setrika\n"
                    "4. Ambil Pesanan\n"
                    "5. Konfigurasi\n"
                    "6. Cara Menggunakan Program\n"
                    "7. Keluar\n";
            printEqualSign(50);
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
                    menuSetrika();
                    break;
                case AMBILPESANAN:
                    menuRak();
                    break;
                case KONFIGURASI:
                    configuration();
                    break;
                case CARAPAKAI:
                    carapakai();
                    break;
                case KELUAR:
                    purge();
                    cout << "Sampai Jumpa Lagi!" << endl;
                    exit(1);
                default:
                    if (cin.fail()){
                        fail();
                    }
                    cout << "Masukan Anda salah!" << endl << endl;
            }
            system("pause");
        }
    }
} menu;