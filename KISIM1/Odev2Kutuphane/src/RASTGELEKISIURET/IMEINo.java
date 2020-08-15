/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* IMEINo sinifi IMEI numaralari olusturmaniza ve varolan IMEI numalarini kontrol etmenizi saglar.
* </p>
*/
package RASTGELEKISIURET;

public class IMEINo {
    private String IMEINo; // IMEI numarasini tutmak icin ozel bir string degiskeni tanimladim.
    
    /*
     * IMEINo sinifinin kurucu fonksiyonudur.
     */
    public IMEINo(){
        IMEINo = "";
        setIMEINo(); // nesne olusturuldugunda IMEI numarasi olusturuluyor.
    }
    
    /*
     * IMEI numarasini olusturan fonksiyon.
     */
    private void setIMEINo(){
        String random_imei = "";
 
        for(int i=0;i<14;i++){ // 14 adet rastgele rakam olusturulup string olarak birlestiriliyor.
            random_imei += Rastgele.sonraki(10);
        }
        
        int tek_toplam = 0; // tek siradaki rakamlarin toplamini tutacagim degisken.
        for(int i=0;i<random_imei.length();i+=2){ // tek siradaki rakamlarin tek_toplam degiskenine ekliyorum.
            tek_toplam += Character.getNumericValue(random_imei.charAt(i));
        }
        
        int cift_iki_kat_toplam = 0; // cift siradaki rakamlarin iki katinin toplamini tutacagim degisken.
        for(int i=1;i<random_imei.length();i+=2){
            // cift siradaki rakamlarin iki katini hesapliyorum.
            int hane_iki_kati = 2 * Character.getNumericValue(random_imei.charAt(i));
            
            // eger hesaplanan sayi cift haneli ise hanelerinin toplamini cift_iki_kat_toplama ekliyorum.
            if(hane_iki_kati > 9){
                cift_iki_kat_toplam += (hane_iki_kati - 10) + 1;
            } else { // eger hesaplanan sayi tek haneliyse direk cift_iki_kat_toplama ekliyorum.
                cift_iki_kat_toplam += hane_iki_kati;
            }
        }
        
        // bu matematiksel formul ile IMEI numarasinin son hanesini hesapliyorum.
        int sonHane = (10 - ((cift_iki_kat_toplam + tek_toplam) % 10));
        
        // eger son hane 10 ciktiysa bu 0 anlamina gelir bunu degistiriyorum.
        if(sonHane == 10) {
            sonHane = 0;
        }
        
        random_imei += sonHane; // son haneyide imei numarasina ekliyorum.
        IMEINo = random_imei; // sinifin IMEINo degiskenini guncelliyorum.
    }

    /*
     * disaridan IMEINo cagrilmak istendiginde kullanilacak fonksiyon
     */
    public String getIMEINo(){
        return IMEINo;
    }
    
    /*
     * uretilmis IMEI numaralarini kontrol etmemizi saglayan fonksiyon
     * @param _imeiNo kontrol edilecek imei numarasi
     */
    public static boolean kontrol(String _imeiNo){
        int tek_toplam = 0; // tek siradaki rakamlarin toplamini tutmak icin olusturulmus degisken.
        for(int i=0;i<_imeiNo.length() - 1;i+=2){ // IMEI numarasinda tek sirada olan rakamlari topluyoruz.
            tek_toplam += Character.getNumericValue(_imeiNo.charAt(i));
        }
        
        int cift_iki_kat_toplam = 0; // cift siradaki rakamlarin toplamini tutmak icin olusturulmus degisken.
        for(int i=1;i<_imeiNo.length() - 1;i+=2){ 
            // cift siradaki rakamlarin iki katini hesapliyorum.
            int hane_iki_kati = 2 * Character.getNumericValue(_imeiNo.charAt(i));
            
            // eger hesaplanan sayi cift haneli ise hanelerinin toplamini cift_iki_kat_toplama ekliyorum.
            if(hane_iki_kati > 9){
                cift_iki_kat_toplam += (hane_iki_kati - 10) + 1;
            } else { // eger hesaplanan sayi tek haneliyse direk cift_iki_kat_toplama ekliyorum.
                cift_iki_kat_toplam += hane_iki_kati;
            }
        }
        
        // bu matematiksel formul ile IMEI numarasinin son hanesini hesapliyorum.
        int sonHane = (10 - ((cift_iki_kat_toplam + tek_toplam) % 10));
        
        // eger son hane 10 ciktiysa bu 0 anlamina gelir bunu degistiriyorum.
        if(sonHane == 10) {
            sonHane = 0;
        }
        
        // eger hesaplanan son hane ile kontrol edilen IMEI numarasinin son hanesi esit degilse false donduruyorum.
        if(sonHane != Character.getNumericValue(_imeiNo.charAt(_imeiNo.length() - 1))){
            return false;
        }
        
        // eger program bu adima kadar geldiyse IMEI numarasi dogrudur anlaminda true donduruyorum. 
        return true;
    }
}
