/*
Nama Program	:
Nama			: Bunga Azizha N
NPM				: 140810180017
Kelas			: B
Tanggal Buat	: 24 April 2019
Deskripsi		:
*/

#include<iostream>
using namespace std;

struct restoran{
	char namaMa[30];
	int jumlah;
	int harga;
	restoran* next;
};

typedef restoran* pointer;
typedef pointer List;

void createList(List& First){
    First = NULL;
    }

void createElmt (pointer& pBaru){
    pBaru = new restoran;
    cout<<"Nama Makanan	: "; cin.ignore(); cin.getline(pBaru->namaMa,30);
    cout<<"Jumlah		: "; cin>>pBaru->jumlah;
    cout<<"Harga		: "; cin>>pBaru->harga;
    pBaru->next=NULL;
}

void insertLast (List& First, pointer pBaru){
    pointer Last;
    if (First==NULL){
        First=pBaru;
    }
    else {
        Last=First;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}

void traversal (List First){
    pointer pBantu;
    pBantu=First;
    int counter=1, x;

    cout<<"No\t\tNama Makanan\t\tJumlah\t\tHarga Satuan"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    while(pBantu != NULL){
    	
			cout<<counter<<"\t\t"<<pBantu->namaMa<<"\t\t\t"<<pBantu->jumlah<<"\t\t\t"<<pBantu->harga<<endl;
        pBantu=pBantu->next;
        counter++;
    }
    cout<<"-----------------------------------------------------------------------------"<<endl;
}

void Sort(List First){
    int tukar, i;
    pointer pBantu;
    pointer last = NULL;

    if (First == NULL){
        return;
    }
    do{
        tukar = 0;
        pBantu = First;
        while (pBantu->next != last)
        {
            if (pBantu->jumlah > pBantu->next->jumlah)
            {
                swap(pBantu->jumlah, pBantu->next->jumlah);
                tukar = 1;
            }
            pBantu = pBantu->next;
        }
        last = pBantu;
    }
    while (tukar);
}

void update (List& First){
 pointer pBantu;
 pBantu = First;
 
 while(pBantu!=NULL){
        cout<<"Nama Makanan "<<pBantu->namaMa<<endl;
        cout<<"Jumlah Pesanan : "; cin>>pBantu->Jumlah;
        cout<<endl;
        pBantu=pBantu->next;
    } 
}

main(){
	pointer pBaru;
    List first;
    int x, pilihan;
    string pemesan;
    
    createList(first);
    while(1){
        system("cls");
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"\tMenu"<<endl;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"1. Pesan "<<endl;
        cout<<"2. Pesan Makanan "<<endl;
        cout<<"3. Munculkan Pesanan"<<endl;
        cout<<"4. Sort Jumlah"<<endl;
        cout<<"5. Update"<<endl;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout << "Masukan Pilihan : "; cin >> pilihan;
        cout<<endl;
        switch(pilihan){
        case 1:
            cout<<"Masukkan Nama Pemesan = ";cin>>pemesan;
        break;

        case 2:
        	cout<<"Banyak Pesanan : ";cin>>x;
	for(int i=0;i<x;i++){
		cout<<"Pesanan-"<<i+1<<endl;
            createElmt(pBaru);
            insertLast(first, pBaru);
        }
        break;

        case 3:
        	cout<<"\nNama Pemesan = "<<pemesan<<endl;
            traversal(first);
        break;

        case 4:
            Sort(first);
            traversal(first);
            break;
        case 5:
        	update(first);	
        }
        system("pause");
    }
    
}
