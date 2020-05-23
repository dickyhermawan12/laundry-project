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

void traversalAntrian(){
    DataPelanggan *helper = queueDataPelanggan.head;
    int count = 1;
    if (helper == NULL){
        cout << "Antrian Kosong!" << endl;
    } else {
        do {
            printEqualSign(37);
            cout << "                " << count << endl;
            printEqualSign(37);
            helper->printDataPelanggan();
            printEqualSign(37);
            helper=helper->next;
            count++;
        } while(helper!=NULL);
    }
}

void traversalPakaian(){
    int id, flag = 0, no = 1;
    cout << "Masukkan ID pesanan:\n> ";
    cin >> id;
    DataPelanggan *helpAntrian = queueDataPelanggan.head;
    while(helpAntrian!=NULL){
        if (helpAntrian->nomorOrder == id){
            flag = 1;
            Pakaian *helpPakaian = helpAntrian->listPakaian;
            printEqualSign(37);
            cout << "Pemilik : " << helpAntrian->nama << endl;
            do {
                printEqualSign(37);
                cout << "Pakaian ke-" << no << endl;
                cout << "Jenis Pakaian: " << jenis.pakaian[helpPakaian->jenis] << endl;
                cout << "Warna Pakaian: " << warna.pakaian[helpPakaian->warna] << endl;
                printEqualSign(37);
                helpPakaian=helpPakaian->next;
                no++;
            } while (helpPakaian!=NULL);
            break;
        } else {
            helpAntrian=helpAntrian->next;
        }
    }
    if (flag == 0){
        cout << "Tidak ada nomor antrian!" << endl;
    }
}

void menuAntrianPesanan(){
    enum enumMenuAntrianPesanan
    {
        TAMBAHPELANGGAN=1,
        LIHATANTRIAN,
        CETAKPAKAIAN
    };
    int menuSelector = 0;
    system("cls");
    printEqualSign(37);
    cout << "Antrian Pesanan\n";
    printEqualSign(37);
    cout << "1. Tambah Pelanggan\n"
            "2. Lihat Antrian\n"
            "3. Cetak Pakaian Pelanggan\n"
            "Masukkan pilihan:\n> ";
    cin >> menuSelector;
    switch (menuSelector){
        case TAMBAHPELANGGAN:
            enqueueAntrian();
            break;
        case LIHATANTRIAN:
            traversalAntrian();
            break;
        case CETAKPAKAIAN:
            traversalPakaian();
            break;
        default:
            cout << "Masukan Anda salah!" << endl;
    }
}