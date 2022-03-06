#include <stdio.h>			//inisialisasi library yang akan digunakan
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "sortheader.h"			//inisialisasi file header yang digunakan dalam program ini
#include "databaseheader.h"
#include "keranjangheader.h"
#include "randomize.h"
#include "searchdata.h"
#include "disp.h"

#define ENTER 13
#define TAB 9
#define BKSP 8

char nuser[100];			//variabel untuk menyimpan nama user yang nanti digunakan untuk nama di struk
barang listbarang[100];		//array untuk menyimpan database barang
troli listkeranjang[100];	//array untuk menyimpan database keranjang pengguna

void mainmenu();			//prototipe dari fungsi yang berada dalam main program
void caribarang();
void keranjang();
void checkout();
void help();

int main(){
	disk = diskonfunc();	//mengambil diskon yang dirandom pada awal program
	database();				//memasukkan data ke array listbarang
	page();
	user();					//sambutan untuk user 
	mainmenu();				//menu utama dari aplikasi
	return 0;
}
void signup(){
	system("cls");
	header();
	char username[100];
	char pass[100];
	printf("\nMasukkan username dan password anda\n");
	printf("Username: ");
	scanf("%s", &username);
	printf("Password: ");
	scanf("%s", &pass);
	printf("%s, %s", username, pass);
	system("pause");
}
void login() {
    char username[100], pass[100], temp;
    int i;

    while(1) {
        system("cls");

        /* Asks for user's username */
        printf("Username: ");
        scanf("%s", &username);

        /* Asks for user's password */
        i = 0;
        printf("Password: ");
        while(1) {
        temp = getch(); // Inputs one single character of password without printing to terminal

            /* Evaluating the ASCII value of the current one single character of password */
            if(temp == ENTER || temp == TAB) {
                pass[i] = '\0';
                break;
            } else if(temp == BKSP) {
                if(i > 0) {
                    i--;	1
                    printf("\b \b"); // Backspace one character
                }
            } else {
                pass[i] = temp;
                printf("*");
                i++;
            }

        }

    }

    printf("\n\nLogin successful.");
    getch();
    system("pause");
}
void page(){
	int input;
	system("cls");
	header();
	printf("\nSelamat datang di aplikasi Toko Pintar. Silahkan pilih menu di bawah: \n");
	printf("\n1. Sign Up\n2. Login\n3. Keluar\n=> ");
	if(scanf("%d", &input) == 1){									//pilihan menu
		switch(input){ 
			case 1: 
				signup(); 
				break;
			case 2: 
				login(); 
				break;
			case 3: 
					system("cls");
					header();
					printf("\nAnda yakin ingin keluar?");
					printf("\n99. Ya \n2. Tidak \n=> ");		//untuk mencegah user tidak sengaja keluar program
					do{
						if(scanf("%d", &input)== 1){			
							if(input == 99){					//kondisi ketika input = 99 atau input != 99
								keluar();
							} else {
								page();
							}
						}
						else{									//error handling apabila input berupa karakter
							printf("Masukan hanya angka.\n");
							getchar();
							system("pause");
						}		
					}while(input != 99);
					break;
			default: printf("Nilai diluar jangkauan.\n");		//error handling apabila angka yang diinput tidak diantara range 1-5
					 system("pause");
					 page();
					 break;
		}
}
}

void mainmenu(){													//menu utama dari aplikasi
	int input;
	system("cls");
	header();
	printf("\nSelamat datang di aplikasi Toko Pintar. Silahkan pilih menu di bawah: \n");
	printf("\n1. Cari Barang \n2. Cek Keranjang \n3. Checkout \n4. Bantuan \n5. Keluar");
	printf("\n\n=> ");
	if(scanf("%d", &input) == 1){									//pilihan menu
		switch(input){ 
			case 1: 
				caribarang(); 
				break;
			case 2: 
				keranjang(); 
				break;
			case 3: checkout(); break;
			case 4: help(); break;
			case 5: 
					system("cls");
					header();
					printf("\nAnda yakin ingin keluar?");
					printf("\n99. Ya \n2. Tidak \n=> ");		//untuk mencegah user tidak sengaja keluar program
					do{
						if(scanf("%d", &input)== 1){			
							if(input == 99){					//kondisi ketika input = 99 atau input != 99
								keluar();
							} else {
								mainmenu();
							}
						}
						else{									//error handling apabila input berupa karakter
							printf("Masukan hanya angka.\n");
							getchar();
							system("pause");
						}		
					}while(input != 99);
					break;
			default: printf("Nilai diluar jangkauan.\n");		//error handling apabila angka yang diinput tidak diantara range 1-5
					 system("pause");
					 mainmenu();
					 break;
		}	
	} else {													//error handling untuk input berupa karakter
		printf("Masukan hanya angka.\n");
		getchar();
		system("pause");
		mainmenu();
	}
}

