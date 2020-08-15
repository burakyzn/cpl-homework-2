/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* Telefon.c Telefon baslik dosyasinin gerceklendigi kaynak dosyasidir.
* </p>
*/

#include "Telefon.h"

// Telefon yapisindan hafizada alan olusturup bunu donduren fonksiyon
Telefon telefonOlustur() {
	Telefon this = (Telefon)malloc(sizeof(struct TELEFON)); // Telefon yapisi icin hafizada yer ayriliyor.

	this->numaraOlustur = &_telefonNoOlustur; // numaraOlustur fonksiyon gostericisine fonksiyonun adresi ataniyor.
	this->yoket = &_telefonYoket; // yoket fonksiyon gostericisine fonksiyonun adresi ataniyor.

	this->numaraOlustur(this); // telefon numarasi olusturmak icin fonksiyonu cagriyoruz
	this->IMEINumarasi = IMEINoOlustur(); // IMEI olusturmak icin fonksiyon cagriliyor
	return this; // yapi adresi donduruluyor
}

// telefon numarasi olusturacak olan fonksiyon
void _telefonNoOlustur(const Telefon this) {
	Rastgele rastgele_operator = rastgeleOlustur(30); // operator atamasi icin rastgele olusturuyoruz
	Rastgele rastgele = rastgeleOlustur(10); // telefon numarasi atamasi icin rastgele olusturuyoruz

	char** ptr = &this->numara; 
	*ptr = (char*)malloc(sizeof(char) * 13); // telefon numarasi icin hafizada yer ayiriyoruz

	// turk gsm operator kodlari tanimlaniyor
	char telefonOperatorleri[31][5] = { "0501","0505","0506","0507","0551","0552","0553","0554","0555","0559",
			"0530", "0531", "0532", "0533", "0534", "0535", "0536", "0537", "0538", "0539", "0561",
			"0540", "0541", "0542", "0543", "0544", "0545", "0546", "0547", "0548", "0549" };

	
	char telefonNo[12] = { '\0' }; // telefon numarasi icin bir dizi olusturuluyor
	int randomOperator = rastgele_operator->sayiUret(rastgele); // operator secimi icin rastgele bir sayi ataniyor
	rastgele_operator->yoket(rastgele_operator); // operator icin olusturdugumuz rastgelenin kapladigi alani serbest birakiyoruz

	sprintf(telefonNo, telefonOperatorleri[randomOperator]); // operator kodunu telefon numarasi dizine aliyoruz
	for (int i = 0; i < 7; i++) { // geri kalan haneler icin rastgele sayi atiyoruz
		sprintf(telefonNo + i + 4, "%d", rastgele->sayiUret(rastgele)); 
	}

	strcpy(*ptr, telefonNo); // telefon numarasi icin ayirdigimiz alana dizidekileri kopyaliyoruz
	rastgele->yoket(rastgele); // rastgele icin ayirdigimiz alani serbest birakiyoruz
}

// hafizadan ayrilan alani geri birakmaya yarayan fonksiyon
void _telefonYoket(Telefon this) {
	if (this != NULL) { // eger telefon icin ayrilan alan bos degilse bunu serbest birakicaz
		this->IMEINumarasi->yoket(this->IMEINumarasi); // telefona ait olan imei numarasini yok ediyoruz
		free(this->numara); // telefon ait olan numarayi yok ediyoruz
		free(this); // telefonun varoldugu alani serbest birakiyoruz
		this = NULL; 
	}
}
