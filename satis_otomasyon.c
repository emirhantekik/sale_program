#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>//KARGO UCRETÝ HESAPLAMAK ÝCÝN
#include "satis_otomasyon.h"

void anaMenu() {
	printf("1.Satis\n");
	printf("2.Musteri Bilgisi\n") ;
	printf("3.Urun Bilgisi\n") ;
	printf("4.Musteri Analizleri\n") ;
	printf("5.Urun Analizleri\n") ;
}

void satisMenu() {
	
	printf("\n1.Satis\n\n") ;
	printf("\t1.1.Satis On Islem\n") ;
	printf("\t1.2.Urun Satis\n") ;
	printf("\t1.3.Satis Son Islem\n\n") ;
	
}

void satisOnislem() {
	printf("\n") ;
	printf("\t\t1.1.1.Son Fatura Bul\n") ;
	printf("\t\t1.1.2.Musteri Numarasi Bul\n") ;
	
}

void urunSatis(){
	printf("\n") ;
	printf("\t\t1.2.1.Urun No Bul\n") ;
	printf("\t\t1.2.2.Miktar Bilgisi Gir\n") ;	
	
	
}


//MUSTERÝ MENULERÝ//
void musteriMenu() {
	printf("2.Musteri Bilgisi\n-----------------\n") ;
	printf("\t2.1.Tum musteriler\n") ;
	printf("\t2.2.Musteri tipine gore\n") ;
	printf("\t2.3.Bir musteri\n") ;
	printf("\t2.4.Yeni musteri girisi\n") ;
	
	
}

//******************//


void urunMenu(){
	printf("3.Urun Bilgisi\n\n") ;
	printf("\t3.1.Tum urunler\n") ;
	printf("\t3.2.Urun tipi\n") ;
	printf("\t3.3.Bir urun\n");
	
}

void analizMenu() {
	
	printf("4.Musteri Analizleri\n\n") ;
	printf("\t4.1.Bir musterinin satin aldigi urunler\n");
	printf("\t4.2.Bir musterinin satin aldigi toplam tutar\n") ;
	printf("\t4.3.Tum musterinin satin aldigi urunlerin toplam tutari\n") ;
	printf("\t4.4.Musterinin kargo ucreti\n") ;
	
	
}

void urunanalizMenu() {
	
	printf("5.Urun Analizleri\n\n") ;
	printf("\t5.1.Bir urunun toplam satis tutari\n") ;
	printf("\t5.2.Bir urun tipinin toplam satis tutari\n") ;
	printf("\t5.3.Tum urunlerin toplam satis tutari\n") ;
	
	
}

void yazdirMusteri(node1 **m){
	
	node1 *temp1=*m;
	
	while(temp1!=NULL) {
		
		printf("%-5d %-15s %-15u %-6.2lf %-1.2lf\n",temp1->ID,temp1->name,temp1->type,temp1->x_coord,temp1->y_coord) ;
		temp1=temp1->next1;
	}
	
} 

void yazdirmusteriTipi(node1 **mt,int x) {
	
	node1 *temp=*mt;
	
	while(temp!=NULL) {
		
		if(temp->type==x) {
			
			printf("%-5d %-15s %-15u %-6.2lf %-1.2lf\n",temp->ID,temp->name,temp->type,temp->x_coord,temp->y_coord) ;
			
		}
		
		else if(temp->type==x){
			printf("%-5d %-15s %-15u %-6.2lf %-1.2lf\n",temp->ID,temp->name,temp->type,temp->x_coord,temp->y_coord) ;
		}
		
		temp=temp->next1;
	}
	
	
}

void yazdirBirmusteri(node1 **b,int x) {
	
	node1 *temp=*b;
	int i;
	i=0;
	
	while(temp!=NULL) {
		
		if(i==x-1){
		printf("%-5d %-15s %-15u %-6.2lf %-1.2lf\n",temp->ID,temp->name,temp->type,temp->x_coord,temp->y_coord) ;
	}
	
		temp=temp->next1;
		i++;
	}
	
	
}


void yazdirUrun(node **u){
	
	node *temp= *u;
	while(temp!=NULL) {
		
		printf("%-5d %-10s %-10u %-6.2lfTL\n",temp->ID,temp->name,temp->type,temp->price) ;
		temp=temp->next;
	}
	
	
} 

