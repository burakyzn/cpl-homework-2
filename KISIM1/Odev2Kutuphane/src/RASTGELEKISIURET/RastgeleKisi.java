/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* RastgeleKisi sinifi rastgele kisileri olusturur, siler, yonetir ve kisileri disari aktarir.
* </p>
*/
package RASTGELEKISIURET;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class RastgeleKisi {
    List<Kisi> kisiList; // Kisi listesini tutmak icin kullanilacak array listin referansi tanimlaniyor.
    
    /*
     * RastgeleKisi sinifinin kurucu fonksiyonudur
     * @param kisi_sayisi istenen kisi sayisini temsil eder
     */
    public RastgeleKisi(int kisi_sayisi){
        int dosyaVar = 0;
        // dosya varligi yoklugu kontrol ediyor dosya yoksa islemlere devam edilmeyecek
        try(Scanner fileIn = new Scanner(new File("random_isimler.txt"));){ 
            dosyaVar = 1;
            fileIn.close();
        }catch(FileNotFoundException e){
            // eger okuma sirasinda hata firlatilirsa bu hata ekrana yazilir.
            System.out.println("random_isimler.txt dosyasi yok veya okunamiyor.");
        }
        
        if(dosyaVar == 1){
            kisiList = new ArrayList<>(); // kisi listesine yeni arraylist olusturuluyor.
            // istenen kisi sayisi kadar kisi olusturulup kisi listesi arraylistine ekleniyor.
            for(int i=0;i<kisi_sayisi;i++){
                kisiList.add(new Kisi());
            }
        
            kisileriDısariAktar(); // olusturulan kisileri text olarak disari aktarmak icin cagriliyor.
        }
    }
        
    /*
     * Olusturulan kisileri txt dosyasi olarak disa aktarir
     */
    private void kisileriDısariAktar(){
        File file = new File("Kisiler.txt"); // Kisiler.txt isminde bir dosya olusturuyor
        try(BufferedWriter br = new BufferedWriter(new FileWriter(file))){
            for(int i=0;i<kisiList.size();i++){ // kisi listesindeki kisi kadar dongu donuyor.
                String kisi_bilgisi_satir = ""; // kisi bilgilerini birlestirmek icin olusturulan degisken
                
                // kisinin tum bilgileri kisi_bilgisi_satir degiskeninde toplaniyor.
                kisi_bilgisi_satir += kisiList.get(i).getKimlikNo() + " ";
                kisi_bilgisi_satir += kisiList.get(i).getIsımSoyisim() + " ";
                kisi_bilgisi_satir += kisiList.get(i).getYas() + " ";
                kisi_bilgisi_satir += kisiList.get(i).getTelefonNo() + " ";
                kisi_bilgisi_satir += "(" + kisiList.get(i).getIMEINo() + ")";
                
                br.write(kisi_bilgisi_satir); // Kisiler.txt dosyasina satir olarak yaziliyor.
                br.newLine(); // bir sonraki satira geciliyor.
            }
        } catch (IOException e) {
            // eger dosya okunamazsa ve hata firlatilirsa ekrana hata mesaji yazdiriliyor.
            System.out.println("Kisiler.txt dosyasina yazilamiyor ");
        }
    }
}
