#ifndef databaseheader
#define databaseheader

#include <string.h>						//inisialisasi library string

extern barang listbarang[100];			//array untuk menyimpan data barang di toko
extern troli listkeranjang[100];		//array untuk menyimpan data barang di keranjang
char nuser[100];						//nama user

void user();							//protipe fungsi yang berada dalam database.h
void addData(char* nama, int stok, int harga);
void database();

//void user(){							//menu yang menampilkan sapaan kepada user dan meminta input nama
//	int waktu;
//	time_t t = time(NULL);
//	struct tm tm = *localtime(&t);
//	waktu = tm.tm_hour;					//mengambil jam saat ini dan menyimpan di variabel waktu
//	header();
//	printf("Selamat ");
//	if(waktu < 11){						//sapaan kepada user sesuai waktu
//		printf("pagi");
//	}else if(waktu >= 11 && waktu < 15){
//		printf("siang");
//	} else if (waktu >= 15 && waktu <18){
//		printf("sore");
//	} else {
//		printf("malam");
//	}
//	printf(", siapa nama kamu? ");		//permintaan nama user
//	scanf("%[^\n]s",&nuser);
//	strcpy(nuser,strupr(nuser));
//}

void addData(char* nama, int stok, int harga){			//fungsi untuk menambahkan data secara otomatis
	strcpy(listbarang[baranglen].namabarang, nama);
	listbarang[baranglen].stok = stok;
	listbarang[baranglen].harga = harga;
	baranglen++;
}

