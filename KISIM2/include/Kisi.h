/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* Kisi.h Kisi icin baslik dosyasidir.
* </p>
*/

#ifndef KISI_H
#define KISI_H

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "Telefon.h"
#include "KimlikNo.h"
#include <string.h>

struct KISI {
	KimlikNo kimlikNo; // KimlikNo yapisindan uretilmis gostericiyi tutacak referans alani
	char* isimSoyisim; // isim soyisim bilgisini tutacak alan
	int yas; // yas bilgisini tutacak alan
	Telefon telefon; // Telefon yapisindan uretilmis gostericiyi tutacak referans alani

	void (*setIsimSoyisim)(struct KISI*); // _setIsimSoyisim fonksiyonu icin fonksiyon gosterici
	void (*setYas)(struct KISI*); // _setYas fonksiyonu icin fonksiyon gosterici
	void (*yoket)(struct KISI*); // _kisiYoket fonksiyonu icin fonksiyon gosterici
};
typedef struct KISI* Kisi; // KISI icin tip tanimlamasi

Kisi KisiOlustur(); // Kisi yapisindan hafizada alan olusturup bunu donduren fonksiyon
void _setIsimSoyisim(Kisi); // isimSoyisim alanini dolduracak olan fonksiyon
void _setYas(Kisi); // yas alanini dolduracak olan fonksiyon
void _kisiYoket(Kisi); // hafizadan ayrilan alani geri birakmaya yarayan fonksiyon

#endif