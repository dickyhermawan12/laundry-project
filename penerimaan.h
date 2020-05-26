// file header untuk fungsi-fungsi penerimaan pelanggan

// fungsi untuk melakukan enqueue antrian terdepan
void enqueueAntrian(){
    DataPelanggan *newPelanggan = new DataPelanggan;
    cin.ignore();
    newPelanggan->insertDataPelanggan();
    if (queueDataPelanggan.head == NULL){
        queueDataPelanggan.head = newPelanggan;
        queueDataPelanggan.tail = newPelanggan;
    } else {
        // priority queue
        DataPelanggan *helper = queueDataPelanggan.head;
        while(helper->next!=NULL){
            if(helper->next->paket>=newPelanggan->paket){
                helper=helper->next;
            } else {
                break;
            }
        }
        if ((helper == queueDataPelanggan.head) && (helper->paket < newPelanggan->paket)){
            newPelanggan->next = queueDataPelanggan.head;
            queueDataPelanggan.head = newPelanggan;
        } else if (helper->next!=NULL){
            newPelanggan->next = helper->next;
            helper->next = newPelanggan;
        } else {
            queueDataPelanggan.tail->next = newPelanggan;
            queueDataPelanggan.tail = newPelanggan;
        }
    }
}

// fungsi untuk melakukan dequeue antrian
void dequeueAntrian(DataPelanggan *&temp){
    temp = queueDataPelanggan.head;
    if (queueDataPelanggan.head->next == NULL){
        queueDataPelanggan.head = NULL;
        queueDataPelanggan.tail = NULL;
    } else {
        queueDataPelanggan.head = queueDataPelanggan.head->next;
    }
    temp->next = NULL;
}

// fungsi untuk melakukan traversal antrian
void traversalAntrian(){
    DataPelanggan *helper = queueDataPelanggan.head;
    int count = 1;
    if (helper == NULL){
        cout << "Antrian Kosong!" << endl << endl;
    } else {
        do {
            printEqualSign(50);
            cout << "                         " << count << endl;
            printEqualSign(50);
            helper->printDataPelanggan();
            printEqualSign(50);
            helper=helper->next;
            count++;
        } while(helper!=NULL);
    }
}

// fungsi untuk melakukan traversal pakaian (penerimaan)
void traversalPakaianAwal(){
    int id, flag = 0;
    cout << "Masukkan nomor order pesanan:\n> ";
    cin >> id;
    DataPelanggan *helpAntrian = queueDataPelanggan.head;
    while(helpAntrian != NULL){
        if (helpAntrian->nomorOrder == id){
            flag = 1;
            printEqualSign(50);
            cout << "Pemilik : " << helpAntrian->nama << endl;
            traversalPakaian(helpAntrian->listPakaian);
            break;
        } else {
            helpAntrian=helpAntrian->next;
        }
    }
    if (flag == 0){
        cout << "Tidak ada nomor antrian!" << endl << endl;
    }
}

// fungsi untuk menu antrian pesanan
void menuAntrianPesanan(){
    enum enumMenuAntrianPesanan
    {
        TAMBAHPELANGGAN=1,
        LIHATANTRIAN,
        CETAKPAKAIAN
    };
    int menuSelector = 0;
    system("cls");
    printEqualSign(50);
    cout << "                  Antrian Pesanan\n";
    printEqualSign(50);
    cout << "1. Tambah Pelanggan\n"
            "2. Lihat Antrian\n"
            "3. Cetak Pakaian Pelanggan\n"
            "Masukkan pilihan:\n> ";
    cin >> menuSelector;
    printEqualSign(50);
    switch (menuSelector){
        case TAMBAHPELANGGAN:
            enqueueAntrian();
            break;
        case LIHATANTRIAN:
            traversalAntrian();
            break;
        case CETAKPAKAIAN:
            traversalPakaianAwal();
            break;
        default:
            if (cin.fail()){
                fail();
            }
            cout << "Masukan Anda salah!" << endl << endl;
    }
}