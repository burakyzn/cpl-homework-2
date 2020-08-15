/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* Telefon sinifi telefon olusturmanizi saglar icerisinde telefon numarası ve IMEI numarası bulunur
* </p>
*/
package RASTGELEKISIURET;

public class Telefon {
    private String telefonNo; // telefon numarasini tutmak icin olusturulan string degiskeni
    private IMEINo IMEINo; // IMEINo sinifindan olusturulacak nesnenin referansi olusturuluyor
    
    /*
     * Telefon sinifinin kurucu fonksiyonudur
     */
    public Telefon(){
        setTelefonNo(); // telefon numarasi olusturmak icin cagriliyor.
        IMEINo = new IMEINo(); // IMEINo referansina nesne olusturulup ataniyor.
    }
    
    /*
     * Telefon numarasini olusturan fonksiyon
     */
    public void setTelefonNo(){
        // turk gsm kodlari bir dizi seklinde tamamlaniyor
        String[] turkGSMKodlari = {"501","505","506","507","551","552","553","554","555","559", // turk telekom
            "530", "531", "532", "533", "534", "535", "536", "537", "538", "539", "561", // turkcell
        	"540", "541", "542", "543", "544", "545", "546", "547", "548", "549"}; // vodafone}
    
        telefonNo = "0"; // telefon numaralari 0 ile basladigindan ilk karaktere sifir ataniyor
        telefonNo += turkGSMKodlari[Rastgele.sonraki(turkGSMKodlari.length)]; // rastgele olarak bir gsm numarasi ataniyor.
        
        for(int i=0;i<7;i++){ // geri kalan 7 hane rastgele rakamlardan olusturuluyor
            telefonNo += (Rastgele.sonraki(10));
        }
    } 
    
    /*
     * disaridan IMEI numarasi cagrilmak istendiginde kullanilacak fonksiyon
     */
    public String getIMEINo(){
        return IMEINo.getIMEINo();
    }
    
    /*
     * disaridan telefon numarasi cagrilmak istendiginde kullanilacak fonksiyon
     */
    public String getTelefonNo(){
        return telefonNo;
    }
}
