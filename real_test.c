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

typedef struct _userpass {
	char nama[100];
	char pass[100];
	struct _userpass *next;	
} userpass;


//userpass *head = NULL;
//head = (userpass *) malloc (sizeof(userpass));
//head -> next = NULL;
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
	page();					//menu untuk membuat akun dan login ke menu utama
	mainmenu();				//menu utama dari aplikasi
	return 0;
}
void signup(userpass *head){
	system("cls");
	header();
	userpass *current = head;
	char username[100];
	char pass[100];
	char conf[100], temp;
	int i;
	
	printf("\nMasukkan username dan password anda (Masukkan -1 pada username untuk kembali)\n");
	printf("Username: ");
	scanf("%s", &username);
	if(strcmp(username, "-1") == 0){
		page();
	}
	while (current -> next !=  NULL){
		if (strcmp(username, current -> nama) == 0){
			printf("Username sudah terdapat dalam database!\n");
			system("pause");
			signup(head);
		}
		current = current -> next;
	}
	printf("Password: ");
	while(1) {
        temp = getch(); // Inputs one single character of password without printing to terminal

            /* Evaluating the ASCII value of the current one single character of password */
            if(temp == ENTER || temp == TAB) {
                pass[i] = '\0';
                break;
            } else if(temp == BKSP) {
                if(i > 0) {
                    i--;
                    printf("\b \b"); // Backspace one character
                }
            } else {
                pass[i] = temp;
                printf("*");
                i++;
            }
        }
	printf("\nKonfirmasi password: ");
	i = 0;
	while(1) {
        temp = getch(); // Inputs one single character of password without printing to terminal

            /* Evaluating the ASCII value of the current one single character of password */
            if(temp == ENTER || temp == TAB) {
                conf[i] = '\0';
                break;
            } else if(temp == BKSP) {
                if(i > 0) {
                    i--;
                    printf("\b \b"); // Backspace one character
                }
            } else {
                conf[i] = temp;
                printf("*");
                i++;
            }
        }
	if(strcmp(pass, conf) != 0){
		printf("\nPassword tidak cocok. Silahkan masukkan ulang.\n");
		system("pause");
		signup(head);
	}
	current -> next = (userpass *) malloc (sizeof(userpass));
	current= current -> next;
	open("database.txt",username,pass);
	
	printf("\nUsername dan Password berhasil dimasukkan. Silahkan login ulang.\n\n");
	system("pause");
	page();
}

void login(userpass *head) {
    char username[100], pass[100], temp;
    int i;
	userpass *current = head;
	system("cls");
	header();
	printf("\nMasukkan username dan password anda (Masukkan -1 pada username untuk kembali)\n");
        /* Asks for user's username */
    printf("Username: ");
    scanf("%s", &username);
	if(strcmp(username, "-1") == 0){
		page();
	}
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
                    i--;
                    printf("\b \b"); // Backspace one character
                }
            } else {
                pass[i] = temp;
                printf("*");
                i++;
            }
        }
        while (current -> next !=  NULL){
			if (strcmp(current -> nama, username) == 0) {
				if (strcmp(current -> pass, pass) == 0) {
					printf("\n\nLogin Berhasil.\n");
					strcpy(nuser,strupr( current -> nama));
					system("pause");
					mainmenu();
					
				}
				else{
					printf("Password anda salah. Silahkan masukkan ulang.\n");
					system("pause");
					login(head);
				}
				
			}
			current = current -> next;    	
		} 
		if(current -> next == NULL) {
			printf("\nUsername tidak ditemukan.\n");
			system("pause");
			login(head);
		}     
}

void page(){
	userpass *head = NULL;
	head = (userpass *) malloc (sizeof(userpass));
	head -> next = NULL;
	read("database.txt",head);

	int input;
	system("cls");
	header();
	
	printf("\nSelamat datang di aplikasi Toko Pintar. Silahkan pilih menu di bawah: \n");
	printf("\n1. Sign Up\n2. Login\n3. Keluar\n=> ");
	if(scanf("%d", &input) == 1){									//pilihan menu
		switch(input){ 
			case 1: 
				signup(head); 
				break;
			case 2: 
				login(head); 
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

void mainmenu(){											//menu utama dari aplikasi
	int input;
	system("cls");
	header();
	int waktu;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	waktu = tm.tm_hour;					//mengambil jam saat ini dan menyimpan di variabel waktu
	printf("Selamat ");
	if(waktu < 11){						//sapaan kepada user sesuai waktu
		printf("pagi ");
	}else if(waktu >= 11 && waktu < 15){
		printf("siang ");
	} else if (waktu >= 15 && waktu <18){
		printf("sore ");
	} else {
		printf("malam ");
	}
	printf("%s, selamat datang di aplikasi Toko Pintar. Silahkan pilih menu di bawah: \n", nuser);
	printf("\n1. Cari Barang \n2. Cek Keranjang \n3. Checkout \n4. Bantuan \n5. Logout");
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
					printf("\nAnda yakin ingin logout?");
					printf("\n99. Ya \n2. Tidak \n=> ");		//untuk mencegah user tidak sengaja keluar program
					do{
						if(scanf("%d", &input)== 1){			
							if(input == 99){					//kondisi ketika input = 99 atau input != 99
								page();
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

void open(char *filename, char *username, char *pass){
	FILE *fPtr;
	fPtr = fopen(filename, "r") ;
	char yorno;
	int flag,i ;
	if ((fPtr) == NULL ){
		printf("\nFile belum ada, %s telah dibuat!\n", filename) ;
		fPtr = fopen("database.txt", "w+") ;
//		fclose(fPtr) ;
	} else { 
		for (yorno = getc(fPtr); yorno != EOF; yorno = getc(fPtr)){
		    if (yorno == '\n') 
            i++ ;
            fclose(fPtr) ;

			fPtr = fopen(filename, "a") ;
		}
	}

	fprintf(fPtr, "%s,%s,.\n", username, pass);
	fclose(fPtr) ;
}

void read(char *filename, userpass* head){
	FILE *fp = fopen(filename, "r");
	int i,a,max,remove;
    char *token,buf[100],comp[100]; 
    const char s[2] = ",";
	userpass *current = head;

    while(fgets(buf, sizeof buf, fp) != NULL){
    	token = strtok(buf, s);
            for(a=0;a<3;a++){
                printf("iterasi\n");
				if (a == 0){
                	strcpy(current -> nama, token);
                	token = strtok(NULL,s);
				}	
				else if (a == 1){   
                	strcpy(current -> pass, token);
                    token = strtok(NULL,s);
                }       
        	}
        current -> next = (userpass *) malloc (sizeof(userpass));
		current = current-> next;
		current -> next = NULL;		
	}
	fclose(fp);
	max = i;
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

