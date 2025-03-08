#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASTA 100

typedef struct {
    int id;
    char ad[50];
    int yas;
    char cinsiyet;
    int oncelik;  // 1: K�rm�z� (Acil), 2: Sar� (Orta), 3: Ye�il (Normal)
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

    printf("Hasta Ad�: ");
    scanf(" %[^\n]", yeniHasta.ad);
    printf("Ya��: ");
    scanf("%d", &yeniHasta.yas);
    printf("Cinsiyeti (E/K): ");
    scanf(" %c", &yeniHasta.cinsiyet);
    printf("�ncelik (1: K�rm�z�, 2: Sar�, 3: Ye�il): ");
    scanf("%d", &yeniHasta.oncelik);

    yeniHasta.receteNo = rand() % 9000 + 1000; // 1000 ile 9999 aras�nda re�ete no �ret

    hastalar[hastaSayisi++] = yeniHasta;
    printf("\nHasta ba�ar�yla eklendi! (Re�ete No: %d)\n\n", yeniHasta.receteNo);
}

void hastaListele() {
    int i;
    if (hastaSayisi == 0) {
        printf("Kay�tl� hasta bulunmamaktad�r.\n");
        return;
    }

    printf("\n--- Hasta Listesi ---\n");
    printf("ID\tAd\t\tYa�\tCinsiyet\t�ncelik\tRe�ete No\n");
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
        printf("S�ralanacak hasta bulunmamaktad�r.\n");
        return;
    }

    // �ncelik s�ras�na g�re Bubble Sort (1: K�rm�z� > 2: Sar� > 3: Ye�il)
    for (i = 0; i < hastaSayisi - 1; i++) {
        for (j = 0; j < hastaSayisi - i - 1; j++) {
            if (hastalar[j].oncelik > hastalar[j + 1].oncelik) {
                Hasta temp = hastalar[j];
                hastalar[j] = hastalar[j + 1];
                hastalar[j + 1] = temp;
            }
        }
    }

    printf("Hastalar �ncelik s�ras�na g�re s�raland�.\n\n");
}

int main() {
    int secim;

    do {
        printf("Acil Servis Y�netim Sistemi\n");
        printf("1. Hasta Ekle\n");
        printf("2. Hasta Listesi G�ster\n");
        printf("3. Hastalar� �ncelik S�ras�na G�re S�rala\n");
        printf("4. ��k��\n");
        printf("Se�iminizi yap�n: ");
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
                printf("��k�� yap�l�yor...\n");
                break;
            default:
                printf("Ge�ersiz se�im! L�tfen tekrar deneyin.\n");
        }
    } while (secim != 4);

    return 0;
}

