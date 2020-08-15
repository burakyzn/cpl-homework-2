/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* RastgeleKisi.c RastgeleKisi baslik dosyasinin gerceklendigi kaynak dosyasidir.
* </p>
*/

#include "RastgeleKisi.h"

// RastgeleKisi yapisindan hafizada alan olusturup bunu donduren fonksiyon
RastgeleKisi rastgeleKisiOlustur(int _kisiSayisi) {
	RastgeleKisi this = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI)); // RastgeleKisi yapisi icin hafizada yer ayriliyor.
	this->kisiSayisi = _kisiSayisi; // kisi sayisi alanina disaridan aldigimiz kisi sayisini atiyoruz
	this->kisiOlusturmaBasarili = 0;
	
	this->kisileriDisariAktar = &_kisileriDisariAktar; // kisileriDisariAktar fonksiyon gostericisine fonksiyonun adresi ataniyor.
	this->kisileriOlustur = &_kisileriOlustur; // kisileriOlustur fonksiyon gostericisine fonksiyonun adresi ataniyor.
	this->yoket = &_rastgeleKisileriYoket; // yoket fonksiyon gostericisine fonksiyonun adresi ataniyor.

	this->kisileriOlustur(this); // kisileri olusturmak icin fonksiyonu cagriyoruz
	return this; // yapi adresi donduruluyor
}

// kisi sayisi kadar kisileri olusturan fonksiyon
void _kisileriOlustur(RastgeleKisi _this) {
	int dosyaKontrol = 0; // programin duzgun calismasi icin dosya kontrolu yapacak degisken
	FILE* dosya; // dosya pointerimizi olusturuyoruz

	if(dosya = fopen("random_isimler.txt", "r")){ // dosya acilmaya calisiyor
		dosyaKontrol = 1; // dosya acilirsa dosyaKontrol 1 yapiliyor.
		fclose(dosya); 
	} else { // dosya acilamazsa dosya yok demektir ekrana hata donuluyor ve yeniden islem isteniyor.
		printf("random_isimler.txt dosyasi bulunamadi. \nProgram bu sekilde calisamaz. \n");
	}

	if(dosyaKontrol){
			// kisi listesi icin istenen kisi sayisi kadar hafizada yer ayiriyoruz
		_this->kisiListesi = (Kisi*)malloc(sizeof(Kisi) * _this->kisiSayisi);
	
		// hafizada ayirdigimiz alana kisileri dolduruyoruz
		for (int i = 0; i < _this->kisiSayisi; i++) {
			_this->kisiListesi[i] = KisiOlustur();
		}

		_this->kisiOlusturmaBasarili = 1;
		// olusturdugumuz kisileri txt dosyasi olarak disari aktarmak icin bu fonksiyonu cagriyoruz
		_kisileriDisariAktar(_this);
	}
}

// rastgele olusturulmus kisileri txt dosyasi olarak disari aktaran fonksiyon
void _kisileriDisariAktar(RastgeleKisi _this) {
	FILE* fp; // dosya icin bir pointer olusturuyoruz
	fp = fopen("Kisiler.txt", "w"); // Kisiler.txt dosyasini tanimliyoruz

	// kisi sayisi kadar kisilistesinde dolasip kisileri satir satir dosyaya yaziyoruz
	for (int i = 0; i < _this->kisiSayisi; i++) {
		fprintf(
				fp, 
				"%s %s %d %s (%s) \n", 
				_this->kisiListesi[i]->kimlikNo->numara,
				_this->kisiListesi[i]->isimSoyisim,
				_this->kisiListesi[i]->yas,
				_this->kisiListesi[i]->telefon->numara,
				_this->kisiListesi[i]->telefon->IMEINumarasi->numara
				);
	}

	fclose(fp); // dosyayi kapatiyoruz
}

// hafizadan ayrilan alani geri birakmaya yarayan fonksiyon
void _rastgeleKisileriYoket(RastgeleKisi this) {
	if (this != NULL) { // eger rastgelekisi icin ayrilan alan bos degilse bunu serbest birakicaz
		if(this->kisiOlusturmaBasarili){
			for (int i = 0; i < this->kisiSayisi; i++) { // kisi listesi icindeki tum kisilere ait alanlari serbest birakiyoruz
			this->kisiListesi[i]->yoket(this->kisiListesi[i]);
		}
		}
		free(this); // rastgelekisi icin ayrilan alani serbest birakiyoruz
		this = NULL;
	}
}
