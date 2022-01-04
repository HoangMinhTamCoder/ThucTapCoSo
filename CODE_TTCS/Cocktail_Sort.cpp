#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
using namespace std;
void swap(int a,int b)
{
	int x = a;
	a = b;
	b = x;
}
void InDs(int a[],int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void CocktailSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;
 
    while (swapped)
    {
        // reset the swapped flag on entering
        // the loop, because it might be true from
        // a previous iteration.
        swapped = false;
 
        // loop from left to right same as
        // the bubble sort
        for (int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
 
        // if nothing moved, then array is sorted.
        if (!swapped)
            break;
 
        // otherwise, reset the swapped flag so that it
        // can be used in the next stage
        swapped = false;
 
        // move the end point back by one, because
        // item at the end is in its rightful spot
        --end;
 
        // from right to left, doing the
        // same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
 
        // increase the starting point, because
        // the last stage would have moved the next
        // smallest number to its rightful spot.
        ++start;
    }
}
void CocktailSort_v2(int a[],int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}
void ShakerSort(int a[], int m) {
   int i, j, k;
   for(i = 0; i < m;) {
      for(j = i+1; j < m; j++) {
         if(a[j] < a[j-1])
            swap(a[j], a[j-1]);
      }
      m--;
      for(k = m-1; k > i; k--) {
         if(a[k] < a[k-1])
            swap(a[k], a[k-1]);
      }
      i++;
   }
}
int main(){
	clock_t start, end;
	double time_use;
	int n;
	start = clock();
	ifstream ifs("DATA/200000_GD.txt");
    if(!ifs){
        cerr << "Error: file not opened." << endl;
    }
    else{
    	ifs >> n;
    	static int a[2000000];
    	cout << "SL pt " << n;
		for(int i = 0; i < n; i++){
			ifs >> a[i];
		}
		cout << "\nMang la:\n";
		InDs(a,n);
		cout << "\n\nMang sau khi sap xep la:" << endl;
		CocktailSort(a,n);
		end = clock();
		InDs(a,n);
		time_use = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "\nTime Short " << time_use;
	}
	return 0;
}