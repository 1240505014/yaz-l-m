#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASTA 100

typedef struct {
    int id;
    char ad[50];
    int yas;
    char cinsiyet;
    int oncelik;  // 1: Kýrmýzý (Acil), 2: Sarý (Orta), 3: Yeþil (Normal)
    int receteNo;
} Hasta;

Hasta hastalar[MAX_HASTA];
int hastaSayisi = 0;

void hastaEkle() {
    if (hastaSayisi >= MAX_HASTA) {
        printf("Hasta kapasitesi doldu!\n");
        return;
    }

    Hasta yeniHasta;
    yeniHasta.id = hastaSayisi + 1;

    printf("Hasta Adý: ");
    scanf(" %[^\n]", yeniHasta.ad);
    printf("Yaþý: ");
    scanf("%d", &yeniHasta.yas);
    printf("Cinsiyeti (E/K): ");
    scanf(" %c", &yeniHasta.cinsiyet);
    printf("Öncelik (1: Kýrmýzý, 2: Sarý, 3: Yeþil): ");
    scanf("%d", &yeniHasta.oncelik);

    yeniHasta.receteNo = rand() % 9000 + 1000; // 1000 ile 9999 arasýnda reçete no üret

    hastalar[hastaSayisi++] = yeniHasta;
    printf("\nHasta baþarýyla eklendi! (Reçete No: %d)\n\n", yeniHasta.receteNo);
}

void hastaListele() {
    int i;
    if (hastaSayisi == 0) {
        printf("Kayýtlý hasta bulunmamaktadýr.\n");
        return;
    }

    printf("\n--- Hasta Listesi ---\n");
    printf("ID\tAd\t\tYaþ\tCinsiyet\tÖncelik\tReçete No\n");
    printf("----------------------------------------------------\n");

    for (i = 0; i < hastaSayisi; i++) {
        printf("%d\t%s\t\t%d\t%c\t\t%d\t%d\n",
               hastalar[i].id, hastalar[i].ad, hastalar[i].yas,
               hastalar[i].cinsiyet, hastalar[i].oncelik, hastalar[i].receteNo);
    }
    printf("\n");
}

void hastaSirala() {
    int i, j;
    if (hastaSayisi == 0) {
        printf("Sýralanacak hasta bulunmamaktadýr.\n");
        return;
    }

    // Öncelik sýrasýna göre Bubble Sort (1: Kýrmýzý > 2: Sarý > 3: Yeþil)
    for (i = 0; i < hastaSayisi - 1; i++) {
        for (j = 0; j < hastaSayisi - i - 1; j++) {
            if (hastalar[j].oncelik > hastalar[j + 1].oncelik) {
                Hasta temp = hastalar[j];
                hastalar[j] = hastalar[j + 1];
                hastalar[j + 1] = temp;
            }
        }
    }

    printf("Hastalar öncelik sýrasýna göre sýralandý.\n\n");
}

int main() {
    int secim;

    do {
        printf("Acil Servis Yönetim Sistemi\n");
        printf("1. Hasta Ekle\n");
        printf("2. Hasta Listesi Göster\n");
        printf("3. Hastalarý Öncelik Sýrasýna Göre Sýrala\n");
        printf("4. Çýkýþ\n");
        printf("Seçiminizi yapýn: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                hastaEkle();
                break;
            case 2:
                hastaListele();
                break;
            case 3:
                hastaSirala();
                break;
            case 4:
                printf("Çýkýþ yapýlýyor...\n");
                break;
            default:
                printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
        }
    } while (secim != 4);

    return 0;
}

