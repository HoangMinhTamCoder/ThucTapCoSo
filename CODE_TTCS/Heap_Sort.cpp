#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
using namespace std;

void InDs(int a[],int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
void heapify(int arr[],int n,int i)
{
	int largest = i; // khoi tao largest nhu la root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// Neu nut con trai lon hon so voi root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Neu nut con phai lon hon so voi root
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Neu root khong phai la lon nhat
	if (largest != i) //Xấu nhất/ Tốt SWAP = 1 //XẤU NHẤT n
	{
		swap(arr[i], arr[largest]);

		// De quy lai ham heapify
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void HeapSort(int arr[],int n)
{
	// Tao mot dong (Sap xep lai mang)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);//1

	// for cùng cấp = (n/2 i => (0;n/2) + 2n = 5n/2 = n => Tốt nhất
	// Xấu nhất n*n/2 + n  +  n^2 => n^2 => n^2 => Xấu nhất
	// Trích xuất từng một phần tử một từ heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Di chuyen root ve cuoi cung
		swap(arr[0], arr[i]);// Tốt nhất: n

		// goi ham heapify
		heapify(arr, i, 0);// n = 2n
	}
}
int main(){
	int n;
	clock_t start, end;
	double time_use;
	start = clock();
	ifstream ifs("DATA/200000_GD.txt");
    if(!ifs){
        cerr << "Error: file not opened." << endl;
    }
    else{
    	ifs >> n;
    	static int a[200000];
    	cout << "SL pt " << n;
		for(int i = 0; i < n; i++){
			ifs >> a[i];
		}
		int length = sizeof(a)/sizeof(int);
		cout << "\nSl mang la: " << length << endl;
		cout << "\nMang la:\n";
		InDs(a,n);
		cout << "\n\nMang sau khi sap xep la:" << endl;
		HeapSort(a,n);
		end = clock();
		InDs(a,n);
		time_use = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "\nTime Short " << time_use;
	}
	return 0;
}
