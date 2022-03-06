#ifndef keranjangheader
#define keranjangheader

#include <string.h>					//inisialisasi library string

extern barang listbarang[100];		//inisialisasi struk 
extern troli listkeranjang[100];	
char nuser[100];					//inisialisasi nama user

void hapuskeranjang();				//prototipe fungsi yang berada pada keranjang.h
void tambahkeranjang(int counter);

void hapuskeranjang(){		//fungsi untuk menghapus barang dari keranjang
	int input, i;
	system("cls");
	header();
	displaykeranjang();		//menampilkan keranjang yang ada pada saat ini
	printf("\n\nPilih barang yang ingin dihapus (tekan -1 untuk kembali): ");
	
	do{
		if(scanf("%d", &input)==1){
			if(input==-1){			//kembali ke menu keranjang jika user memasukkan -1
				keranjang();
			}
			if(input <= 0 || input > keranjanglen){				//error handling ketika user memasukkan angka yang tidak sesuai
		        printf("\nInput diluar jangkauan. silahkan coba lagi\n");
		        system("pause");
		        hapuskeranjang();
		    }	
		}
		else {													//error handling untuk input berupa karakter
			printf("Masukan hanya angka.\n");
			getchar();
			system("pause");
			hapuskeranjang();
		}
	}while(input <= 0 || input > keranjanglen);
	
	
    
    for(i = input-1; i < keranjanglen; i++){			//mekanisme penyesuaian list keranjang agar barang terhapus
    	if(i == keranjanglen-1){						//kondisi ketika index sekarang sudah merupakan barang terakhir dari list, barang akan dikosongkan
    		listkeranjang[i].index = NULL;
    		listkeranjang[i].harga = 0;
    		listkeranjang[i].jumlah = 0;
		} else {										//memindahkan list barang dalam indeks sekarang dengan indeks dibawahnya
			listkeranjang[i].index = listkeranjang[i+1].index;
    		listkeranjang[i].harga = listkeranjang[i+1].harga;
    		listkeranjang[i].jumlah = listkeranjang[i+1].jumlah;
		}
	}
	keranjanglen--;										//mengurangi banyaknya barang dalam keranjang
	system("cls");
	header();
	displaykeranjang();									//menampilkan keranjang saat ini
	printf("\n\nBarang berhasil dihapus.\n");			//konfirmasi barang berhasil dihapus
	system("pause");
	keranjang();										//kembali ke menu keranjang
}

void tambahkeranjang(int counter){												//fungsi untuk menambahkan barang ke list keranjang
    int pil, i, nkeranjang = -1, jumlah, ada;
    system("cls");
	header();
	printf("\n%-5s %-50s %-8s %-15s", "No.","Nama Barang","Stok", "Harga Satuan");
	printf("\n------------------------------------------------------------------------------");
	for (i = 0 ; i < counter; i++){												//menampilkan hasil pencarian
		printf("\n%-5d %-50s %-8d Rp.%-15d",i+1 ,listbarang[hasilcari[i]].namabarang,listbarang[hasilcari[i]].stok, listbarang[hasilcari[i]].harga);
	}
	printf("\n------------------------------------------------------------------------------");
    printf("\n\nSilahkan pilih barang yang ingin dimasukkan ke keranjang: ");	//meminta user untuk memilih barang
    
    if (counter == 0){															//error handling apabila tidak terdapat hasil pencarian
		printf("\n\n\nIsi pencarian tidak ditemukan!\nProgram akan kembali ke menu pencarian barang\n");
		system("pause");
		caribarang();
	}
	else{
		do{
	    	if(scanf("%d", &pil)==1){
		    	if(pil < 0 || pil > counter){										//error handling ketika input tidak sesuai
			        printf("\nInput diluar jangkauan. Silahkan coba lagi\n\n");
			        system("pause");
			        tambahkeranjang(counter);
			    }	
			}
			else {																	//error handling untuk input berupa karakter
				printf("Masukan hanya angka.\n");
				getchar();
				system("pause");
			}
		}while(pil < 0 || pil > counter);
    
	    for(i = 0; i < keranjanglen; i++){											//mekanisme ketika barang yang dipilih sudah ada di keranjang
	        if(listkeranjang[i].index == hasilcari[pil-1]){
	            nkeranjang = i;
	            listbarang[hasilcari[pil-1]].stok += listkeranjang[i].jumlah;
	            printf("Barang sudah ada di keranjang. Stok saat ini: %d\n", listbarang[hasilcari[pil-1]].stok);
	        }
	    }
	    
	    if(nkeranjang == -1){														//fungsi ketika barang belum ada di keranjang
	        nkeranjang = keranjanglen;
	        keranjanglen++;
	        listkeranjang[i].index = hasilcari[pil-1];
	    }
	    do{
	    	printf("Silahkan masukkan jumlah pesanan barang: ");					//meminta user untuk memasukkan jumlah pesanan
	    	do{
	    		if(scanf("%d", &jumlah)==1){
		    		if (jumlah > listbarang[listkeranjang[nkeranjang].index].stok || jumlah <= 0){		//error handling ketika user memasukkan nilai yang salah
			    		printf("\nJumlah barang melebihi stok / jumlah tidak sesuai. silahkan masukkan ulang.\n");
			    		system("pause");
			    		tambahkeranjang(counter);
			    		ada = 0;
					} 
					else {
						ada = 1;
					}	
				}
	    		else {																	//error handling untuk input berupa karakter
					printf("Masukan hanya angka.\n");
					getchar();
					system("pause");
				}
			}while(jumlah > listbarang[listkeranjang[nkeranjang].index].stok || jumlah <= 0);	
		}while(ada == 0);
    
	    listbarang[listkeranjang[nkeranjang].index].stok -= jumlah;		//pengurangan jumlah stok karena barang dimasukkan ke keranjang
	    listkeranjang[nkeranjang].jumlah = jumlah;						//jumlah barang di keranjang
	    listkeranjang[nkeranjang].harga = listbarang[listkeranjang[nkeranjang].index].harga * listkeranjang[nkeranjang].jumlah;		//harga total barang terpilih
	    
	    printf("\n%d pcs %s sukses ditambahkan ke keranjang.\n\n",listkeranjang[nkeranjang].jumlah, listbarang[listkeranjang[nkeranjang].index].namabarang);		//konfirmasi pemesanan barang
	    system("pause");
	    caribarang();
	}
}

#endif
