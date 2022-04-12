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
		printf("Korona virus nedeniyle g�nl�k hasta kabul say�s� s�n�ra ula�t� \n");
	}
	
	else 
	{
		node *hasta = (node*)malloc(sizeof(node));
		printf("Hastanede hasta kayd� i�in bekleyen hastalar�n bilgilerini giriniz : \n");
		printf("Ad: "); scanf("%s", &hasta -> ad );
		printf("Soyad: "); scanf("%s", &hasta -> soyad );
		printf("Tc: "); scanf("%d", &hasta -> tc );
	   	printf("Randevu al�nacak b�l�m: "); scanf("%s", &hasta -> bolum );
	   	printf("Doktor Ad�: "); scanf("%s", &hasta -> doktorAd );
	   	
	   	if ( bosMu(q))
	   	{
	   		hasta -> next == NULL;
	   		q-> rear = q-> front = hasta;
	   		printf(" Hasta kay�t i�lemi i�in s�raya ilk giren ki�i : %s \n" , q -> rear);
	   		q-> sayac++;
	   	}
	   	
	   	else
	   	{
	   		hasta -> next = q -> rear ;
	   		q -> rear = hasta;
	   		printf("%s Hasta kay�t i�lemi i�in s�raya girdi : \n" , q -> rear);
	   		q -> sayac++ ;
	    }
	}
}

void hastaSil(queue*q)
{
	if (bosMu(q))
	{
		printf("Hasta kay�t i�lemi i�in bekleyen hasta yok \n");
	}
	
	else
	{
		if(q-> sayac == 1)
		{
			printf("Hasta kay�t i�lemi i�in bekleyen son ki�i de kayd� tamamlanarak s�radan ayr�ld� \n");
			free(q-> front);
			q-> front = q-> rear = NULL;
			q -> sayac--;
		}
		
		else
		{
			node * temp = q-> rear;
			while(temp -> next != q-> front)
			temp = temp-> next;
			
			printf("%s s�radan ayr�ld� \n", q-> front );
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
		printf("Hasta kay�t i�lemi i�in bekleyen hasta yok \n");
	}
	
	else
	{
		node * temp2 = q-> rear;
		while(temp2!= NULL)
		{
			printf("%s %s Tc: %d  , Se�ilen randevu : %s,  Se�ilen doktor: %s \n",
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
		printf("Hasta kay�t i�lemi i�in bekleyen hasta yok \n");
	}
	
	else
	{
			printf("Hasta kay�t i�lemleri i�in bekleyen hasta say�s� : %d\n", q ->sayac);
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
		printf("Hasta Kay�t Sistemi \n");
		printf("1-- Hasta ekle \n");
		printf("2-- Hasta sil \n");
		printf("3-- Bilgileri listele\n");
		printf("4-- Bekleyenlerin say�s� \n");
		printf("0-- ��k�� \n");
		printf("Yap�lacak ��lemi Se�iniz:");
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
			default: printf("Hatal� i�lem \n");
    	}
	}
	return 0;
} 

