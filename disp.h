#ifndef disp
#define disp
#include <string.h>					//inisialisasi library string

extern barang listbarang[100];		//inisialisasi struk 
extern troli listkeranjang[100];	
char nuser[100];					//inisialisasi nama user

void displaykeranjang();			//inisialisasi fungsi berada pada disp.h
void display(int len);
void struk();
void hasilstruk(int disk);
void header();

void displaykeranjang(){				//fungsi untuk menampilkan list barang saat ini
	int i, total = 0;
	printf("\n%-5s %-50s %-8s %-15s %-15s", "No.","Nama Barang","Jumlah", "Harga Satuan", "Harga Total");
	printf("\n---------------------------------------------------------------------------------------------");
	char b[100];
	for (i = 0 ; i < keranjanglen; i++){	//menampilkan list barang
		
		sprintf(b, "Rp.%d",listkeranjang[i].harga);
		printf("\n%-5d %-50s %-8d Rp.%-13d %10s",i+1 ,listbarang[listkeranjang[i].index].namabarang,listkeranjang[i].jumlah,listbarang[listkeranjang[i].index].harga,b );
		total += listkeranjang[i].harga;
	}
	printf("\n---------------------------------------------------------------------------------------------");
	char a[100];
	sprintf(a,"Rp.%d", total);
	printf("\nSubtotal :  %81s", a);			//nilai total barang di keranjang
}
void display(int len){							//menampilkan barang yang diambil secara random
	int i,j;
	printf("\n%-5s %-35s %-8s %-15s", "No.","Nama Barang","Stok", "Harga Satuan");
	printf("\n---------------------------------------------------------------");	
	for (i = 0 ; i < len; i++){
		j = Random(0,baranglen-1);		//fungsi random untuk nomor array
		printf("\n%-5d %-35s %-8d Rp.%-15d",i+1 ,listbarang[j].namabarang,listbarang[j].stok, listbarang[j].harga);
	}
}
void struk(){				//menampilkan struk user
    int input = 0;
	system("cls");
    header();
    hasilstruk(disk);		//fungsi display dari struk
    do{						//mengulang fungsi struk hingga user memasukkan angka 99
    	printf("Masukkan 99 untuk keluar: ");
    	scanf("%d", &input);
    	if(input != 99){
    		struk();
		}
	}while(input != 99);
    keluar();   
}
void hasilstruk(int disk){			//fungsi display dari struk
    if (keranjanglen == 0){			//barang masih kosong sehingga struk tidak dicetak
        printf("\nAnda belum memasukkan barang ke keranjang Anda! Struk belum dapat dibuat\n");
        system("pause");
        mainmenu();
    }
    else{							//tampilan struk
    	int i;
        printf("\n\nSelamat, Anda mendapatkan DISKON sebesar %d%% dalam transaksi ini!\n", disk);
        printf("Berikut Struk Anda\n");
        printf("\n\n\n                              TOKO PINTAR\n");
        printf("                 Jl. Koala Utara No. 14 Kota Bekasi\n");
        printf("---------------------------------------------------------------------\n");
        time_t t = time(NULL);
        char st[100];
        char c[100];
        for (i = 0 ; i < 19;i++){
        	c[i] = nuser[i];
		}
        sprintf(st,"2.1.27 972724/%s/TR.02",c);					//menampilkan nama user di struk
        printf("%-39s     %s",st, asctime(localtime(&t)));		//menampilkan waktu request struk
        int sum;
        for (i = 0 ; i < keranjanglen; i++){					//menampilkan  list belanja

            printf("\n%-50s%-3d Rp.%11d",listbarang[listkeranjang[i].index].namabarang,listkeranjang[i].jumlah, listkeranjang[i].harga);
            sum += listkeranjang[i].harga;
        }
        int diskon;
        diskon = disk * sum;
        diskon = diskon/100;									//perhitungan diskon yang diinisialisasi dari awal program
        int total = sum - diskon;								//perhitungan total belanja

        char disc[100];
        sprintf(disc, "(Rp.%d)", diskon);

        printf("\n                                 ------------------------------------\n");
        printf("                                   HARGA JUAL\t:     Rp.%11d\n", sum);
        printf("                                   DISKON    \t:     %15s\n", disc);
        printf("                                 ------------------------------------\n");
        printf("                                   TOTAL     \t:     Rp.%11d\n", total);
        printf("                                   ANDA HEMAT\t:     Rp.%11d\n", diskon);
        printf("\n\n               TERIMAKASIH, SELAMAT BELANJA KEMBALI\n");
        printf("==============      LAYANAN KONSUMEN TOKO PINTAR     ==============\n");
        printf("                SMS 0888 8888 8888    CALL 1234 280          \n");
        printf("              EMAIL:TOKOPINTAR@TOKOSERBAADA.CO.ID                \n");
    }
}

void header(){			//header dari aplikasi
	printf("\n-----------------------------------------------------------------------------------------------------\n");
	printf("                                             TOKO PINTAR v2.0\n");
	printf("                                  Jl. Koala Utara No. 14 Kota Bekasi\n");
	printf("-----------------------------------------------------------------------------------------------------\n\n");
}

#endif

