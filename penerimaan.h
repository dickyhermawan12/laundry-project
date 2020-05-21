
void enqueueAntrian(){
    dataPenerimaan* newPelanggan = new dataPenerimaan;
    cin.ignore();
    newPelanggan->insertDataPelanggan();
    if (queueDataPenerimaan.head == NULL){
        queueDataPenerimaan.head = newPelanggan;
        queueDataPenerimaan.tail = newPelanggan;
    } else {
        // priority queue
        dataPenerimaan *helper = queueDataPenerimaan.head;
        while(helper->next!=NULL){
            if(helper->next->paket>=newPelanggan->paket){
                helper=helper->next;
            } else {
                break;
            }
        }
        if ((helper == queueDataPenerimaan.head) && (helper->paket < newPelanggan->paket)){
            newPelanggan->next = queueDataPenerimaan.head;
            queueDataPenerimaan.head = newPelanggan;
        } else if (helper->next!=NULL){
            newPelanggan->next = helper->next;
            helper->next = newPelanggan;
        } else {
            queueDataPenerimaan.tail->next = newPelanggan;
            queueDataPenerimaan.tail = newPelanggan;
        }
    }
}

void dequeueAntrian(dataPenerimaan *&temp){
    temp = queueDataPenerimaan.head;
    if (queueDataPenerimaan.head->next == NULL){
        queueDataPenerimaan.head = NULL;
        queueDataPenerimaan.tail = NULL;
    } else {
        queueDataPenerimaan.head = queueDataPenerimaan.head->next;
    }
    temp->next = NULL;
}

void traversalAntrian(){
    dataPenerimaan* helper = queueDataPenerimaan.head;
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
    dataPenerimaan* helpAntrian = queueDataPenerimaan.head;
    while(helpAntrian!=NULL){
        if (helpAntrian->nomorOrder==id){
            flag = 1;
            pakaian* helpPakaian = helpAntrian->listPakaian;
            do {
                printEqualSign(37);
                cout << "Pakaian ke-" << no << endl;
                cout << "Jenis Pakaian: " << helpPakaian->jenis << endl;
                cout << "Warna Pakaian: " << helpPakaian->warna << endl;
                printEqualSign(37);
                helpPakaian=helpPakaian->next;
                no++;
            } while (helpPakaian!=NULL);
            break;
        } else {
            helpAntrian=helpAntrian->next;
        }
    }
    if (flag==0){
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