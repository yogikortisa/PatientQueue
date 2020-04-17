#include<stdio.h>
#include<string.h>
#include<windows.h>
#define MAX 100

typedef struct {                //Deklarasi variabel yang dibutuhkan untuk data pasien
	char kartu[20];
	char nama[20];
	int jenis;
} data_pasien;

typedef data_pasien tipeItem;   //Buat tipe data baru dengan tipe data_pasien bernama tipeItem 

typedef struct {                //Buat tipe struktur untuk antrian
	tipeItem data[MAX];
	int count;
	int front;
	int rear;
} Queue;
Queue Q;
	data_pasien masukan;       //Buat tipe struktur baru bertipe data_pasien

void create(Queue *Q)          //Prosedur untuk membuat Queue baru
{
	(*Q).front = 0;
	(*Q).rear = -1;
	(*Q).count = 0;
}

int isEmpty(Queue Q)            //Cek apakah antrian kosong?
{
	return(Q.count == 0);
} 

int isFull(Queue Q)             //Cek apakah antrian  penuh?
{
	return(Q.count == MAX);
}

void enqueue(Queue *Q, tipeItem x)    //Prosedur untuk menambahkan pasien baru ke antrian
{
	if(isFull(*Q))
		printf("Antrian penuh, penambahan antrian gagal");
	else {
		(*Q).rear = ((*Q).rear + 1) % MAX;
		strcpy((*Q).data[(*Q).rear].kartu, x.kartu);
		strcpy((*Q).data[(*Q).rear].nama, x.nama);
		(*Q).data[(*Q).rear].jenis = x.jenis;
		(*Q).count = (*Q).count + 1;
	}
}

void dequeue(Queue *Q, tipeItem *out)        //Prosedur untuk memanggil pasien
{
	if(!isEmpty(*Q))
	{
		strcpy((*out).kartu, (*Q).data[(*Q).front].kartu);
		strcpy((*out).nama, (*Q).data[(*Q).front].nama);
		(*out).jenis = (*Q).data[(*Q).front].jenis;
		(*Q).front = ((*Q).front+1) % MAX;
		(*Q).count=(*Q).count-1;
		printf("\nNo. Antrian	: %d", (*Q).front);
		printf("\nNo. kartu Motor	: %s", masukan.kartu);
		printf("\nNama Pasien	: %s", masukan.nama);
    }
	else
		printf("Antrian kosong, pemanggilan gagal");
}

void cetak_antrian(Queue Q) //Prosedur untuk mencetak semua data pasien yang sedang mengantri
{
	int i;

		for(i=Q.front; i<=Q.rear; i++)                     // Untuk menangani Linear Queue
		{
			printf("\n------------------------\n");
			printf("No. Antrian    : %d\n", i+1);
			printf("No. Kartu      : %s \n",Q.data[i].kartu);
			printf("Nama           : %s \n",Q.data[i].nama);
			if (Q.data[i].jenis == 1){
					printf("Poli	  : Umum\n");
				}
				else{
				if (Q.data[i].jenis == 2)
				{
					printf("Poli	   : Gigi\n");
				}
				else 
					printf("Poli	: Anak\n");
				}			
		}
	
	
	
}

int main()
{
    /* Declaration */
      int i,j,k,menu,ket,jumlah, total, bayar, kembali;
      float diskon;
      char qty[3];
      char lagi;
      char data[5][3][100] = {{"1","","50000"},{"2","","25000"},
                              {"3","","18000"},{"4","","15000"},
                              {"0","",""}};
                              
      /*---------------------- Program Information -------------------------*/
	  system("color 0A");
	  system("cls");
	  printf("\n\n\n\n\n\n\n\n");
	  printf("\t\t+-----------------------------------------+\n"); Sleep(100);
	  printf("\t\t|\t   PROGRAM ANTRIAN PASIEN         |\n");      Sleep(100);
	  printf("\t\t+-----------------------------------------+\n"); Sleep(200);
	  printf("\n\n");
	  getch();
	  system("cls");
	  
      /*--------------- Copyright (c) Yogi Kortisa - 2014 ------------------*/
      
      /**** Ini Untuk Login ****/
      char username[20], password[20];
      system("cls");
      printf("\n\n");
      printf("\tLogin Sebagai Administrator\n");
      printf("\t+--------------------------+\n");
      printf("\tUsername : ");
      scanf("%s", &username);
      printf("\tPassword : ");
      scanf("%s", &password);
      printf("\t+--------------------------+\n");
      if (strcmp(username,"admin")==0 && strcmp(password,"1234")==0)
      {
      system("cls");
      system("color 1F");
      printf("\t\tLogin Succesfully\n");
      system("cls");
      printf("\t+-------------------------------------------+\n");
      printf("\t|\tSelamat Datang Administrator	    |\n");
      printf("\t+-------------------------------------------+\n");
      getch();
      system("cls");
      }
      /**** Login Selesai ****/
    
	int y;
	printf("SISTEM ANTRIAN - PUSKESMAS SEKUPANG\n");
	printf("[1] Tambah Antrian Pasien\n");
	printf("[2] Panggil Pasien\n");
	printf("[3] Tampil Daftar Antrian Pasien\n");
	printf("[4] Keluar Program\n");
	printf("\nPilihan Anda: ");
	scanf("%d", &y);
	create(&Q);
	while(y != 4)
	{
	switch(y)
	{
		case 1: printf("\nNo. Kartu	: ");
				scanf("%s", &masukan.kartu);
				printf("Nama Pasien	: ");
				scanf("%s", &masukan.nama);
				printf("Poli (1. Umum, 2. Gigi, 3. Anak): ");
				scanf("%d", &masukan.jenis);
				printf(">> Antrian baru telah tersimpan..");
				enqueue(&Q, masukan);
				break;
				
		case 2: dequeue(&Q, &masukan);
				
				break;
				
		case 3: if (Q.count == 0)
					printf("Antrian Kosong!!!");
				else {
				printf("\nAda %d pasien lagi di antrian", Q.count);
				cetak_antrian(Q);
			}
			 break;
		case 4: return 0;
				break;
		default: printf("Perintah tidak ditemukan!");
	}
	printf("\n\nPilihan Anda: ");
	scanf("%d", &y);
	}
}
