#include<bits\stdc++.h>
using namespace std;

int main(){
	int n,i,j;
	float a;
	cout<<"Enter the no of processes"<<endl;
	cin>>n;
	float T[n],t[n];//array for predicted and actual times
	cout<<"Enter smoothing factor [Alpha]:"<<endl;
	cin>>a;//float because alpha ranges from 0 to 1
	if(a<0 || a>1){
		cout<<"Smoothing factor should be in range of 0<=alpha<=1"<<endl;
		return 0;
	}
	cout<<"Enter the previous times [t1,t2...]:\n"<<endl;
	for(i=0;i<n-1;i++){
		cin>>t[i];
	}
  
	cout<<"Give the predicted burst time of  P1"<<endl;
	cin>>T[0];
	for(i=1;i<n;i++){
		T[i]=(a*t[i-1])+((1-a)*T[i-1]);
	cout<<"Predicted burst time of"<<"P"<<i+1<<"is"<<T[i]<<endl;
	}

  return 0;
}
