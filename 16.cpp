#include<bits/stdc++.h>
using namespace std;

struct pstruct {
	int fno;
	int pbit;
}ptable[10];
int pmsize,lmsize,psize,no_of_frames,no_of_pages,ftable[20],frameno;
void info(){
	cout<<"Enter the Size of Physical memory: "<<endl;
cin>>pmsize;
	cout<<"Enter the size of Logical memory: "<<endl;
	cin>>lmsize;
	cout<<"Enter the page size: "<<endl;
	cin>>psize;
	no_of_frames=pmsize/psize;
	no_of_pages=lmsize/psize;
	cout<<"The physical memory is divided into"<<no_of_frames<<"no of frames"<<endl;
	cout<<"The Logical memory is divided into"<<no_of_pages<<"no of pages"<<endl;
}
void assign(){
	int i,x;
	for (i=0;i<no_of_pages;i++){
		ptable[i].fno = -1;
		ptable[i].pbit= -1;
	}
	for(i=0; i<no_of_frames;i++)
		ftable[i] = 32555;
	for (i=0;i<no_of_pages;i++){
		cout<<"Enter the Frame number where page"<<i<<"must be placed: "<<endl;
		cin>>frameno;
		ftable[frameno] = i;
		if(ptable[i].pbit == -1){
			ptable[i].fno = frameno;
			ptable[i].pbit = 1;
		}
	}
	cout<<"PAGE TABLE"<<endl;
	cout<<"PageAddress  FrameNo. PresenceBit"<<endl;
	for (i=0;i<no_of_pages;i++)
		cout<<i<<" "<<ptable[i].fno<<" "<<ptable[i].pbit<<endl;
	cout<<"FRAME TABLE"<<endl;
	cout<<"FrameAddress PageNo"<<endl;
	for(i=0;i<no_of_frames;i++)
		cout<<i<<" "<<ftable[i]<<endl;
}

void cphyaddr(){
	int log_add,paddr,disp,phy_add,base_add;
	cout<<"Enter the Base Address: "<<endl;
	cin>>base_add;
	cout<<"Enter the Logical Address: "<<endl;
	cin>>log_add;
	paddr = log_add / psize;
	disp = log_add % psize;
	if(ptable[paddr].pbit == 1 )
		phy_add = base_add + (ptable[paddr].fno*psize) + disp;
	cout<<"The Physical Address where the instruction present:"<<phy_add<<endl;
}
int main(){
	info();
	assign();
	cphyaddr();
  return 0;
}
