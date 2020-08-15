/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* KimlikNo sinifi kimlik numaralari olusturmaniza ve varolan kimlik numalarini kontrol etmenizi saglar.
* </p>
*/
package RASTGELEKISIURET;

public class KimlikNo {
    private String kimlikNo; // kimlik numarasini tutmak icin ozel bir string degiskeni tanimladim.
    
    /*
     * KimlikNo sinifi icin kurucu fonksiyon
     */
    public KimlikNo(){
        kimlikNo = "";
        setKimlikNo(); // nesne olusturuldugunda kimlik numarasi olusturuluyor.
    }
    
    /*
     * Kurallara uygun olarak kimlik numarasi uretmek icin kullanilan fonksiyondur.
     */
    public void setKimlikNo(){
        int[] kimlikNoArr = new int[11]; // kimlik numalari 11 haneli oldugu icin 11 haneli bir integer dizisi olusturuyorum.
        
        for(int i=0;i<9;i++){ // kimlik numarasinin ilk 9 hanesi icin rastgele rakamlar atiyorum.
            kimlikNoArr[i] = Rastgele.sonraki(10);
        }
        
        // kimlik numalarinin ilk numarasi 0 olamaz
        while(kimlikNoArr[0] == 0){ // kimlik numarasi 0 olmayana kadar tekrar atama yapiyorum.
            kimlikNoArr[0] = Rastgele.sonraki(10);
        }
        
        int cift_basamak = 0; // cift basamaktaki rakamlarin toplamini tutmak icin olusturulan degisken. 
        int tek_basamak = 0; // tek basamaktaki rakamlarin toplamini tutmak icin olusturulan degisken.
        int tum_basamaklar = 0; // tum basamaklardaki rakamlarin toplamini tutmak icin olusturulan degisken
        for(int i=0;i<9;i++){ // ilk 9 hanesi icin islem yapiyoruz.
            if(((i+1)%2) == 0){ // cift hanelerdeki rakamlari cift_basamak degiskeninde topluyoruz.
                cift_basamak += kimlikNoArr[i]; 
            } else { // tek hanelerdeki rakamlari tek_basamak degiskeninde topluyoruz.
                tek_basamak += kimlikNoArr[i]; 
            }
            tum_basamaklar += kimlikNoArr[i]; // butun rakamlarida tum_basamaklar degiskeninde topluyoruz.
        }
        
        // kimlik numarasinin 10. hanesini matematiksel formul ile hesapliyoruz.
        kimlikNoArr[9] = (((tek_basamak) * 7) - (cift_basamak) ) % 10; 
        // hesaplanan 10.haneyide tum_basamaklar degiskenine ekliyoruz.
        tum_basamaklar += kimlikNoArr[9];
        // kimlik numarasinin son hanesini tum basamaklara uygulanan matematiksel islem ile buluyoruz.
        kimlikNoArr[10] = tum_basamaklar % 10;
        
        for(int i=0;i<11;i++){ // dizideki haneleri string olarak birlestiriyoruz.
            kimlikNo += kimlikNoArr[i];
        }
    }
    
    /*
     * disaridan KimlikNo cagrilmak istendiginde kullanilacak fonksiyon
     */
    public String getKimlikNo(){
        return kimlikNo;
    }
    
    /*
     * uretilmis kimlik numaralarini kontrol etmemizi saglayan fonksiyon
     * @param _kimlikNo kontrol edilecek kimlik numarasi
     */
    public static boolean kontrol(String _kimlikNo){
        // eger kimlik numarasinin ilk hanesi 0 ise diger islemleri yapmaya gerek olmadan
        // bu kimlik numarasinin yanlis oldugunu soyleyebiliriz bu yuzden false donduruyoruz.
        if(Character.getNumericValue(_kimlikNo.charAt(0)) == 0){
            return false;
        } 
                
        int cift_basamak = 0; // cift basamaktaki rakamlarin toplamini tutmak icin olusturulan degisken. 
        int tek_basamak = 0; // tek basamaktaki rakamlarin toplamini tutmak icin olusturulan degisken.
        int tum_basamaklar = 0; // tum basamaklardaki rakamlarin toplamini tutmak icin olusturulan degisken
        for(int i=0;i<9;i++){ // ilk 9 hanesi icin islem yapiyoruz.
            if(((i+1)%2) == 0){ // cift hanelerdeki rakamlari cift_basamak degiskeninde topluyoruz.
                cift_basamak += Character.getNumericValue(_kimlikNo.charAt(i)); 
            } else { // tek hanelerdeki rakamlari tek_basamak degiskeninde topluyoruz.
                tek_basamak += Character.getNumericValue(_kimlikNo.charAt(i)); 
            }
            tum_basamaklar += Character.getNumericValue(_kimlikNo.charAt(i)); // butun rakamlarida tum_basamaklar degiskeninde topluyoruz.
        }
                
        // kimlik numarasinin 10. hanesini matematiksel formul ile hesapliyoruz.
        int onBasamak = (((tek_basamak) * 7) - (cift_basamak) ) % 10; 
        // hesaplanan 10.haneyide tum_basamaklar degiskenine ekliyoruz.
        tum_basamaklar += onBasamak;
         // kimlik numarasinin son hanesini tum basamaklara uygulanan matematiksel islem ile buluyoruz.
        int sonBasamak = tum_basamaklar % 10;

        // eger kimlik numarasinin 10.hanesi bizim hesapladigimiz 10.haneye esit degilse kimlik numarasi yanlistir.
        if(Character.getNumericValue(_kimlikNo.charAt(9)) != onBasamak){
            return false;
        } else if(Character.getNumericValue(_kimlikNo.charAt(10)) != sonBasamak){
            // eger kimlik numarasinin son hanesi bizim hesapladigimiz son haneye esit degilse kimlik numarasi yanlistir.
            return false;
        }
        
        // eger program tum adimlari gecip buraya geldiyse o kimlik numarasi dogrudur bu yuzden true donduruyoruz
        return true;
    }
}
