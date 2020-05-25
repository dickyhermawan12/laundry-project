// struct untuk menyimpan informasi paket
struct Paket {
    // enum untuk id paket
    enum enumPaket {
        REGULER=1,
        EKSPRESS=2
    };
    // array untuk nama paket
    string nama[3] = {
        "Undefined",
        "Reguler",
        "Ekspress"
    };
    // array untuk biaya paket
    int biaya[3] = {
        0,
        6000,
        10000
    };
    // method untuk cetak paket
    string getNamaPaket(int input){
        return nama[input];
    }
} paket;

// struct untuk menyimpan informasi warna pakaian
struct WarnaPakaian {
    enum enumWarna {
        PUTIH=1,
        BERWARNA=2
    };
    // array untuk nama paket
    string pakaian[3] = {
        "Undefined",
        "Putih",
        "Berwarna"
    };
    // method untuk cetak warna
    string getWarnaPakaian(int input){
        return pakaian[input];
    }
} warna;

// struct untuk menyimpan informasi jenis pakaian
struct JenisPakaian {
    // enum untuk jenis pakaian
    enum enumJenis
    {
        KAOS=1,
        KEMEJA=2,
        CELANAPENDEK=3,
        CELANAPANJANG=4,
        JAS=5,
        DRESS=6,
        JAKET=7,
        HANDUK=8
    };
    // array untuk jenis pakaian
    string pakaian[9] = {
        "Undefined",
        "Kaos",
        "Kemeja",
        "Celana Pendek",
        "Celana Panjang",
        "Jas",
        "Dress",
        "Jaket",
        "Handuk"
    };
    // method untuk cetak pakaian
    string getJenisPakaian(int input){
        return pakaian[input];
    }
} jenis;

// struct untuk menyimpan informasi pakaian
struct Pakaian {
    // member struct
    int nomorOrder;
    int jenis;
    int warna;
    float berat;
    Pakaian *next;
    // constructor
    Pakaian(){
        next = NULL;
    }
    // method untuk insersi data pakaian
    void insertDataPakaian(int getNomorOrder){
        nomorOrder = getNomorOrder;
        // print list jenis pakaian
        cout << "Jenis pakaian yang diterima:\n";
        for(int i=1; i<=8; i++){
            cout << i << " - " << ::jenis.pakaian[i] << endl;
        }
        // input jenis pakaian
        cout << "Masukkan jenis pakaian (1-8) :\n> ";
        cin >> jenis;
        // print list warna pakaian
        cout << "Warna pakaian yang diterima:\n";
        for(int i=1; i<=2; i++){
            cout << i << " - " << ::warna.pakaian[i] << endl;
        }
        // input warna pakaian
        cout << "Masukkan warna pakaian (1/2) :\n> ";
        cin >> warna;
        // input berat pakaian
        cout << "Masukkan berat pakaian (gram) :\n> ";
        cin >> berat;
    }

};

// struct untuk menyimpan data pelanggan
struct DataPelanggan {
    // member struct
    enum enumKeteranganJumlah{
        AWAL=0,
        AKHIR=3
    };
    int nomorOrder;
    string nama;
    string alamat;
    int paket;
    float beratTotal;
    int jumlahPakaian[4];
    double totalBiaya;
    Pakaian *listPakaian;
    DataPelanggan *next;
    // constructor
    DataPelanggan(){
        nomorOrder = globalNomorOrder;
        beratTotal = 0;
        for(int i=0; i<4; i++){
            jumlahPakaian[i] = 0;
        }
        totalBiaya = 0;
        listPakaian = NULL;
        next = NULL;
    }
    // method untuk menghitung total biaya
    void countTotal(float tempBerat, int tempPaket){
        int biaya;
        if (tempPaket == ::paket.REGULER){
            biaya = ::paket.biaya[::paket.REGULER];
        } else if (tempPaket == ::paket.EKSPRESS){
            biaya = ::paket.biaya[::paket.EKSPRESS];
        }
        totalBiaya = ceil(tempBerat)*float(biaya);
    }
    // method untuk insersi pakaian
    void insertListPakaian(float &tempBerat){
        Pakaian *newPakaian = new Pakaian;
        newPakaian->insertDataPakaian(nomorOrder);
        if (listPakaian == NULL){
            listPakaian = newPakaian;
        } else {
            Pakaian *helper = listPakaian;
            while(helper->next!=NULL){
                helper=helper->next;
            }
            helper->next = newPakaian;
        }
        tempBerat = newPakaian->berat;
        if (newPakaian->warna == warna.PUTIH){
            jumlahPakaian[::warna.PUTIH]++;
        } else {
            jumlahPakaian[::warna.BERWARNA]++;
        }
    }
    // method untuk insersi data pelanggan
    void insertDataPelanggan(){
        float tempBerat;
        int count = 1;
        char decision;
        cout << "Masukkan nama pelanggan:\n> ";
        getline(cin, nama);
        cout << "Masukkan alamat:\n> ";
        getline(cin, alamat);
        // print list warna pakaian
        cout << "Paket yang dapat dipilih:\n";
        for(int i=1; i<=2; i++){
            cout << i << " - " << ::paket.nama[i] << endl;
        }
        cout << "Masukkan paket yang dipilih (1/2):\n> ";
        cin >> paket;
        while(true){
            cout << "Masukkan pakaian ke-" << count << "\n> ";
            insertListPakaian(tempBerat);
            beratTotal+=tempBerat;
            cout << "Apakah Anda ingin menambah pakaian? (Y/N)\n> ";
            cin >> decision;
            if (decision=='Y' || decision=='y'){
                count++;
                continue;
            } else {
                jumlahPakaian[AWAL] = count;
                break;
            }
        }
        beratTotal/=1000;
        countTotal(beratTotal, paket);
        globalNomorOrder++;
    }
    // method untuk mencetak data pelanggan
    void printDataPelanggan(){
        cout << "Nomor Order       : " << nomorOrder << endl;
        cout << "Nama Pelanggan    : " << nama << endl;
        cout << "Alamat            : " << alamat << endl;
        cout << "Paket             : " << ::paket.nama[paket] << endl;
        cout << "Berat Total (kg)  : " << beratTotal << endl;
        cout << "Jumlah Pakaian    : " << jumlahPakaian[AWAL] << endl;
        cout << "Total Biaya       : " << totalBiaya << endl;
    }
    // method untuk mengeluarkan pakaian dari list
};

