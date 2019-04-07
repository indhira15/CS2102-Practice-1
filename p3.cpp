#include "iostream"
#include <stdio.h> 

using namespace std;

void insertionSort(int A[],int n){
	int k,a;
	for(int i=0;i<n;i++){
		a=A[i];
		k=i;
		while(A[k-1]>a && k>=1){
			A[k]=A[k-1];
			k--;
		}
		A[k]=a;
	}

}

void merge(int A[], int izq, int der, int middle){
	const int izq_size=middle-izq;
	const int der_size=der-middle+1;
	int der_v[der_size];
	int izq_v[izq_size];

	for(int i=0;i<izq_size;++i){
		izq_v[i]=A[i+izq];
	}
	for (int i = 0; i < der_size; ++i){
		der_v[i]=A[middle+i];
	}
	int der_v_p=0,izq_v_p=0;
	int start_sub=izq;

	while(izq_v_p < izq_size && der_v_p < der_size){
		if(izq_v[izq_v_p] <= der_v[der_v_p]){
			A[start_sub]= izq_v[izq_v_p];
			izq_v_p++;
		}
		else{
			A[start_sub]=der_v[der_v_p];
			der_v_p++;
		}
		start_sub++;
	}
	while(der_v_p<der_size){
		A[start_sub]=der_v[der_v_p];
		der_v_p++;
		start_sub++;
	}
	while(izq_v_p<izq_size){
		A[start_sub]=izq_v[izq_v_p];
		izq_v_p++;
		start_sub++;
	}

}

void merge_sort(int A[],int izq,int der){
	if(izq<der){
		int middle=(der-izq)/2+ izq+1;
		merge_sort(A,izq,middle-1);
		merge_sort(A,middle,der);
		merge(A,izq,der,middle);
		
	}
}


int main(){
	int arr[8]={25,43,11,24,85,23,45,67};
	/*
	insertionSort(arr,8);

	for(int i=0;i<9;++i){
		cout<<arr[i]<<" ";
	}
	*/
	merge_sort(arr,0,7);
	for(int i=0;i<8;++i){
		cout<<arr[i]<<" ";
	}
	return 0;

}
