/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* KimlikNo.h KimlikNo icin baslik dosyasidir.
* </p>
*/

#ifndef KIMLIKNO_H
#define KIMLIKNO_H
#define _CRT_SECURE_NO_WARNINGS

#include "Telefon.h"
#include "Rastgele.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct KIMLIKNO {
	char* numara; // kimlik numarasini tutan pointer alan
	void (*numaraUret)(struct KIMLIKNO*); // _kimlikNoUret fonksiyonu icin fonksiyon gosterici
	void (*yoket)(struct KIMLIKNO*); // _kimlikNoYoket fonksiyonu icin fonksiyon gosterici
};
typedef struct KIMLIKNO* KimlikNo; // KIMLIKNO icin tip tanimlamasi

KimlikNo kimlikNoOlustur(); // KimlikNo yapisindan hafizada alan olusturup bunu donduren fonksiyon
void _kimlikNoUret(KimlikNo); // bilinen kurallara gore kimlik numarasi olusturan fonksiyon
int kimlikKontrol(char*); // uretilen kimlik numalarini kontrol etmemizi saglayan fonksiyon
void _kimlikNoYoket(KimlikNo); // hafizadan ayrilan alani geri birakmaya yarayan fonksiyon
#endif