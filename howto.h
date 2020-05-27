void carapakai(){
    system("cls");
    printEqualSign(80);
    cout << "                            Cara Menggunakan Program" << endl;
    printEqualSign(80);
    cout << "Deskripsi: Program ini merupakan program untuk mengelola kegiatan operasional\n"
            "laundry kiloan.\n\n"
            "Tujuan: Program ini bertujuan untuk mengawasi alur penerimaan pakaian dari\n"
            "antrian pelanggan hingga pakaian selesai dicuci dan disetrika untuk kemudian\n"
            "diambil oleh pelanggan\n\n"
            "Cara kerja:\n"
            "- Anda dapat mulai memasukkan pelanggan dengan mengisi data diri beserta\n"
            "pakaian yang akan dilaundry pada menu Antrian Pesanan -> Tambah Pelanggan\n"
            "Antrian akan disortir berdasarkan prioritas paket pemesanan yang dipilih\n"
            "(paket express > reguler). Setelah itu, Anda dapat melihat antrian pada\n"
            "menu Antrian Pelanggan -> Lihat Antrian. Pakaian yang akan dilaundry per\n"
            "pelanggannya juga dapat dilihat pada menu Antrian Pelanggan -> Cetak Pakaian\n"
            "Pelanggan dengan memasukkan Nomor Order pelanggan yang dimaksud.\n"
            "- Anda kemudian dapat memproses antrian dan memasukkan pakaian pelanggan\n"
            "pada antrian terdepan satu per satu dengan mengakses menu Atur Mesin Cuci ->\n"
            "Isi Mesin Cuci. Secara otomatis, rak pakaian untuk pelanggan yang diproses\n"
            "akan dipersiapkan. Anda kemudian dapat melihat pakaian yang ada pada mesin\n"
            "cuci pada menu Atur Mesin Cuci -> Cek Mesin Cuci. Kapasitas mesin cuci\n"
            "secara default adalah 10 per mesin cucinya\n"
            "- Setelah selesai mencuci, Anda dapat memindahkan pakaian ke tumpukan setrika\n"
            "dengan mengakses menu Atur Mesin Cuci -> Keluarkan Pakaian dari Mesin Cuci.\n"
            "Dengan begitu, pakaian dari kedua mesin cuci akan segera dikosongkan untuk\n"
            "kemudian disetrika.\n"
            "- Anda dapat melihat pakaian dalam tumpukan setrika pada menu Atur Setrika ->\n"
            "Cek Setrikaan. Setelah selesai menyetrika, Anda dapat memindahkan pakaian\n"
            "ke rak masing-masing pelanggan yang telah dipersiapkan sebelumnya.\n"
            "- Anda dapat mengakses rak pelanggan pada menu Ambil Pesanan -> Cek Nomor Order\n"
            "pada Rak. Jika seluruh pakaian telah selesai dicuci dan disetrika, Anda dapat\n"
            "menyelesaikan proses laundry dengan mengakses menu Ambil Pesanan -> Ambil\n"
            "Pesanan dari Rak.\n"
            "- Anda dapat melakukan konfigurasi untuk jenis pakaian dan biaya per paket\n"
            "laundry pada menu Konfigurasi\n\n"
            " ~~~~~~~~~~~~~~~ Happy Laundrying  ~~~~~~~~~~~~~~~ \n\n";
}