void yazdirurunTipi(node **ut,int x) {
	
	node *temp=*ut;
	
	while(temp!=NULL) {
		
		if(temp->type==x) {
			
			printf("%-5d %-10s %-15u %-6.2lfTL\n",temp->ID,temp->name,temp->type,temp->price) ;
			
		}
		
		else if(temp->type==x){
			printf("%-5d %-10s %-15u %-6.2lfTL\n",temp->ID,temp->name,temp->type,temp->price) ;
		}
		
		temp=temp->next;
	}
	
	
}

void yazdirBirurun(node **bu,int x) {
	
	node *temp=*bu;
	int i;
	i=0;
	
	while(temp!=NULL) {
		
		if(i==x-1){
		printf("%-5d %-10s %-15u %-6.2lfTL\n",temp->ID,temp->name,temp->type,temp->price) ;
	}
	
		temp=temp->next;
		i++;
	}
	
	
}

void birmusteriurunler(node **bmu,node1 **bmuu,node2 **bmuuu,int x) {
	
	node *temp=*bmu ;//urun
	node1 *temp1=*bmuu;//musteri
	node2 *temp2=*bmuuu;//fatura
	
	int i=0;
	int musteriID;
	int faturaurunID;
	
	while(temp1!=NULL){//Müþteri listesi
		
		if(i==x-1){ //Ekran çýktýsýnda kullanýcýnýn seçtiði müþteriyi bulmak için
			
			printf("%s aldigi urunler :\n",temp1->name) ;
			musteriID=temp1->ID;
			
			while (temp2!=NULL) {//fatura listesi
				
				if(temp2->customer_ID==musteriID) { // Eðer fatura listesindeki müþteri ID'si ile kullanýcýc seçtiði müþteri ID eþleþirse
					
					faturaurunID=temp2->product_ID;
					
					while(temp!=NULL){//Urun listesi
						
						if(faturaurunID==temp->ID){//eðer fatura listesinde eþleþmiþ olan müþteri için faturadaki urun ID'si ile ürünün ID eþitse 
							
							printf("%s\n",temp->name) ;//ürünün adýný bastýrýr
							
						}
						temp=temp->next;
					}//ucuncu while sonu
					
				}//ikinci if sonu
				
				
				temp2=temp2->next2;
			}//ikinci while sonu
				
		}//ilk if sonu
		
		
		temp1=temp1->next1;
		i++;
	}//ilk while sonu
	
}

void tummusteriToplam(node2 **t) {
	
	node2 *temp=*t;
	double toplam;
	toplam=0;
	
	while(temp!=NULL) {
		
		toplam=toplam+temp->cost;		
		temp=temp->next2;
	}
	
	printf("Musterilerin aldigi urunlerin toplam tutari : %.2lfTL",toplam) ;
}

void kargoUcreti(node1 **ku){
	
	node1 *temp=*ku;
	double sayi;
	
	while(temp!=NULL) {
		
		printf("%s musterinin kargo ucreti :",temp->name);
		sayi=sqrt(pow(temp->x_coord,2)+pow(temp->y_coord,2));
		printf("%.2lfTL\n",sayi) ;
		temp=temp->next1;	
	}
 	
}

void birmusteriToplam(node1 **bmt,node2 **bmtt,int x) {
	
	node2 *temp2=*bmtt;
	node1 *temp1=*bmt;
	int i;
	i=0;
	
	double toplam;
	toplam=0;
	
	while(temp1!=NULL){
		
		if(i==x-1){
			
			printf("%s musterinin toplam alisveris ucreti :",temp1->name) ;
			
			while(temp2!=NULL){
				
				if(temp1->ID==temp2->customer_ID){
					
				toplam=toplam+temp2->cost;		
					
				}
				
				temp2=temp2->next2;
			}
			
		}
		
		
		temp1=temp1->next1;
		i++;
	}
	
	printf("%.2lfTL\n",toplam);
	
}

void yenimusteriGirisix(node1 **ymgx,double x,double y) {
	
	node1 *temp1=*ymgx;
	node1 *eklenecek =malloc(sizeof(node1)) ;
	
	eklenecek->x_coord=x;
	eklenecek->y_coord=y;
	eklenecek->next1=NULL;
	
	while(temp1->next1!=NULL) {
		
		
		temp1=temp1->next1;
		
	}
	
	temp1->next1=eklenecek ;
}


