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
    switch (menuSelector){
        case UBAHJENIS:
            cout << "Apa yang akan diubah?\n> ";
            cin >> inMenuSelector;
            cout << "Mengubah " << ::jenis.pakaian[inMenuSelector] << "..." << endl;
            cin.ignore();
            cout << "Ubah menjadi?\n> ";
            getline(cin, changes);
            ::jenis.pakaian[inMenuSelector] = changes;
            cout << "Jenis terubah!" << endl;
            break;
        case TAMBAHJENIS:
            ::jenis.maxJenis++;
            cin.ignore();
            cout << "Ingin menambah apa?\n> ";
            getline(cin, changes);
            ::jenis.pakaian[::jenis.maxJenis] = changes;
            cout << "Jenis " << changes << " ditambah!" << endl;
            break;
        default:
            cout << "Masukan Anda salah!" << endl;
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
    switch (menuSelector){
        case (::paket.REGULER):
            cout << "Ubah menjadi?\n> ";
            cin >> changes;
            ::paket.biaya[::paket.REGULER] = changes;
            cout << "Biaya reguler terubah!" << endl;
            break;
        case (::paket.EKSPRESS):
            cout << "Ubah menjadi?\n> ";
            cin >> changes;
            ::paket.biaya[::paket.EKSPRESS] = changes;
            cout << "Biaya ekspress terubah!" << endl;
            break;
        default:
            cout << "Masukan Anda salah!" << endl;
    }
}

// menu konfigurasi
void configuration(){
    enum enumConfiguration {
        UBAHJENIS=1,
        UBAHBIAYA
    };
    int menuSelector = 0;
    system("cls");
    printEqualSign(37);
    cout << "Konfigurasi\n"
            "Apa yang ingin diubah?\n"
            "1. Jenis Pakaian\n"
            "2. Biaya Paket\n"
            "Masukkan pilihan:\n> ";
    cin >> menuSelector;
    switch (menuSelector){
        case UBAHJENIS:
            ubahJenis();
            break;
        case UBAHBIAYA:
            ubahBiaya();
            break;
        default:
            cout << "Masukan Anda salah!" << endl;
    }
}