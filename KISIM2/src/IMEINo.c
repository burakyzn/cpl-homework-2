/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* IMEINo.c IMEINo baslik dosyasinin gerceklendigi kaynak dosyasidir.
* </p>
*/

#include "IMEINo.h"

// IMEINo yapisindan hafizada alan olusturup bunu donduren fonksiyon
IMEINo IMEINoOlustur() {
	IMEINo this = (IMEINo)malloc(sizeof(struct IMEINO)); // IMEINo yapisi icin hafizada yer ayriliyor.
	
	this->numaraOlustur = &_IMEINoUret; // numaraOlustur fonksiyon gostericisine fonksiyonun adresi ataniyor.
	this->yoket = &_IMEINoYoket; // yoket fonksiyon gostericisine fonksiyonun adresi ataniyor.

	this->numaraOlustur(this); // IMEI numarasi olusturulmak icin fonksiyon cagriliyor
	return this; // yapi adresi donduruluyor
}

// IMEI kurallarına gore IMEI numarasi olusturan fonksiyon
void _IMEINoUret(IMEINo _imeiNo) {
	Rastgele rastgele = rastgeleOlustur(10); // Rastgele yapisini olusturuyoruz
	
	char** ptr = &_imeiNo->numara;
	*ptr = (char*)malloc(sizeof(char) * 16); // yapi icerisindeki numara alani icin yer aciyoruz

	char imeiNo[16] = { '\0' }; // 16 lik bir char dizisi aciyoruz

	for (int i = 0; i < 14; i++) { // dizinin ilk 14 elemanina rastgele rakamlar atiyoruz
		sprintf(imeiNo + i, "%d", rastgele->sayiUret(rastgele)); 
	}

	int tek_toplam = 0; // tek siradaki rakamlarin toplamini tutmak icin degisken olusturduk
	for (int i = 0; i < 14; i += 2) { // dizide bulunan tek hanedeki sayilari topluyoruz
		tek_toplam += (int)imeiNo[i] - 48; // burada -48 almamizin sebebi rakamlarin ascii de 48den baslamasi
	}

	int cift_iki_kat_toplam = 0; // cift siradaki rakamlarin toplamni tutmak icin degisken olusturduk
	for (int i = 1; i < 14; i += 2) { // dizide bulunan cift siradaki sayilar uzerinde dolasiyoruz
		int hane_iki_kati = 2 * ((int)imeiNo[i] - 48); // cift siradaki sayilarin iki katini hesapliyoruz

		// eger hesaplanan iki katlarinda sayi 9 dan buyukse hane hane olarak topluyoruz ve toplama ekliyoruz
		if (hane_iki_kati > 9) {
			cift_iki_kat_toplam += (hane_iki_kati - 10) + 1;
		}
		else { // 9 dan kucukse direk toplama ekliyoruz
			cift_iki_kat_toplam += hane_iki_kati;
		}
	}

	// IMEI numarasinin matematiksel formulune uygun olarak son haneyi hesapliyoruz
	int sonHane = (10 - ((cift_iki_kat_toplam + tek_toplam) % 10));

	// eger son hane 10 olarak hesaplandiysa bu 0 anlamina geliyor bunu degistiriyoruz
	if (sonHane == 10) {
		sonHane = 0;
	}
	sprintf(imeiNo + 14, "%d", sonHane); // son haneyi diziye ekliyoruz
	strcpy(*ptr, imeiNo); // butun IMEI numarasini pointerimizin gosterdigi alana kopyaliyoruz
	rastgele->yoket(rastgele); // rastgele icin olusturdugumuz alani serbest birakiyoruz
}

// disaridan alinan IMEI numaralarini kontrol etmemize yarayan fonksiyon
int IMEIKontrol(char* imeiNo){

	int tek_toplam = 0; // tek siradaki rakamlarin toplamini tutmak icin degisken olusturduk
	for (int i = 0; i < 14; i += 2) { // dizide bulunan tek hanedeki sayilari topluyoruz
		tek_toplam += (int)imeiNo[i] - 48;
	}

	int cift_iki_kat_toplam = 0; // cift siradaki rakamlarin toplamni tutmak icin degisken olusturduk
	for (int i = 1; i < 14; i += 2) { // dizide bulunan cift siradaki sayilar uzerinde dolasiyoruz
		int hane_iki_kati = 2 * ((int)imeiNo[i] - 48); // cift siradaki sayilarin iki katini hesapliyoruz

		// eger hesaplanan iki katlarinda sayi 9 dan buyukse hane hane olarak topluyoruz ve toplama ekliyoruz
		if (hane_iki_kati > 9) {
			cift_iki_kat_toplam += (hane_iki_kati - 10) + 1;
		}
		else { // 9 dan kucukse direk toplama ekliyoruz
			cift_iki_kat_toplam += hane_iki_kati;
		}
	}

	// IMEI numarasinin matematiksel formulune uygun olarak son haneyi hesapliyoruz
	int sonHane = (10 - ((cift_iki_kat_toplam + tek_toplam) % 10));

	// eger son hane 10 olarak hesaplandiysa bu 0 anlamina geliyor bunu degistiriyoruz
	if (sonHane == 10) {
		sonHane = 0;
	}

	// eger bizim hesapladigimiz son hane bize kontrol icin verilen IMEI numarasinin son hanesiyle eslesmiyorsa IMEI numarasi yanlistir
	if (sonHane +48 != imeiNo[14]) {
		return 0;
	}

	// eger program buraya kadar geldiyse IMEI numarasi dogrudur bu yuzden true anlaminda 1 donduruyoruz
	return 1;
} 

// hafizadan alinan alani geri birakmaya yarayan fonksiyon
void _IMEINoYoket(IMEINo this) {
	if (this != NULL) { // eger IMEINo alani bos degilse bunu serbest birakicaz
		free(this->numara); // once IMEINo alanina ait olan numara alanini serbest birakiyoruz.
		free(this); // IMEINo alani serbest birakiliyor.
		this = NULL;
	}
}