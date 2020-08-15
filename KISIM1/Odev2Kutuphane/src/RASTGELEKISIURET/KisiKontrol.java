/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RASTGELEKISIURET;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author Burak
 */
public class KisiKontrol {
    /*
     * Olusturulan kisilerin kontrolu icin yazilmis fonksiyon
     */
    public static void kontrolBaslat(){
        try{
            // kisiler.txt dosyasi okuma icin tanimlaniyor.
            Scanner fileIn = new Scanner(new File("Kisiler.txt"));
            
            String satir = ""; // okunan satitlari tutmak icin olusturulmus degisken
            
            int kimlikGecerliSayisi = 0; // gecerli kimlik sayisinin tutalacagi degisken
            int kimlikGecersizSayisi = 0; // gecersiz kimlik sayisinin tutalacagi degisken
            int IMEIGecerliSayisi = 0; // gecerli IMEI sayisinin tutalacagi degisken
            int IMEIGecersizSayisi = 0; // gecersiz IMEI sayisinin tutalacagi degisken

            while(fileIn.hasNextLine()){ // eger bir sonraki satir varsa dongu devam ediyor
                satir = fileIn.nextLine(); // satir okunuyor ve satir degiskenine atiliyor
                
                // kimlik numarasi bosluklara bolunup ilk alan kimlik kontrolu icin gonderiliyor
                if(KimlikNo.kontrol(satir.split(" ")[0])){ 
                    kimlikGecerliSayisi++; // eger kimlik dogruysa gecerli sayisi arttiriliyor
                } else {
                    kimlikGecersizSayisi++; // eger kimlik yanlissa gecersiz sayisi arttiriliyor
                }
                
                // kimlik numarasi bosluklara bolunup son bolum aliniyor parantezlerden arindirildan sonra kontrol icin gonderiliyor
                if(IMEINo.kontrol(satir.split(" ")[5].substring(1, satir.split(" ")[5].length() - 1))){
                    IMEIGecerliSayisi++; // eger IMEI dogruysa gecersiz sayisi arttiriliyor
                } else {
                    IMEIGecersizSayisi++; // eger IMEI yanlissa gecersiz sayisi arttiriliyor
                }                
            }
            
            // bulunan degerleri yazdirmak icin fonksiyona yolluyorum
            kontrolCiktisiniYazdir(kimlikGecerliSayisi,kimlikGecersizSayisi,IMEIGecerliSayisi,IMEIGecersizSayisi);
                       
        }catch(FileNotFoundException e){
            // eger dosya okunamazsa hata mesaji iletiliyor
            System.out.println("Kisiler.txt dosyasi bulunamadi veya okunamiyor.");
        }
    }
    
    /*
     * Sonraki rastgele sayiyi verir
     * @param kimlikGecerli gecerli kimlik numarasi sayisi
     * @param kimlikGecersiz gecersiz kimlik numarasi sayisi
     * @param imeiGecerli gecerli IMEI numarasi sayisi
     * @param imeiGecersiz gecersiz IMEI numarasi sayisi
     */
    private static void kontrolCiktisiniYazdir(int kimlikGecerli, int kimlikGecersiz, int imeiGecerli, int imeiGecersiz){
        // alinan gecerli gecersiz sayilari ekrana yazdiriliyor.
        System.out.println("T.C Kimlik Kontrol");
        System.out.println(kimlikGecerli + " Geçerli");
        System.out.println(kimlikGecersiz + " Geçersiz");
        System.out.println("IMEI Kontrol");
        System.out.println(imeiGecerli + " Geçerli");
        System.out.println(imeiGecersiz + " Geçersiz");
    }
}
