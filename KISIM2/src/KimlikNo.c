/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* KimlikNo.c KimlikNo baslik dosyasinin gerceklendigi kaynak dosyasidir.
* </p>
*/

#include "KimlikNo.h"

// KimlikNo yapisindan hafizada alan olusturup bunu donduren fonksiyon
KimlikNo kimlikNoOlustur() {
	KimlikNo this = (KimlikNo)malloc(sizeof(struct KIMLIKNO)); // KimlikNo yapisi icin hafizada yer ayriliyor.
	
	this->numaraUret = &_kimlikNoUret; // numaraUret fonksiyon gostericisine fonksiyonun adresi ataniyor.
	this->yoket = &_kimlikNoYoket; // yoket fonksiyon gostericisine fonksiyonun adresi ataniyor.

	this->numaraUret(this); // kimlik numarasi olusturulmak icin fonksiyon cagriliyor
	return this; // yapi adresi donduruluyor
}

// kimlik no kurallarına gore kimlik numarasi olusturan fonksiyon
void _kimlikNoUret(KimlikNo _kimlikNo) {
	Rastgele rastgele = rastgeleOlustur(10); // rastgele sayi uretmek icin olusturuyoruz

	char** ptr = &_kimlikNo->numara;
	*ptr = (char*)malloc(sizeof(char) * 12); // kimlik numarasi alani icin yer ayriliyor

	char kimlikNo[12] = { '\0' }; // kimlik numarasi icin bir dizi olusturuyoruz

	// kimlik numaralarinin ilk hanesi 0 olamaz
	// bu yuzden ilk hane 0 olmayana kadar rastgele rakam atiyoruz
	sprintf(kimlikNo, "%d", rastgele->sayiUret(rastgele));
	while (kimlikNo[0] == '0') {
		sprintf(kimlikNo, "%d", rastgele->sayiUret(rastgele)); 
	}

	// ilk haneden sonra geri kalan 8 hane icin rastgele rakamlar atiyoruz
	for (int i = 1; i < 9; i++) {
		sprintf(kimlikNo + i, "%d", rastgele->sayiUret(rastgele)); 
	}

	int cift_basamak = 0; // cift siradaki rakamlarin toplamini tutmak icin degisken
	int tek_basamak = 0; // tek siradaki rakamlarin toplamini tutmak icin degisken 
	int tum_basamaklar = 0; // tum rakamlarin toplamini tutmak icin degisken 
	for (int i = 0; i < 9; i++) { // ilk 9 hane icin dizi uzerinde donuyoruz
		if (((i + 1) % 2) == 0) { // cift siradaki sayilar cift_basamak ta toplaniyor
			cift_basamak += (int)kimlikNo[i] - 48;
		}
		else { // tek siradaki sayilar tek_basamak ta toplaniyor
			tek_basamak += (int)kimlikNo[i] - 48;
		} // tum sayilar tum_basamak ta toplaniyor
		tum_basamaklar += (int)kimlikNo[i] - 48;
	}

	// kimlik numarasinin 10. hanesini matematiksel olarak hesapliyoruz ve diziye atiyoruz
	sprintf(kimlikNo + 9, "%d", ((((tek_basamak) * 7) - (cift_basamak)) % 10));
	// hesapladigimiz 10.haneyi de tum_basamaklar toplamina ekliyoruz
	tum_basamaklar += (int)kimlikNo[9] - 48;
	// kimlik numarasinin 11. hanesi de matematiksel olarak hesaplaniyor
	sprintf(kimlikNo + 10, "%d", (tum_basamaklar % 10));

	strcpy(*ptr, kimlikNo); // dizimizdeki elemanlari pointerin gosterdigi alana kopyaliyoruz
	rastgele->yoket(rastgele); // hafizadan aldigimiz alani geri birakiyoruz
}

// uretilen kimlik numalarini kontrol etmemizi saglayan fonksiyon
int kimlikKontrol(char* kimlikNo) {
	// eger kimlik numarasinin ilk hanesi 0 ise kontrol etmeye gerek yok kimlik numarasi yanlistir
	if (kimlikNo[0] == '0') {
		return 0;
	}

	int cift_basamak = 0; // cift siradaki rakamlarin toplamini tutmak icin degisken
	int tek_basamak = 0; // tek siradaki rakamlarin toplamini tutmak icin degisken 
	int tum_basamaklar = 0; // tum rakamlarin toplamini tutmak icin degisken 
	for (int i = 0; i < 9; i++) { // ilk 9 hane icin dizi uzerinde donuyoruz
		if (((i + 1) % 2) == 0) { // cift siradaki sayilar cift_basamak ta toplaniyor
			cift_basamak += (int)kimlikNo[i] - 48;
		}
		else { // tek siradaki sayilar tek_basamak ta toplaniyor
			tek_basamak += (int)kimlikNo[i] - 48;
		} // tum sayilar tum_basamak ta toplaniyor
		tum_basamaklar += (int)kimlikNo[i] - 48;
	}

	// kimlik numarasinin 10. hanesini matematiksel olarak hesapliyoruz ve diziye atiyoruz
	int onBasamak = ((((tek_basamak) * 7) - (cift_basamak)) % 10);
	// hesaplanan 10. haneyi de tum_basamaklar toplamina ekliyoruz
	tum_basamaklar += onBasamak;
	// kimlik numarasinin son hanesini hesapliyoruz
	int sonBasamak = tum_basamaklar % 10;

	// eger bizim hesapladigimiz 10. basamak ile kimlik numarasinin 10.basamagi ayni degilse kimlik no yanlistir
	if (kimlikNo[9] != onBasamak + 48) {
		return 0;
	} // eger bizim hesapladigimiz son basamak ile kimlik numarasinin 10. basamagi ayni degilse kimlik no yanlistir
	else if (kimlikNo[10] != sonBasamak + 48) {
		return 0;
	}

	// eger program buraya kadar geldiyse kimlik numarasi dogrudur bu yuzden 1 donduruyoruz
	return 1;
}

// hafizadan alinan alani geri birakmaya yarayan fonksiyon
void _kimlikNoYoket(KimlikNo this) {
	if (this != NULL) {  // eger kimlik no alani bos degilse bunu serbest birakicaz
		free(this->numara); // once kimlik alanina ait olan numara alanini serbest birakiyoruz.
		free(this); // kimlik no alani serbest birakiliyor.
		this = NULL;
	}
}