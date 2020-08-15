/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* RsatgeleKisi.h RastgeleKisi icin baslik dosyasidir.
* </p>
*/

#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H
#define _CRT_SECURE_NO_WARNINGS

#include "Kisi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RASTGELEKISI {
	Kisi* kisiListesi; // kisi listesini tutmamizi saglayacak pointer
	int kisiSayisi; // kisi sayisini tutacak olan alan
	int kisiOlusturmaBasarili; // kisi olusturmalar basarili mi basarisiz mi tuttugumuz degisken

	void (*kisileriDisariAktar)(struct RASTGELEKISI*); // _kisileriDisariAktar fonksiyonu icin fonksiyon gosterici
	void (*kisileriOlustur)(struct RASTGELEKISI*); // _kisileriOlustur fonksiyonu icin fonksiyon gosterici
	void (*yoket)(struct RASTGELEKISI*); // _rastgeleKisileriYoket fonksiyonu icin fonksiyon gosterici
};

typedef struct RASTGELEKISI* RastgeleKisi; // RastgeleKisi icin tip tanimlamasi

RastgeleKisi rastgeleKisiOlustur(int); // RastgeleKisi yapisindan hafizada alan olusturup bunu donduren fonksiyon
void _kisileriDisariAktar(RastgeleKisi); // rastgele olusturulmus kisileri txt dosyasi olarak disari aktaran fonksiyon
void _kisileriOlustur(RastgeleKisi); // kisi sayisi kadar kisileri olusturan fonksiyon
void _rastgeleKisileriYoket(RastgeleKisi); // hafizadan ayrilan alani geri birakmaya yarayan fonksiyon
#endif