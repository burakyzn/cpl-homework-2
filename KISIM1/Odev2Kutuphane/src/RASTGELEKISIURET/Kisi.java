/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* Kisi sinifi kisi olusturmanizi saglar. Kisilerin kimlik numarasi ismi yasi ve telefonu bulunur.
* </p>
*/
package RASTGELEKISIURET;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Kisi {
    private KimlikNo kimlikNo; // kisinin kimlik numarasini tutmak icin kimlikNo sinifindan bir nesne referansi tutuluyor.
    private String isimSoyisim; // kisinin ismini ve soyismini tutmak icin string bir alan tutuluyor.
    private int yas; // kisinin yasini tutmak icin int bir alan tutuluyor.
    private Telefon telefon; // kisinin telefonunu tutmak icin Telefon sinifindan bir nesne referansi tutuluyor
   
    /*
     * Kisi sinifinin kurucu fonksiyonudur.
     */
    public Kisi(){
        kimlikNo = new KimlikNo(); // kimlikNo alanina KimlikNo sinifindan nesne olusturulup ataniyor.
        telefon = new Telefon(); // telefon alanina Telefon sinifindan nesne olusturulup ataniyor.
        isimSoyisim = ""; // isim soyisim icin baslangic degeri atiliyor.
        yas = 0; // yas icin baslangic degeri atiliyor.
        
        setIsimSoyisim(); // isim soyisim ayarlanmak icin cagriliyor.
        setYas(); // yas ayarlanmak icin cagriliyor.
    }
    
    /*
     * Kisinin isim soyisim alanini olusturmak icin kullanilan fonksiyon
     */
    private void setIsimSoyisim(){
        try{
            Scanner fileIn = new Scanner(new File("random_isimler.txt")); // random_isimler dosyasi okunur
            int rastgele = Rastgele.sonraki(2999) + 1; // rastgeleden 0 ile 3000 arasi gelebilir ama 0 dosya sisteminde tanimli degildir.
            
            int i = 1; // kacinci satirda oldugumuzu tutmak icin kullandigimiz degisken
            while(rastgele != i && fileIn.hasNextLine()){ // satir sayisi rastgele satira esit olana kadar satir atlanir.
                fileIn.nextLine();
                i++;
            }
            
            isimSoyisim = fileIn.nextLine(); // rastgele satira gelindiginde isim nesnenin isim soyisim alanina kaydedilir.
            fileIn.close(); // dosya kapatilir.
        }catch(FileNotFoundException e){
            // eger okuma sirasinda hata firlatilirsa bu hata ekrana yazilir.
            System.out.println("dosya yolu yanlış veya isim sınırı aşıldı.");
            isimSoyisim = "";
        }

    }
    
    /*
     * Kisinin yasini olusturmak icin kullanilan fonksiyon
     */
    private void setYas(){
        yas = Rastgele.sonraki(100); // yas alanina 0-100 arasi rastgele sayi atanir
    }
    
    /*
     * Disaridan cagrilmak istenen kimlik numarasi icin kullanilir
     */
    public String getKimlikNo(){
        return kimlikNo.getKimlikNo();
    }
    
    /*
     * Disaridan cagrilmak istenen isim soyisim icin kullanilir
     */
    public String getIsımSoyisim(){
        return isimSoyisim;
    }
    
    /*
     * Disaridan cagrilmak icin yas icin kullanilir
     */
    public int getYas(){
        return yas;
    }
    
    /*
     * Disaridan cagrilmak istenen telefon numarasi icin kullanilir
     */
    public String getTelefonNo(){
        return telefon.getTelefonNo();
    }
    
    /*
     * Disaridan cagrilmak istenen IMEI numarasi icin kullanilir
     */
    public String getIMEINo(){
        return telefon.getIMEINo();
    }
}