void caribarang(){                							//menu pencarian barang
    int input;
    system("cls");
    header();
    printf("Barang promo saat ini: \n");
    display(5);                    							//menampilkan barang promo yang dirandomize
    int len = find();			   							//mencari barang dan mengembalikan banyaknya barang berdasarkan hasil pencarian
    printf("\nSilahkan pilih menu di bawah: \n");
    printf("\n1. Tambah ke keranjang \n2. Cari barang lagi \n3. Cek keranjang \n4. Sortir \n5. Menu utama");
    printf("\n\n=> ");
    if(scanf("%d", &input) == 1){
        switch(input){ 										//pilihan menu
            case 1: tambahkeranjang(len); break;
            case 2: caribarang();break;
            case 3: keranjang(); break;
            case 4: sort(len); break;
            case 5: mainmenu(); break;
            default: printf("Nilai diluar jangkauan.\n");
                     system("pause");
                     caribarang();
                     break;
        }    
    } else {
        printf("Masukan hanya angka.\n");            		//error handling untuk input berupa karakter
        getchar();
        system("pause");
        caribarang();
    }    
}

void keranjang(){											//menu untuk menampikan keranjang saat ini dan memodifikasi pesanan di keranjang
	int input, i;
	system("cls");
	header();
	displaykeranjang();										//fungsi untuk menampilkan list keranjang
	printf("\n\nSilahkan pilih menu di bawah: \n");
	printf("\n1. Cari barang \n2. Hapus barang \n3. Menu utama");
	printf("\n\n=> ");
	if(scanf("%d", &input) == 1){							//pilihan menu
		switch(input){ 
			case 1: 
				caribarang(); 
				break;
			case 2: 
				hapuskeranjang(); 
				break;
			case 3: mainmenu();
					break;	
			default: printf("Nilai diluar jangkauan.\n");	//apabila input tidak berada dalam range 1-3
					 system("pause");
					 mainmenu();
					 break;
		}	
	} else {												//error handling untuk input berupa karakter
		printf("Masukan hanya angka.\n");
		getchar();
		system("pause");
		mainmenu();
	}
}

void checkout(){											//menu untuk melakukan checkout
	int input;
	system("cls");
	header();
	displaykeranjang();										//menampilkan barang di keranjang saat ini sebelum checkout
	printf("\n\nApakah anda yakin ingin checkout (Jika berhasil checkout anda tidak bisa kembali ke menu utama)?");
	printf("\n1. Ya \n2. Tidak");
	printf("\n=> ");
	if(scanf("%d", &input) == 1){							//pilihan menu
		switch(input){ 
			case 1: 
				struk(); 
				break;
			case 2: 
				mainmenu(); 
				break;
			default: printf("Nilai diluar jangkauan.\n");	//apabila input tidak berada dalam range 1-2
					 system("pause");
					 mainmenu();
					 break;
		}	
	} else {												//error handling untuk input berupa karakter
		printf("Masukan hanya angka.\n");
		getchar();
		system("pause");
		mainmenu();
	}
}

void help(){				//menu untuk menampilkan cara menggunakan program
	system("cls");
	header();
	printf("\nBagaimana cara berbelanja di toko pintar?\n");
	printf("\n1. Masuk ke menu utama.");
	printf("\n2. Pilih menu. Untuk mencari barang masukkan angka 1.");
	printf("\n3. Ketik nama barang yang ingin dicari. Masukkan -1 untuk kembali ke menu utama.");
	printf("\n4. Pilih menu tambah ke keranjang untuk memasukkan barang yang ada di pencarian ke keranjang.");
	printf("\n5. Masukkan nomor barang. Nomor barang tertera di paling kiri tabel pencarian barang.");
	printf("\n6. Masukkan jumlah barang yang ingin dibeli. Jumlah barang yang dibeli tidak bisa melebihi stok yang ada.");
	printf("\n7. Jika sudah selesai berbelanja, pilih menu checkout. Kemudian akan muncul struk pembelian");
	printf("\n8. Tunjukkan struk pada kasir di TOKO PINTAR untuk mengambil barang pesanan.\n\n");
	system("pause");
	mainmenu();
}

void keluar(){			//menu untuk keluar dari program utama
	system("cls");
	header();
	printf("\nTerima kasih sudah menggunakan aplikasi TOKO PINTAR.");
	printf("\n\nCreated by Group 11 ");
	printf("\nPramudita Bintang & Raihan M. Syahran\n\n");
	system("pause");
	exit(0);
}

