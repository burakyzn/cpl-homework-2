/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* Rastgele.h Rastgele icin baslik dosyasidir.
* </p>
*/

#ifndef RASTGELE_H
#define RASTGELE_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

struct RASTGELE {
	int ustLimit; // rastgele uretilecek sayilarin ust limitini tutacagimiz alan
	int (*sayiUret)(struct RASTGELE*); // _rastgeleSayiUret fonksiyonu icin fonksiyon gosterici
	void (*yoket)(struct RASTGELE*); // _rastgeleYokEt fonksiyonu icin fonksiyon gosterici
};

typedef struct RASTGELE* Rastgele; // KisiKontrol icin tip tanimlamasi

Rastgele rastgeleOlustur(int); // rastgele yapisindan hafizada alan olusturup bunu donduren fonksiyon
int _rastgeleSayiUret(Rastgele); // rastgele sayi uretip bunu dondurecek olan fonksiyon
void _rastgeleYokEt(Rastgele); // hafizadan ayrilan alani geri birakmaya yarayan fonksiyon

#endif
