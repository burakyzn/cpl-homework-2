/**
*
* @author Burak Yazan - burak.yazan@ogr.sakarya.edu.tr
* @since  Nisan - 2020
* <p>
* Rastgele sinifi sifir ile verilen maksimum sayi arasinda sayi uretmenizi saglar.
* </p>
*/
package RASTGELEKISIURET;

public class Rastgele { 
    private static long baslangic = System.currentTimeMillis(); // sistem zamanini baslangic degiskeninde tutuyoruz
    
    /*
     * Sonraki rastgele sayiyi verir
     * @param maksimum sayi araligi icin maksimum sayi
     */
    public static int sonraki(int maksimum) {
        /* rastgele sayilar uretmek icin linear congruential generators algoritmasini kullaniyorum.
           burada sistem zamanini baslangic degiskeninde tutarak ve ustunde alttaki matematiksel islemi
           yaparak surekli farkli sayilar elde edebiliyoruz. bu farkli sayilarin istegimiz araligin maksimum
           sayisina gore modunu alırsak bize istedigimiz aralikta sayilar kaliyor.
           bu sayinin mutlak degerini alip int olarak geri donduruyoruz. 
        */
        baslangic = (baslangic * 32719 + 3) % 32749; 
	return (int)Math.abs((baslangic % maksimum));
    }
}
