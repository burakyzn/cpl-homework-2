/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* KisiKontrol.h KisiKontrol icin baslik dosyasidir.
* </p>
*/

#ifndef KISIKONTROL_H
#define KISIKONTROL_H
#define _CRT_SECURE_NO_WARNINGS

#include "Kisi.h"
#include "IMEINo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct KISIKONTROL {
	void (*kontroluBaslat)(struct KISIKONTROL*); // _kontroluBaslat fonksiyonu icin fonksiyon gosterici
	void (*yoket)(struct KISIKONTROL*); // _kisiKontrolYoket fonksiyonu icin fonksiyon gosterici
};

typedef struct KISIKONTROL* KisiKontrol; // KisiKontrol icin tip tanimlamasi

KisiKontrol kisiKontrolOlustur(); // KisiKontrol yapisindan hafizada alan olusturup bunu donduren fonksiyon
void _kontroluBaslat(KisiKontrol); // kisilerin kontrolunu baslatacak fonksiyon
void _kisiKontrolYoket(KisiKontrol); // hafizadan ayrilan alani geri birakmaya yarayan fonksiyon

#endif

