/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* IMEINo.h IMEINo icin baslik dosyasidir.
* </p>
*/

#ifndef IMEINO_H
#define IMEINO_H
#define _CRT_SECURE_NO_WARNINGS

#include "Rastgele.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IMEINO {
	char* numara; // IMEI numarasini tuttugumuz pointer alan
	void (*numaraOlustur)(struct IMEINO*); // _IMEINoUret fonksiyonu icin fonksiyon gosterici
	void (*yoket)(struct IMEINO*); // _IMEINoYoket fonksiyonu icin fonksiyon gosterici
};
typedef struct IMEINO* IMEINo; // IMEINO icin tip tanimlamasi

IMEINo IMEINoOlustur(); // IMEINo yapisindan hafizada alan olusturup bunu donduren fonksiyon
void _IMEINoUret(IMEINo); // IMEI kurallarına gore IMEI numarasi olusturan fonksiyon
int IMEIKontrol(char*); // uretilen IMEI numalarini kontrol etmemizi saglayan fonksiyon
void _IMEINoYoket(IMEINo); // hafizadan ayrilan alani geri birakmaya yarayan fonksiyon
#endif