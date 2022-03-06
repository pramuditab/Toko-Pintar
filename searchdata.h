#ifndef searchdata
#define searchdata

#include <string.h>						//inisialisasi library string

extern barang listbarang[100];			//array untuk menyimpan data barang di toko
extern troli listkeranjang[100];		//array untuk menyimpan data barang di keranjang
char nuser[100];						//nama user

int find();
int search(char str[100], char substr[100]);

int find(){								//fungsi untuk mencari barang
	int caricounter,i,j = 0;
	printf("\n\nKamu cari barang apa? (masukkan -1 untuk kembali ke menu utama): ");		//meminta user memasukkan keyword
	char caribarang[100];
	getchar();
	scanf("%[^\n]s",&caribarang);
	if(strcmp(caribarang,"-1")==0){		//kembali ke menu utama ketika input sama dengan -1
		mainmenu();
	}
	for (i = 0 ; i < baranglen; i++){	//fungsi untuk mencari barang
		if (search(listbarang[i].namabarang, caribarang) == 1){
			hasilcari[j] = i;
			j++;						//jumlah barang yang ada di array hasilcari saat ini
		}
	}
	printf("\n");
	system("cls");
	header();
	printf("Hasil cari untuk: %s\n", caribarang);
	printf("\n%-5s %-50s %-8s %-15s", "No.","Nama Barang","Stok", "Harga Satuan");				//menampilkan hasil pencarian barang
	printf("\n------------------------------------------------------------------------------");
	for (i = 0 ; i < j; i++){		
		printf("\n%-5d %-50s %-8d Rp.%-15d",i+1 ,listbarang[hasilcari[i]].namabarang,listbarang[hasilcari[i]].stok, listbarang[hasilcari[i]].harga);
	}
	printf("\n");
	return j;
}

int search(char str[100], char substr[100]){			//fungsi untuk partial search
    int i = 0, j = 0;
	char str1;
	char str2;
	
	char substr1;
	char substr2;
	
    while (((str[j] != '\0') && (substr[i] != '\0')) ) {	//loop selama indeks j bukan merupakan akhir str dan indeks i bukan merupakan akhir substr
  		str1 = str[j] + 32;
		str2 = str[j] - 32;
	
		substr1 = substr[i] + 32;
		substr2 = substr[i] - 32;
        if ( (str[j] != substr[i]) && (str2 != substr[i]) && (str1 != substr[i]) 	//pengecekan apakah str sama dengan substr, case insensitive
		&& (str[j] != substr1) && (str[j] != substr2) ) {
            j++;
            i = 0;
        }
        else {
            i++;
            j++;
        }
    }
    if (substr[i] == 0)										//substr terdapat didalam str
        return 1;	
    else													//tidak terdapat substr didalam str
        return -1;
}

#endif
