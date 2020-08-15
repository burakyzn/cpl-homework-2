/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* Rastgele.c Rastgele baslik dosyasinin gerceklendigi kaynak dosyasidir.
* </p>
*/


#include "Rastgele.h"

// Rastgele yapisindan hafizada alan olusturup bunu donduren fonksiyon
Rastgele rastgeleOlustur(int ustLimit) {
	Rastgele this = (Rastgele)malloc(sizeof(struct RASTGELE)); // Rastgele yapisi icin hafizada yer ayriliyor.

	this->ustLimit = ustLimit; // ustLimit fonksiyon gostericisine fonksiyonun adresi ataniyor.
	this->sayiUret = &_rastgeleSayiUret; // sayiUret fonksiyon gostericisine fonksiyonun adresi ataniyor.
	this->yoket = &_rastgeleYokEt; // yoket fonksiyon gostericisine fonksiyonun adresi ataniyor.
 
	return this; // yapi adresi donduruluyor
}

// rastgele sayi uretip bunu dondurecek olan fonksiyon
int _rastgeleSayiUret(Rastgele this) {
	static int baslangic, baslangicGereklimi = 1; // baslangic ve baslangic gerekli mi degiskenlerini static tanimliyoruz
	if (baslangicGereklimi) { // eger fonksiyon ilk kez cagriliyorsa baslangica zaman ataniyor
		baslangic = time(0); // zaman atandi
		baslangicGereklimi = 0; // baslangic gereklimi kapaniyor
	}

	baslangic = (baslangic * 32719 + 3) % 32749; // rastgelelik icin matematiksel hesaplama yapiliyor
	return abs((baslangic % this->ustLimit)); // ve istenen maksimum sayiya gore sayi geri donduruluyor
}

// hafizadan ayrilan alani geri birakmaya yarayan fonksiyon
void _rastgeleYokEt(Rastgele this) {
	if (this != NULL) { // eger rastgele icin ayrilan alan bos degilse bunu serbest birakicaz
		free(this); // rastgele icin ayrilan alani serbest birakiyoruz
		this = NULL;
	}
}