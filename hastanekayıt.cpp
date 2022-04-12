#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define SIZE 5

struct dugum {
	char ad[20];
	char soyad[20];
	int tc;
	char bolum[20];
	char doktorAd[20];
    struct dugum * next ;
};

struct kuyruk {
	int sayac = 0;
	struct dugum *rear;
	struct dugum *front;
};

typedef struct dugum node;
typedef struct kuyruk queue;

void baslangic(queue*q){
	q -> front = q -> rear = NULL;
	q ->sayac = 0;
}

bool doluMu(queue*q)
{
	return(q->sayac == SIZE);
}

bool bosMu(queue * q)
{
	return(q-> sayac == 0);
}

void hastaEkle(queue * q){
	if (doluMu(q))
	{
		printf("Korona virus nedeniyle günlük hasta kabul sayýsý sýnýra ulaþtý \n");
	}
	
	else 
	{
		node *hasta = (node*)malloc(sizeof(node));
		printf("Hastanede hasta kaydý için bekleyen hastalarýn bilgilerini giriniz : \n");
		printf("Ad: "); scanf("%s", &hasta -> ad );
		printf("Soyad: "); scanf("%s", &hasta -> soyad );
		printf("Tc: "); scanf("%d", &hasta -> tc );
	   	printf("Randevu alýnacak bölüm: "); scanf("%s", &hasta -> bolum );
	   	printf("Doktor Adý: "); scanf("%s", &hasta -> doktorAd );
	   	
	   	if ( bosMu(q))
	   	{
	   		hasta -> next == NULL;
	   		q-> rear = q-> front = hasta;
	   		printf(" Hasta kayýt iþlemi için sýraya ilk giren kiþi : %s \n" , q -> rear);
	   		q-> sayac++;
	   	}
	   	
	   	else
	   	{
	   		hasta -> next = q -> rear ;
	   		q -> rear = hasta;
	   		printf("%s Hasta kayýt iþlemi için sýraya girdi : \n" , q -> rear);
	   		q -> sayac++ ;
	    }
	}
}

void hastaSil(queue*q)
{
	if (bosMu(q))
	{
		printf("Hasta kayýt iþlemi için bekleyen hasta yok \n");
	}
	
	else
	{
		if(q-> sayac == 1)
		{
			printf("Hasta kayýt iþlemi için bekleyen son kiþi de kaydý tamamlanarak sýradan ayrýldý \n");
			free(q-> front);
			q-> front = q-> rear = NULL;
			q -> sayac--;
		}
		
		else
		{
			node * temp = q-> rear;
			while(temp -> next != q-> front)
			temp = temp-> next;
			
			printf("%s sýradan ayrýldý \n", q-> front );
			free(q-> front);
			q-> front = temp;
			q-> front -> next = NULL;
			q -> sayac--;
		}
	}
}
	
void bekleyenleriListele(queue*q)
{   system("cls");
	if (bosMu(q))
	{
		printf("Hasta kayýt iþlemi için bekleyen hasta yok \n");
	}
	
	else
	{
		node * temp2 = q-> rear;
		while(temp2!= NULL)
		{
			printf("%s %s Tc: %d  , Seçilen randevu : %s,  Seçilen doktor: %s \n",
			 temp2-> ad, temp2-> soyad,
			 temp2-> tc  , temp2->bolum, temp2-> doktorAd);
			temp2 = temp2 -> next;
		}
	}
}

void bekleyenHastaSayisi(queue * q)
{
	 
	if (bosMu(q))
	{
		printf("Hasta kayýt iþlemi için bekleyen hasta yok \n");
	}
	
	else
	{
			printf("Hasta kayýt iþlemleri için bekleyen hasta sayýsý : %d\n", q ->sayac);
	}
}

int main()
{
	setlocale (LC_ALL,"Turkish");
	int secim;
	queue q;
	baslangic(&q);
	while(1)
	{
		printf("Hasta Kayýt Sistemi \n");
		printf("1-- Hasta ekle \n");
		printf("2-- Hasta sil \n");
		printf("3-- Bilgileri listele\n");
		printf("4-- Bekleyenlerin sayýsý \n");
		printf("0-- Çýkýþ \n");
		printf("Yapýlacak Ýþlemi Seçiniz:");
		scanf("%d" , &secim);
		switch(secim)
		{
			case 1: hastaEkle(&q);
			break;
			case 2: hastaSil(&q);
			break;
			case 3: bekleyenleriListele(&q);
			break;
			case 4: bekleyenHastaSayisi(&q);
			break;
			case 0: exit(0);
			break;
			default: printf("Hatalý iþlem \n");
    	}
	}
	return 0;
} 

