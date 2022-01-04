#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
using namespace std;
//http://hiepsiit.net/detail/ctdl/ctdlvagiaithuat/giaithuatshellsort
void InDs(unsigned long long int a[],unsigned long long int n){
	for(unsigned long long int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
void ShellSort(unsigned long long int a[], unsigned long long int n)
{
	for (unsigned long long int gap = n/2; gap > 0; gap /= 2)
    {
        for (unsigned long long int i = gap; i < n; i += 1)
        {
            unsigned long long int temp = a[i];
            unsigned long long int j;           
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}
void shellSort_ct(unsigned long long int arr[], unsigned long long int n){
    unsigned long long int inner, outer;
    unsigned long long int X;
    unsigned long long int h = 1;
    unsigned long long int i = 0;
    //Tìm khoảng cách h cho danh sách
    //VD: n = 12 pt => h = 4 khoang cach hop ly de sap xep
    while(h <= n / 3) {
        h = h * 3 + 1;
    }
    while(h > 0) {
    	// Thực hiện hoán đổi giữa 2 phần tử có khoảng cách h
        for(outer = h; outer < n; outer++) {
            X = arr[outer];
            inner = outer; //Vị trí của X
 			// Đổi đk để hoán đổi
            while(inner > h -1 && arr[inner - h] >= X) {
                arr[inner] = arr[inner - h];
                inner -= h;
            }
            arr[inner] = X;
        }
        h = (h -1) /3;
        i++;
    }
}
int main(){
	clock_t start, end;
	double time_use;
	unsigned long long int n;
	start = clock();
	ifstream ifs("DATA/200000_GD.txt");
    if(!ifs){
        cerr << "Error: file not opened." << endl;
    }
    else{
    	ifs >> n;
    	static unsigned long long int a[200000];
    	cout << "SL pt " << n;
		for(unsigned long long int i = 0; i < n; i++){
			ifs >> a[i];
		}
		cout << "\nMang la:\n";
		for(unsigned long long int i = 0; i < n; i++){
			cout << a[i] << "\t";
		}
		cout << "\n\nMang sau khi sap xep la:" << endl;
		ShellSort(a,n);
		end = clock();
//		shellSort_ct(a,n);
		InDs(a,n);
		time_use = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "\nTime Short " << time_use;
	}
}
