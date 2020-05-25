// file header untuk fungsi-fungsi setrika

// fungsi untuk mengecek keadaan setrika
void cekSetrikaan(){
    if (stackSetrika.listPakaian == NULL){
        cout<<"Tidak ada pakaian dalam tumpukan setrika\n";
    } else {
        char decision;
        cout<<"Jumlah pakaian dalam tumpukkan setrika : " << stackSetrika.jumlahPakaian << endl;
        cout << "Lihat daftar pakaian? (Y/N)\n> ";
        cin >> decision;
        if (decision == 'Y' || decision == 'y')
            traversalPakaian(stackSetrika.listPakaian);
    }
}

// fungsi untuk memasukkan pakaian ke dalam rak
void masukkanKeRak(){
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
    };
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
    printEqualSign(37);
    cout << "Mode Setrika\n"
            "1. Cek Setrikaan\n"
            "2. Masukkan ke Rak\n"
            "Pilih menu setrika:\n> ";
    
    cin >> menuSelector;
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