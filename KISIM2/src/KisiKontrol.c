/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* KisiKontrol.c KisiKontrol baslik dosyasinin gerceklendigi kaynak dosyasidir.
* </p>
*/


#include "KisiKontrol.h"

// KisiKontrol yapisindan hafizada alan olusturup bunu donduren fonksiyon
KisiKontrol kisiKontrolOlustur() {
	KisiKontrol this = (KisiKontrol)malloc(sizeof(struct KISIKONTROL));  // KisiKontrol yapisi icin hafizada yer ayriliyor.

	this->kontroluBaslat = &_kontroluBaslat; // kontroluBaslat fonksiyon gostericisine fonksiyonun adresi ataniyor.
	this->yoket = &_kisiKontrolYoket; // yoket fonksiyon gostericisine fonksiyonun adresi ataniyor.

	return this; // yapi adresi donduruluyor
}

// kisilerin kontrolunu baslatacak fonksiyon
void _kontroluBaslat(KisiKontrol this){
	FILE* dosya; // FILE pointeri olusturuluyor
	int karakterUzunlugu = 75; // dosyadan tek seferde okunacak satir uzunlugu
	char okunanSatir[75]; // okunan satirin atanacagi char dizisi olusturuluyor

	int kimlikGecerliSayisi = 0; // gecerli kimlik numarasi sayisinin tutulacagi degisken
	int kimlikGecersizSayisi = 0; // gecersiz kimlik numarasi sayisinin tutulacagi degisken
	int IMEIGecerliSayisi = 0; // gecerli IMEI numarasi sayisinin tutulacagi degisken
	int IMEIGecersizSayisi = 0; // gecersiz IMEI numarasi  sayisinin tutulacagi degisken

	char* kimlikNo = (char*)malloc(sizeof(char) * 12); // kimlik numarasi icin hafizada alan ayriliyor
	char* imeiNo = (char*)malloc(sizeof(char) * 16); // IMEI numarasi icin hafizada alan ayriliyor

	int sonSayac = 0; // IMEI numarasini yakalamak icin kullandigimiz sayac

	if(dosya = fopen("Kisiler.txt", "r")){ // kisiler.txt dosyasi aciliyor
		while (fgets(okunanSatir, karakterUzunlugu, dosya) != NULL) // satirlar bitene kadar bir dongu olusturuyoruz
		{
			sonSayac = 0; // IMEI yakalama sayaci sifirlaniyor 
			kimlikNo[0] = '\0'; // kimlik numarasi dizisi sifirlaniyor
			imeiNo[0] = '\0'; // IMEI numarasi dizisi sifirlaniyor

			for (int i = 0; i < 11; i++) { // okunan satirin ilk 11 hanesi kimlik numarasi dizisine ataniyor
				kimlikNo[i] = okunanSatir[i];
			}
	
			while (okunanSatir[sonSayac] != '(') { // okunan satirda parantez araniyor
				sonSayac++;
			}

			for (int i = 0; i < 15; i++) { // parantezden sonraki 15 hane IMEI numarasi dizisine kopyalaniyor
				imeiNo[i] = okunanSatir[i + sonSayac + 1];
			}

			if (kimlikKontrol(kimlikNo) == 0) { // kimlik numarasi kontrole gonderiliyor 0 gelirse yanlistir
				kimlikGecersizSayisi++; // kimlik numarasi yanlissa gecersiz sayisi arttiriliyor
			}
			else {
				kimlikGecerliSayisi++; // kimlik numarasi dogruysa gecerli sayisi arttiriliyor
			}

			if (IMEIKontrol(imeiNo) == 0) { // IMEI numarasi kontrole gonderiliyor 0 gelirse yanlistir
				IMEIGecersizSayisi++; // IMEI numarasi yanlissa gecersiz sayisi arttiriliyor
			}
			else {
				IMEIGecerliSayisi++; // IMEI numarasi dogruysa gecerli sayisi arttiriliyor
			}
		}

		// gecerli ve gecersiz sayilari ekrana yazdiriliyor
		printf("\nT.C Kimlik Kontrol");
		printf("\n%d Gecerli", kimlikGecerliSayisi);
		printf("\n%d Gecersiz\n", kimlikGecersizSayisi);
		printf("\nIMEI Kontrol");
		printf("\n%d Gecerli", IMEIGecerliSayisi);
		printf("\n%d Gecersiz\n", IMEIGecersizSayisi);
	} else { // eger kontrol edilecek Kisiler.txt dosyasi yoksa ekrana hata mesaji basiyor.
		printf("Kisiler.txt dosyasi bulunamadi. \n");
	}

	free(kimlikNo); // kimlik numaralari icin ayirdigimiz alani serbest birakiyoruz
	free(imeiNo); // IMEI numaralari icin ayirdigimiz alani serbest birakiyoruz
	fclose(dosya); // acilan dosya kapaniyor
}

// hafizadan ayrilan alani geri birakmaya yarayan fonksiyon
void _kisiKontrolYoket(KisiKontrol this) {
	if (this != NULL) { // eger KisiKontrol icin ayrilan alan bos degilse bunu serbest birakicaz
		free(this); // KisiKontrol icin ayirdigimiz alani serbest birakiyoruz
		this = NULL;
	}
}
