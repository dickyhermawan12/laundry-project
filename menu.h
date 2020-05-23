struct menu {
    int menuSelector;
    enum menuEnum
    {
        TAMBAHPESANAN=1,
        ATURMESINCUCI,
        ATURSETRIKA,
        SIMPANRAK,
        AMBILPESANAN,
        KONFIGURASI,
        KELUAR
    };
    // constructor
    menu(){
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
                    "3. Atur Setrikaan\n"
                    "4. Simpan ke Rak\n"
                    "5. Ambil Pesanan\n"
                    "6. Konfigurasi\n"
                    "7. Keluar\n";
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
                    cout << "Mengatur Setrika" << endl;
                    break;
                case SIMPANRAK:
                    cout << "Menyimpan ke Rak" << endl;
                    break;
                case AMBILPESANAN:
                    menuRak();
                    break;
                case KONFIGURASI:
                    cout << "Memulai Konfigurasi" << endl;
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
} mainMenu;