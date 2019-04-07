#include <iostream>

using namespace std;


int intentos(int n){
		if(n==1){return 0;}
		else{
			int c=0;
			while(n!=1){
				c++;
				if(n%2==0){
					n=n/2;
				}
				else{
					n=3*n+1;
				}
			}
		return c+1;
	}
}

void all_intentos(int a, int b){
	if(a>0 && b>0 && b<10000 && a<10000 && a<b){
		int max=0;
		for(int i=a;i<=b;i++){
			int c=intentos(i);
			if(c>max){
			max=c;
			}
		}
		cout<<a<<" "<<b<<" "<<max<<"\n";
	}
}
int main(){
	int a,b;
	while(cin>>a>>b){
		all_intentos(a,b);
	}
	return 0;
}