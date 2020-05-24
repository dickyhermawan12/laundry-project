void cekSetrikaan(){
    if(stackSetrika.listPakaian == NULL)
        cout<<"Tidak ada pakaian dalam tumpukan setrika\n";
    else {
        cout<<"Ada pakaian\n";
        cout<<"Jumlah pakaian dalam tumpukkan setrika : "<<stackSetrika.jumlahPakaian<<endl;
    }
}

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
            "Pilih menu setrika:\n>";
    
    cin >> menuSelector;
    switch (menuSelector){
        case CEKSETRIKAAN:
            cekSetrikaan();
            break;
        case MASUKKANKERAK:
            cout << "Masukkan Ke Rak \n";
            break;
        default:
            cout << "Masukan Anda salah!" << endl;
    }
}