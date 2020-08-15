/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* Telefon.h Telefon icin baslik dosyasidir.
* </p>
*/

#ifndef TELEFON_H
#define TELEFON_H
#define _CRT_SECURE_NO_WARNINGS
#include "Rastgele.h"
#include "IMEINo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TELEFON {
	char* numara; // telefon numarasini tutacak olan char pointer
	IMEINo IMEINumarasi; // IMEINo yapisindan uretilmis gostericiyi tutacak referans alani

	void (*numaraOlustur)(struct TELEFON*); // _telefonNoOlustur fonksiyonu icin fonksiyon gosterici
	void (*yoket)(struct TELEFON*); // _telefonYoket fonksiyonu icin fonksiyon gosterici
}; 
typedef struct TELEFON* Telefon; // Telefon icin tip tanimlamasi

Telefon telefonOlustur(); // Telefon yapisindan hafizada alan olusturup bunu donduren fonksiyon
void _telefonNoOlustur(const Telefon); // telefon numarasi olusturacak olan fonksiyon
void _telefonYoket(Telefon); // hafizadan ayrilan alani geri birakmaya yarayan fonksiyon
#endif