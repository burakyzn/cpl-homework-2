#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* Main.c sinifimizi test icin yazilmis ana kaynak dosyasidir.
* </p>
*/


#include <stdlib.h>
#include "RastgeleKisi.h"
#include "KisiKontrol.h"

#include "Rastgele.h"

int main() {
	char cevap[20]; // okunacak cevap icin 20 karakterli bir dizi olusturuyoruz
	int basarili_okuma = 0; // okumalardan geri donusleri tutmak icin degisken
	while (1) { // cikis istenen kadar dongunun donmesi icin surekli true 1 veriyoruz
		cevap[0] = '\0'; // cevap sifirlaniyor

		// ekrana menu yazdiriliyor
		printf("\n1 - Rastgele kisi uret\n");
		printf("2 - Uretilmis dosya kontrol et\n");
		printf("3 - Cikis\n");

		printf("Istenilen : ");
		basarili_okuma = scanf(" %s", cevap); // ekrandan girilen deger cevaba aktariliyor giris dogru ise basarili_okumaya 1 aktariliyor

		while (getchar() != '\n'); // ekrandaki giris arabellegini temizliyorum.

		if (basarili_okuma == 1 && cevap[1] == '\0') { // eger giris dogru ve cevap tek karakterli ise ic bloga giriliyor
			if (cevap[0] - 48 == 3) {  // eger cevap 3 ise cikis isteniyor program sonlandiriliyor
				printf("Cikis yapildi.");
				return 0;
			}
			else if (cevap[0] - 48 == 1) { // eger cevap 1 ise rastgele kisiler olusturmamiz isteniyor
				int kisi_sayisi = 0; // kisi sayisini tutacak olan degisken tanimlaniyor
				printf("Uretilecek kisi adetini girin : "); // ekrana aciklama yazdiriyoruz
				basarili_okuma = scanf("%d", &kisi_sayisi); // girilen deger kisi_sayisi degiskenine ataniyor

				while (getchar() != '\n'); // ekrandaki giris arabellegini temizliyorum.

				if (basarili_okuma == 1) { // eger kisi sayisi girisi basariliysa rastgele kisiler olusturuluyor
					RastgeleKisi r = rastgeleKisiOlustur(kisi_sayisi);
					r->yoket(r); // olusturulduktan sonra ayrilan tum hafiza geri iade ediliyor
				}
				else { // eger basarili okuma basarisizsa ekrana hata mesaji yazdiriliyor
					printf("\nGiris gecerli degil.");
				}
			}
			else if (cevap[0] - 48 == 2) { // eger cevap 2 ise kontrol baslatiliyor
				KisiKontrol kontrol = kisiKontrolOlustur(); // kontrol icin alan ayriliyor
				kontrol->kontroluBaslat(kontrol); // kontrol baslatiliyor 
				kontrol->yoket(kontrol); // kontrol icin ayirdigimiz alani serbest birakiyoruz
			}
			else { // eger cevap 1 2 3 den biri degilse ekrana farkli bir karakter girildigi icin hata mesaji bastiriliyor
				printf("\nSadece ekrandaki rakamlardan girilmelidir.");
			}
		}
		else { // eger cevap 1 2 3 den biri degilse ekrana farkli bir karakter girildigi icin hata mesaji bastiriliyor
			printf("\nSadece ekrandaki rakamlardan girilmelidir.");
		}
	}

	// program sonlandiriliyor
	return 0;
}