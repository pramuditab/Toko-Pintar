#ifndef sortheader
#define sortheader

#include <string.h>
typedef struct barang_{			//inisialisasi struct untuk barang toko
	char namabarang[100];
	int stok;
	int harga;
} barang;

typedef struct troli_{ 			//inisialisasi struct untuk barang keranjang
	int index;
	int jumlah;
	int harga;
}troli;

extern barang listbarang[100];			//array untuk menyimpan data barang di toko
extern troli listkeranjang[100];		//array untuk menyimpan data barang di keranjang
int hasilcari[100];						//inisialisasi indeks hasil pencarian
int keranjanglen;					//banyaknya barang dalam keranjang
int baranglen;						//banyaknya barang dalam pencarian
int disk;								//inisialisasi diskon
char nuser[100];						//inisialisasi nama user

void sort(int len);						//inisialisasi fungsi yang berada pada sort.h
void sort_dsc_num(int n);
void sort_asc_num(int n);
void sort_dsc_name(int n);
void sort_asc_name(int n);

void sort(int len){			//fungsi untuk menampilkan pilihan sorting
	int pilih = 0;
	do{
		system("cls");
		header();
		printf("Hasil Pencarian Kamu: \n");
		int i;
		printf("\n%-5s %-50s %-8s %-15s", "No.","Nama Barang","Stok", "Harga Satuan");		//menampilkan pilihen sortir
		printf("\n------------------------------------------------------------------------------");
		for (i = 0 ; i < len; i++){		
			printf("\n%-5d %-50s %-8d Rp.%-15d",i+1 ,listbarang[hasilcari[i]].namabarang,listbarang[hasilcari[i]].stok, listbarang[hasilcari[i]].harga);
		}
		printf("\n------------------------------------------------------------------------------");
		printf("\n\n\nSortir berdasarkan: \n1. Abjad Terendah-Tertinggi\n2. Abjad Tertinggi-Terendah\n3. Harga Terendah-Tertinggi\n4. Harga Tertinggi-Terendah\n5. Masukkan ke keranjang \n6. Cari barang lagi");
		printf("\n\nPilih Menu yang kamu inginkan: ");
			if (scanf("%d",&pilih) == 1){
			switch(pilih){
			case 1: 
				sort_asc_name(len); //sortir berdasarkan abjad terendah-tertinggi
				break;
			case 2: 
				sort_dsc_name(len); //sortir berdasarkan abjar tertinggi-terendah
				break;
			case 3:
				sort_asc_num(len);	//sortir berdasarkan harga terendah-tertinggi
				break;
			case 4:
				sort_dsc_num(len);	//sortir berdasarkan harga tertinggi-terendah
				break;
			case 5:
				tambahkeranjang(len);	// memasukkan barang di pencarian ke keranjang
				break;
			case 6: 
				caribarang(); 
				break;				//kembali ke cari barang
			default: 				//error handling apabila input bukan diantara range 1-6
				printf("Input Angka dibatasi hanya 1 -6 saja");
				system("pause");
				break;
			}
		}
		else						//error handling untuk input berupa karakter
		{
			getchar();
			printf("Input Error!, Input hanya bisa berupa angka!");
			system("pause");
		}	
	}while(pilih != 5);	
}

void sort_dsc_num(int n){ 			//sortir berdasarkan harga tertinggi-terendah
    int i,j, temp;
    for(j = n;j > 0; j--){
        for(i = 1; i < j; i++){		
            if(listbarang[hasilcari[j-1]].harga > listbarang[hasilcari[j-i-1]].harga){		//penukaran hasilcari 
                temp = hasilcari[j-1];
              	hasilcari[j-1]= hasilcari[j-i-1];
              	hasilcari[j-i-1] = temp;               
            }
        }
    }
}
void sort_asc_num(int n){ 			//sortir berdasarkan harga terendah-tertinggi
	int i,j, temp;
 	for(j = n;j > 0; j--){
   		for(i = 1; i < j; i++){
            if(listbarang[hasilcari[j-1]].harga < listbarang[hasilcari[j-i-1]].harga){		//penukaran hasilcari
              	temp = hasilcari[j-1];
				hasilcari[j-1]= hasilcari[j-i-1];
              	hasilcari[j-i-1] = temp;               
            }
        }
	}
}
void sort_dsc_name(int n){ 			//sortir berdasarkan abjad tertinggi-terendah
	int i,j,temp;
	char s[100];
	  for(i=0;i<n;i++){
      	for(j=i+1;j<n;j++){
	         if(stricmp(listbarang[hasilcari[i]].namabarang,listbarang[hasilcari[j]].namabarang)<0)		//penukaran hasilcari 
			 {
	         	temp =  hasilcari[j];
	         	hasilcari[j] = hasilcari[i];
	         	hasilcari[i] = temp;
	         }
      	}
   	}
}
void sort_asc_name(int n){			//sortir berdasarkan abjad terendah-tertinggi
	int i,j,temp;
	char s[100];
	  for(i=0;i<n;i++){
      	for(j=i+1;j<n;j++){
	         if(stricmp(listbarang[hasilcari[i]].namabarang,listbarang[hasilcari[j]].namabarang)>0)		//penukaran hasilcari 
			 {
	         	temp =  hasilcari[j];
	         	hasilcari[j] = hasilcari[i];
	         	hasilcari[i] = temp;
	         }
      	}
   	}
}

#endif
