// file header untuk fungsi menu

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
            printEqualSign(37);
            cout << "          LAUNDRY CUAN-CUAN" << endl;
            printEqualSign(37);
            cout << "Menu\n"
                    "1. Antrian Pesanan\n"
                    "2. Atur Mesin Cuci\n"
                    "3. Atur Setrika\n"
                    "4. Ambil Pesanan\n"
                    "5. Konfigurasi\n"
                    "6. Keluar\n";
            printEqualSign(37);
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
                case KELUAR:
                    cout << "Sampai Jumpa Lagi!" << endl;
                    exit(1);
                default:
                    cout << "Masukan Anda salah!" << endl;
            }
            system("pause");
        }
    }
} menu;