// struct untuk menyimpan data antrian pelanggan
struct antrianPelanggan {
    DataPelanggan *head;
    DataPelanggan *tail;

    antrianPelanggan(){
        head = NULL;
        tail = NULL;
    }
} queueDataPelanggan;

// struct untuk menyimpan data setrika
struct StackSetrika {
    Pakaian *listPakaian;
    int jumlahPakaian;

    StackSetrika(){
        listPakaian = NULL;
        jumlahPakaian = 0;
    }

    void pushStackSetrika(Pakaian *&poppedPakaian){
        if (jumlahPakaian == 0){
            listPakaian = poppedPakaian;
        } else {
            poppedPakaian->next = listPakaian;
            listPakaian = poppedPakaian;
        }
        jumlahPakaian++;
    }
} stackSetrika;

// struct untuk menyimpan data rak
struct Rak {
    DataPelanggan *arrayRak[50];

    Rak(){
        for(int i=0; i<50; i++){
            arrayRak[i] = NULL;
        }
    }

    void isiRak(DataPelanggan *&poppedPelanggan){
        int nomorOrder = poppedPelanggan->nomorOrder;
        nomorOrder--;
        nomorOrder%=50;
        if (arrayRak[nomorOrder] == NULL){
            arrayRak[nomorOrder] = poppedPelanggan;
        } else {
            arrayRak[nomorOrder]->next = poppedPelanggan;
        }
    }

    void isiPakaianKeRak(Pakaian *&poppedPakaian){
        int nomorOrder = poppedPakaian->nomorOrder;
        nomorOrder--;
        DataPelanggan *helperPelanggan = arrayRak[nomorOrder];
        if (helperPelanggan->next != NULL){
            while (helperPelanggan != NULL){
                if (helperPelanggan->nomorOrder == poppedPakaian->nomorOrder){
                    break;
                } else {
                    helperPelanggan = helperPelanggan->next;
                }
            }
        }

        if (helperPelanggan->jumlahPakaian[3] == 0){
            helperPelanggan->listPakaian = poppedPakaian;
        } else {
            poppedPakaian->next = helperPelanggan->listPakaian;
            helperPelanggan->listPakaian = poppedPakaian;
        }
        helperPelanggan->jumlahPakaian[3]++;
    }
} rak;

// struct untuk menyimpan data mesin cuci
struct MesinCuci {
    int kapasitasPutih;
    int kapasitasWarna;
    Pakaian *mesinCuciPutih;
    Pakaian *mesinCuciWarna;
    // constructor
    MesinCuci(){
        kapasitasPutih = 0;
        kapasitasWarna = 0;
        mesinCuciPutih = NULL;
        mesinCuciWarna = NULL;
    }
    // method untuk push data ke mesin cuci
    void pushMesinCuci(Pakaian *&pakaianMasuk){
        if (pakaianMasuk->warna == warna.PUTIH){
            if (kapasitasPutih == 0){
                mesinCuciPutih = pakaianMasuk;
            } else {
                pakaianMasuk->next = mesinCuciPutih;
                mesinCuciPutih = pakaianMasuk;
            }
            kapasitasPutih++;
        } else {
            if (kapasitasWarna == 0){
                mesinCuciWarna = pakaianMasuk;
            } else {
                pakaianMasuk->next = mesinCuciWarna;
                mesinCuciWarna = pakaianMasuk;
            }
            kapasitasWarna++;
        }
    }
} mesinCuci;