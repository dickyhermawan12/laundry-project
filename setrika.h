// file header untuk fungsi-fungsi setrika

// fungsi untuk mengecek keadaan setrika
void cekSetrikaan(){
    if (stackSetrika.jumlahPakaian == 0){
        cout << "Tidak ada pakaian dalam tumpukan setrika!" << endl << endl;
    } else {
        char decision;
        cout<<"Jumlah pakaian dalam tumpukan setrika : " << stackSetrika.jumlahPakaian << endl;
        printEqualSign(50);
        cout << "Lihat daftar pakaian? (Y/N)\n> ";
        cin >> decision;
        if (decision == 'Y' || decision == 'y')
            traversalPakaian(stackSetrika.listPakaian);
    }
}

// fungsi untuk memasukkan pakaian ke dalam rak
void masukkanKeRak(){
    if (stackSetrika.jumlahPakaian == 0){
        cout << "Tidak ada pakaian dalam tumpukan setrika!" << endl << endl;
    } else {
        Pakaian *helpPakaian;
        while (stackSetrika.jumlahPakaian != 0) {
            helpPakaian = stackSetrika.listPakaian;
            if (stackSetrika.jumlahPakaian == 1){
                stackSetrika.listPakaian = NULL;
            } else {
                stackSetrika.listPakaian = helpPakaian->next;
            }
            helpPakaian->next = NULL;
            rak.isiPakaianKeRak(helpPakaian);
            stackSetrika.jumlahPakaian--;
        }
        cout << "Seluruh pakaian dalam tumpukan setrika telah dipindahkan pada rak masing-masing pelanggan!" << endl << endl;
    }
}

// fungsi untuk menu setrika
void menuSetrika(){
    enum enumMenuSetrikaan
    {
        CEKSETRIKAAN=1,
        MASUKKANKERAK
    };
    int menuSelector = 0;
    system("cls");
    printEqualSign(50);
    cout << "                   Mode Setrika\n";
    printEqualSign(50);
    cout << "1. Cek Setrikaan\n"
            "2. Masukkan ke Rak\n"
            "Pilih menu setrika:\n> ";
    
    cin >> menuSelector;
    printEqualSign(50);
    switch (menuSelector){
        case CEKSETRIKAAN:
            cekSetrikaan();
            break;
        case MASUKKANKERAK:
            masukkanKeRak();
            break;
        default:
            cout << "Masukan Anda salah!" << endl;
    }
}