void database(){										//data barang yang ada di toko
	addData("Shampo Lifebuoy 170ml", 20, 16600);
	addData("Shampo Lifebuoy 340ml", 24, 27500);
	addData("Shampo Zinc 170ml", 34, 18400);
	addData("Shampo Clear 300ml",25,37200);
	addData("Shampo Rejoice 170ml",25,37200);
	addData("Sabun Mandi Lifebuoy 450ml",26,26000);
	addData("Sabun Mandi Biore 800ml", 10, 38600);
	addData("Sabun Mandi Nuvo 250ml", 11, 12000);
	addData("Deterjen Bubuk Rinso 2kg", 14, 37600);
	addData("Deterjen Cair Rinso 1.8L", 15, 21600);
	addData("Sabun Cuci Piring Sunlight 755ml", 29, 14200);
	addData("Sabun Cuci Piring Sahaja 60ml", 56, 1000);
	addData("Pembersih Lantai Wipol 780ml", 25, 14300);
	addData("Pembersih Porselen Vixal 780ml",23,16200);
	addData("Pewangi Pakaian Molto 820ml",15,11900);
	addData("Pewangi Pakaian Kispray 300ml",46,5000);
	addData("Minyak Goreng Rose Brand 1L", 56, 18200);
	addData("Gula Gulaku Tebu 1kg", 39, 15700);
	addData("Wafer Nissin Chocolate 50 gr", 49, 3400);
	addData("Susu UHT Frisian Flag 225ml", 59, 5700);
	addData("Minyak Goreng Rose Brand 2L", 28, 34000);
	addData("Selai Goldenfil Choco Crunchy 1kg", 57, 48500);
	addData("Minyak Telon Konicare 30ml", 48, 15700);
	addData("Tisu Wajah Nice 60s", 52, 3900);
	addData("Indomie Goreng Jumbo 129gr", 562, 3700);
	addData("Mie Sedaap Soto 75gr", 585, 2600);
	addData("Chocolatos Wafer Coklat Box", 25, 12600);
	addData("Gulaku Pouch 300gr", 51,5500);
	addData("Rose Brand Tepung Tapioka 500gr", 235, 5300);
	addData("Biskuit Marie Susu 185gr", 52, 5600);
	addData("Garam Beryodium Cap Kapal 250gr", 234, 1700);
	addData("Roma Sari Gandum Biskuit 115gr", 23, 7600);
	addData("Tisu Wajah Paseo 50s", 63, 4500);
	addData("Nice Tisu Wajah 250s",26, 15900);
	addData("Indomie Goreng 85gr", 623, 2600);
	addData("Indomie Ayam Bawang 69gr", 463, 2600);
	addData("Minyak Goreng Sania 1L", 53, 16000);
	addData("Saori Saus Tiram 113ml", 25, 9200);
	addData("Royco Bumbu Kaldu Ayam 230gr", 35, 8600);
	addData("Bango Kecap Manis 210ml", 52, 10700);
	addData("Mawar Jaya Beras Sentra Ramos 1kg", 24, 13600);
	addData("Santan Kelapa Rose Brand 65ml", 47, 2800);
	addData("Sariwangi Teh Celup Hitam 50pc", 58, 8800);
	addData("Blue Band Margarin 200gr", 52, 8900);
	addData("Pepsodent White Pasta Gigi 225gr", 59, 12700);
	addData("Systema Sikat Gigi 3pcs", 47, 10100);
	addData("Ciptadent Sikat Gigi 3pcs", 79, 5600);
	addData("Close Up Pasta Gigi 160gr", 78, 16000);
	addData("Secret Clean Hand Sanitizer 100ml", 57, 11300);
	addData("Listerine Cool Mint 100ml", 67, 8800);
	addData("Cabe Rawit Merah 100gr", 400, 6650);
	addData("Kembang Kol 580gr", 50, 17110);
	addData("Brokoli 200gr", 50, 9220);
	addData("Bawang Putih 200gr", 20, 10600);
	addData("Bawang Merah 200gr", 20, 11000);
	addData("Bawang Bombay 210gr", 20, 13000);
	addData("Wortel 500gr", 30, 8900);
	addData("Bayam 1 Ikat 400-500gr",50,6200);
	addData("Terong Sayur 280gr", 100, 7810);
	addData("Paprika Hijau 200gr", 20,13750);
	addData("Jahe 250gr", 80, 10980);
	addData("Kentang 650gr", 50, 9690);
	addData("Daun Singkong 250gr",80,7000);
	addData("Buah Salak 1kg", 50, 20600);
	addData("Buah Pisang Mas 500gr", 50, 7900);
	addData("Buah Pisang Cavendish Baby 1 pack", 50, 13800);
	addData("Buah Lemon 1kg", 70, 19900);
	addData("Buah Mangga Harum Manis 1kg", 50, 15900);
	addData("Buah Pisang Raja Bulu 500gr", 50, 11000);
	addData("Buah Apel Merah Washington 500gr", 50, 21000);
	addData("Buah Kelengkeng 1kg", 50, 48000);
	addData("Buah Anggur Hitam 1kg", 40, 75680);
	addData("Buah Nanas", 30,10000);
	addData("Buah Kedondong 1kg", 20, 22000);
	addData("Buah Alpukat 500gr", 50, 20500);
	addData("Ikan Salmon 250gr", 20, 90000);
	addData("Ikan Salem 480-520gr", 30, 20200);
	addData("Ikan Bandeng 450-550gr", 50, 18400);
	addData("Ikan Dori Fillet 1kg", 50, 46000);
	addData("Ikan Bawal Hitam 450-550gr", 50, 36000);
	addData("Ikan Tuna Fillet 480-520gr", 40, 43500);
	addData("Ikan Kue Frozen 480-520gr", 40, 37000);
	addData("Daging Ayam 0.8kg", 50, 27500);
	addData("Daging Sapi Iga Rantai 1kg", 20, 105000);
	addData("Daging Sapi Rendang", 50, 46000);
	addData("Daging Kambing Segar 250gr", 50,40000);
	addData("Daging Kambing Muda 500gr", 50, 108900);
	addData("Telur Putuh 30pcs", 20, 23600);
	addData("Telur Ayam 10pcs", 30,30000);
	addData("Telur Ayam Kampung 10pcs", 30, 34000);
	addData("Telur Bebek Asin 6pcs", 20,22500);
	addData("Ultra Milk Susu UHT Full Cream 250gr", 50, 5000);
	addData("ULtra Milk Susu Cokelat 250ml", 100, 5200);
	addData("Ultra Milk Susu Stroberi 250ml", 100, 5200);
}

#endif
