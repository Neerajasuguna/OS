#include<bits\stdc++.h>
using namespace std;
int main(){
	int rs[50], i, j, k, n, f, count[20], m[20], min, pf=0;
	cout<<"Enter number of page references:"<<endl;
	cin>>n;
	cout<<"Enter the reference string:"<<endl;
	for(i=0;i<n;i++)
		cin>>rs[i];
	cout<<"Enter the available no. of frames:"<<endl;
	cin>>f;
	for(i=0;i<f;i++){
		count[i]=0;
		m[i]=-1;
	}
	
	for(i=0;i<n;i++){
		for(k=0;k<f;k++){
			if(rs[i]==m[k]){
				count[k]++;
				break;
			}
		}
		if(k==f){
			if(i<f){
				m[i]=rs[i];
				count[i]++;
			}
			else{
				min = 0;
				for(j=1;j<f;j++)
					if(count[min]>count[j])
						min=j;
				m[min]=rs[i];
				count[min]=1;
			}
			pf++;
		}
		
	}
	cout<<" Total number of page faults"<<pf<<endl;
  return 0;
}
