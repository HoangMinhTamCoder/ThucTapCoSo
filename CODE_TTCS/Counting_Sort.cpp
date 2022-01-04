#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
using namespace std;

void InDs(unsigned long long int a[],unsigned long long int n){
	for(unsigned long long int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
//https://www.programiz.com/dsa/counting-sort
//https://kienthuc24h.com/tim-hieu-va-cai-dat-thuat-toan-counting-sort/
//https://blog.emptyq.net/a?id=00016-c6b698cd-75e1-4014-9a41-79515a6560f4
//https://hocjavascript.net/sap-xep/thuat-toan-sap-xep-dem-phan-phoi-counting-sort/
void CountingSort(unsigned long long int input[],unsigned long long int n)
{
    static unsigned long long int output[1000000];
    unsigned long long int max = input[0];
    unsigned long long int min = input[0];
    for(unsigned long long int i = 1; i < n; i++)
    {
        if(input[i] > max)
            max = input[i];
        else if(input[i] < min)
            min = input[i];
    }
    unsigned long long int k = max - min + 1;
    unsigned long long int count_array[k];
    // Fill_n tạo ra 1 mảng bắt đầu từ count_array đến k với giá trị các pt la 0
    fill_n(count_array, k, 0);
    for(unsigned long long int i = 0; i < n; i++)
        count_array[input[i] - min]++;
    for(unsigned long long int i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];
    for(unsigned long long int i = 0; i < n; i++)
    {
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }
    for(unsigned long long int i = 0; i < n; i++)
        input[i] = output[i]; 
}
void countSort(long int array[], long int size) {
  // The size of count must be at least the (max+1) but
  // we cannot assign declare it as int count(max+1) in C++ as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  long int output[size];
  long int count[size];
  long int max = array[0];

  // Find the largest element of the array
  for (long int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Initialize count array with all zeros.
  for (long int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (long int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (long int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (long int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (long int i = 0; i < size; i++) {
    array[i] = output[i];
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
    	static unsigned long long int a[2000000];
    	cout << "SL pt " << n;
		for(unsigned long long int i = 0; i < n; i++){
			ifs >> a[i];
		}
		unsigned long long int length = sizeof(a)/sizeof(unsigned long long int);
		cout << "\nSl mang la: " << length << endl;
		cout << "\nMang la:\n";
		for(unsigned long long int i = 0; i < n; i++){
			cout << a[i] << "\t";
		}
		cout << "\n\nMang sau khi sap xep la:" << endl;
		CountingSort(a,n);
		end = clock();
		InDs(a,n);
		time_use = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "\nTime Short " << time_use;
	}
	return 0;
}
