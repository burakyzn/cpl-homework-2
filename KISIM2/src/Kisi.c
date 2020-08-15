/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* Kisi.c Kisi baslik dosyasinin gerceklendigi kaynak dosyasidir.
* </p>
*/

#include "Kisi.h"
#include "Rastgele.h"
#include "Telefon.h"
#include "KimlikNo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Kisi yapisindan hafizada alan olusturup bunu donduren fonksiyon
Kisi KisiOlustur() {
	Kisi this = (Kisi)malloc(sizeof(struct KISI)); // Kisi yapisi icin hafizada yer ayriliyor.
	this->isimSoyisim = (char*)malloc(sizeof(char) * 20); 

	this->setIsimSoyisim = &_setIsimSoyisim; // setIsimSoyisim fonksiyon gostericisine fonksiyonun adresi ataniyor.
	this->setYas = &_setYas; // setYas fonksiyon gostericisine fonksiyonun adresi ataniyor.
	this->yoket = &_kisiYoket; // yoket fonksiyon gostericisine fonksiyonun adresi ataniyor.

	this->telefon = telefonOlustur(); // telefon olusturulmak icin fonksiyon cagriliyor
	this->kimlikNo = kimlikNoOlustur(); // kimlik olusturulmak icin fonksiyon cagriliyor
	this->yas = 0; // yas icin baslangic degeri ataniyor

	this->setIsimSoyisim(this); // isim soyisim ayarlanmak icin fonksiyonu cagriliyor
	this->setYas(this); // yas ayarlanmak icin fonksiyonu cagriliyor

	return this; // yapi adresi donduruluyor
}

// isimSoyisim alanini dolduracak olan fonksiyon
void _setIsimSoyisim(Kisi this) { 
	Rastgele rastgele = rastgeleOlustur(2999); // rastgele icin hafizada yer ayriliyor

	char** ptr = &this->isimSoyisim;
	*ptr = (char*)malloc(sizeof(char) * 26); // okunacak isim icin hafizada yer ayriliyor

	char kisi_isim_soyisim[26] = { '\0' }; // okunacak isim icin bir dizi olusturuluyor

	FILE* dosya; // dosyayı isaret edicek pointer yaratiliyor
	int satirUzunlugu = 25; //

	// burada dosya aciliyor ama dosya varligi kontrol edilmiyor.
	// cunku dosya varligi ve yoklugu daha once kontrol edildi.
	dosya = fopen("random_isimler.txt", "r"); 

	int istenenIsim = rastgele->sayiUret(rastgele) + 1; // istenen isim icin rastgele sayi belirleniyor dosyada 0.satir olmadigi icin +1 ekleniyor

	int satirSayaci = 0; // rastgele istenen isme gitmek icin olusturulan sayac
	while (satirSayaci != istenenIsim) { // rastgele istenen satira gelene kadar satir atlamak icin dongue giriliyor
		kisi_isim_soyisim[0] = '\0';
		fgets(kisi_isim_soyisim, satirUzunlugu, dosya); // satir okunup kisi_isim_soyisim dizisine aktariliyor
		satirSayaci++;
	}

	int karakterSayaci = 0; // isim uzerinde karakter saymak icin kullanilacak degisken
	for (int i = 0; i < 25; i++) { // isimler en fazla 25 karakter olabildigi icin 25 karakter donuyoruz
		if (kisi_isim_soyisim[i] == '\0') { // ismin bitisi yakalandigi zaman donguden cikilir
			break;
		}
		karakterSayaci++; // ismin sonuna gelmezsek sayac arttilir
	}

	kisi_isim_soyisim[karakterSayaci - 1] = '\0'; // ismin sonundaki satir atla isaretini silmek icin bir oncekine sonlandirma isareti koyuyoruz

	strcpy(*ptr, kisi_isim_soyisim); // isim soyisim icin ayirdigimiz alana kisi_isim_soyisim dizisini kopyaliyoruz
	fclose(dosya); // dosyayi kapatiyoruz
	rastgele->yoket(rastgele); // rastgele icin tuttugumuz alani serbest birakiyoruz
}

// yas alanini dolduracak olan fonksiyon
void _setYas(Kisi this) {
	Rastgele rastgele = rastgeleOlustur(99); // 0-100 arasi rastgele bir sayi ataniyor
	this->yas = rastgele->sayiUret(rastgele); // bu sayi kisinin yas alanina atiliyor
	rastgele->yoket(rastgele); // hafizadan rastgele icin ayrilan yer geri birakiliyor
}

// hafizadan ayrilan alani geri birakmaya yarayan fonksiyon
void _kisiYoket(Kisi this) {
	if (this != NULL) { // eger kisi icin ayrilan alan bos degilse bunu serbest birakicaz
		this->kimlikNo->yoket(this->kimlikNo); // kimlik noyu serbest birakiyoruz
		this->telefon->yoket(this->telefon); // telefonu serbest bırakiyoruz
		free(this); // kisi icin ayirdigimiz alani serbest birakiyoruz
		this = NULL;
	}
}
