#ifndef randomize
#define randomize

int Random(int lower, int upper);			//prototipe fungsi yang berada pada randomize.h
int diskonfunc();

int Random(int lower, int upper){			//fungsi untuk menghasilkan bilangan bulat pada range tertentu
    int i;
    int num = (rand() % (upper - lower + 1)) + lower;     
    return num;								//Random number akan muncul dengan range lower-upper
}

int diskonfunc(){							//perhitungan diskon undian bagi pelanggan
    srand(time(0));
    int hasil= Random(1,10);				//perhitungan undian dari angka 1 - 10%
    return hasil;
}

#endif
