#ifndef _SATIS_OTOMASYON_
#define _SATIS_OTOMASYON_

//urun struct
struct product {
	
	int ID;
	char name[50];
	unsigned int type : 4;
	double price;	
	struct product *next;

};
typedef struct product node;

//Müsteri struct
struct customer {
	
	int ID;
	char name[50];
	unsigned int type: 1;
	double x_coord;
	double y_coord;
	struct customer *next1;

};
typedef struct customer node1;


struct purchased {

	int ID;
	int invoice_ID;
	int customer_ID;
	int product_ID;
	double cost;
	struct purchased *next2;

};
typedef struct purchased node2;

//FONKSÝYONLAR

void anaMenu();
void satisMenu();
void satisOnislem();
void urunSatis();
void musteriMenu();
void urunMenu();
void analizMenu() ;
void urunanalizMenu();
void yazdirMusteri(node1 **m);
void yazdirmusteriTipi(node1 **mt,int x);
void yazdirBirmusteri(node1 **b,int x);
void yazdirUrun(node **u);
void yazdirurunTipi(node **ut,int x);
void yazdirBirurun(node **bu,int x);
void birmusteriurunler(node **bmu,node1 **bmuu,node2 **bmuuu,int x) ;
void tummusteriToplam(node2 **t);
void kargoUcreti(node1 **ku);
void birmusteriToplam(node1 **bmt,node2 **bmtt,int x) ;
void yenimusteriGirisix(node1 **ymg,double x,double y);


#endif





