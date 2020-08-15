/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* Test RastgeleKısıUret kutuphanesini test etmek icin yazilmistir.
* </p>
*/
package odev2test;

import RASTGELEKISIURET.KisiKontrol;
import RASTGELEKISIURET.RastgeleKisi; // RASTGELEKISIURET kutuphanesinden RastgeleKisi sinifi dahil edildi.
import java.util.Scanner; // ek1randan giris almamiz icin scanner sinifi dahil edildi.

public class Odev2Test {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner ekran = new Scanner(System.in); // scannerdan nesne olusturuyorum.
        boolean devamEt = true; // devamEt degiskeni programin ana menusu icin olusturuldu.
        
        do{
            // menunun secenekleri ekrana yazdiriliyor.
            System.out.println("\n1- Rastgele Kişi Üret");
            System.out.println("2- Üretilmiş Dosya Kontrol Et");
            System.out.println("3- Cikis");
            System.out.print("Cevap : ");
            String istek = ekran.nextLine(); // kullanicidan giris aliniyor.
            
            // kullanicidan gelen istegi degerlendirmek icin switch case kullandim.
            switch (istek) {
                case "1": // eger kullanici 1 girerse rastgele kisi uretiyor.
                    int kisiSayisi; // kullanicidan alinacak kisi sayisini tutan degisken.
                    System.out.print("Kisi sayisi giriniz : ");
                    String istenenKisiSayisi = ekran.nextLine(); // kisi sayisi ekrandan aliniyor
                    try{
                        kisiSayisi = Integer.parseInt(istenenKisiSayisi); // girilen string integer degerine donusturuluyor.
                    } catch(NumberFormatException e){
                        // eger sayiya donusemeyen bir string ifade girerse burada hata vererek dogru girisi sagliyoruz.
                        System.out.println("Lütfen geçerli bir kişi sayisi girerek işlemi tekrar deneyiniz.");
                        continue;
                    }
                    RastgeleKisi k = new RastgeleKisi(Integer.parseInt(istenenKisiSayisi)); // kisi adeti kadar yeni kisi olusturmasi icin rastgelekisi sinifindan bir nesne uretiyoruz.
                    break;
                case "2":
                    // eger kullanici 2 girerse uretilen dosyalarin kontrolu yapılıyor.
                    // bu yuzden RastgeleKisi sinifinin static fonksiyonu olan kontrol cagriliyor.
                    KisiKontrol.kontrolBaslat();
                    break;
                case "3":
                    // eger kullanici 3 girerse programdan cikiliyor bunu saglamak icin devamEt degiskenine false atiliyor.
                    devamEt = false;
                    break;
                default:
                    // switch casedeki seceneklerden biri girilmediyse default olarak bu case calisiyor.
                    System.out.println("Geçerli bir cevap giriniz.");
                    break;
            }
        }while(devamEt); // kullanici 3 girmedigi surece devamEt degiskeni true olur ve dongu devam eder.
    }
    
}
