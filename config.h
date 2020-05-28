// file header untuk mengatur konfigurasi jenis dan paket

// fungsi untuk mengubah nama dan menambah jenis pakaian
void ubahJenis(){
    enum enumUbahJenis{
        UBAHJENIS = 1,
        TAMBAHJENIS
    };
    int menuSelector = 0, inMenuSelector = 0;
    string changes;
    cout << "Jenis pakaian yang diterima saat ini:\n";
    for (int i = 1; i <= ::jenis.maxJenis; i++){
        cout << i << " - " << ::jenis.pakaian[i] << endl;
    }
    cout << "\n1. Ubah jenis pakaian\n"
            "2. Tambah jenis pakaian\n"
            "Masukkan pilihan:\n> ";
    cin >> menuSelector;
    printEqualSign(50);
    switch (menuSelector){
        case UBAHJENIS:
            while (true){
                cout << "Apa yang akan diubah?\n> ";
                cin >> inMenuSelector;
                if (!cin.fail() && (inMenuSelector >= 1 && inMenuSelector <= ::jenis.maxJenis)){
                    break;
                }
                fail();
                cout << "Input Anda salah!" << endl;
            }
            cout << "Mengubah " << ::jenis.pakaian[inMenuSelector] << "..." << endl;
            cin.ignore();
            cout << "Ubah menjadi?\n> ";
            getline(cin, changes);
            ::jenis.pakaian[inMenuSelector] = changes;
            cout << "Jenis terubah!\n\n";
            break;
        case TAMBAHJENIS:
            if (::jenis.maxJenis == 19){
                cout << "Jenis pakaian penuh!\n\n";
                break;
            }
            ::jenis.maxJenis++;
            cin.ignore();
            cout << "Ingin menambah apa?\n> ";
            getline(cin, changes);
            ::jenis.pakaian[::jenis.maxJenis] = changes;
            cout << "Jenis " << changes << " ditambah!\n\n";
            break;
        default:
            if (cin.fail()){
                fail();
            }
            cout << "Masukan Anda salah!\n\n";
    }
}

// fungsi untuk mengubah biaya paket
void ubahBiaya(){
    int menuSelector = 0;
    int changes;
    cout << "Biaya paket saat ini:\n";
    for (int i = 1; i <= 2; i++){
        cout << i << " - " << ::paket.nama[i] << " - " << ::paket.biaya[i] << endl;
    }
    cout << "\n1. Ubah biaya reguler\n"
            "2. Ubah biaya ekspress\n"
            "Masukkan pilihan:\n> ";
    cin >> menuSelector;
    printEqualSign(50);
    switch (menuSelector){
        case (::paket.REGULER):
            while (true){
                cout << "Ubah menjadi?\n> ";
                cin >> changes;
                if (!cin.fail() && changes > 0){
                    break;
                }
                fail();
                cout << "Input Anda salah!" << endl;
            }
            ::paket.biaya[::paket.REGULER] = changes;
            cout << "Biaya reguler terubah!\n\n";
            break;
        case (::paket.EKSPRESS):
            while (true){
                cout << "Ubah menjadi?\n> ";
                cin >> changes;
                if (!cin.fail() && changes > 0){
                    break;
                }
                fail();
                cout << "Input Anda salah!" << endl;
            }
            ::paket.biaya[::paket.EKSPRESS] = changes;
            cout << "Biaya ekspress terubah!\n\n";
            break;
        default:
            if (cin.fail()){
                fail();
            }
            cout << "Masukan Anda salah!\n\n";
    }
}

void ubahKapasitas(){
    int changes;
    cout << "Kapasitas masing-masing mesin cuci saat ini: " << maxCapacity << endl;
    while (true){
        cout << "Ubah menjadi?\n> ";
        cin >> changes;
        if (changes >= 0 && changes <= 50){
            maxCapacity = changes;
            cout << "Kapasitas mesin cuci maksimal berhasil diubah\n"
                    "menjadi " << maxCapacity << "!\n\n";
            break;
        } else {
            if (changes < 0){
                cout << "Input tidak boleh negatif!" << endl;
            }
            if (changes > 50){
                cout << "Input Anda terlalu besar!" << endl;
            }
            if (cin.fail()){
                fail();
            }
            cout << "Input Anda salah!" << endl;
        }
    }
}

// menu konfigurasi
void configuration(){
    enum enumConfiguration {
        UBAHJENIS=1,
        UBAHBIAYA,
        UBAHKAPASITAS
    };
    int menuSelector = 0;
    system("cls");
    printEqualSign(50);
    cout << "                  Konfigurasi\n";
    printEqualSign(50);
    cout << "1. Ubah Jenis Pakaian\n"
            "2. Ubah Biaya Paket\n"
            "3. Ubah Kapasitas Mesin Cuci\n"
            "Masukkan pilihan:\n> ";
    cin >> menuSelector;
    printEqualSign(50);
    switch (menuSelector){
        case UBAHJENIS:
            ubahJenis();
            break;
        case UBAHBIAYA:
            ubahBiaya();
            break;
        case UBAHKAPASITAS:
            ubahKapasitas();
            break;
        default:
            cout << "Masukan Anda salah!\n\n";
    }
}