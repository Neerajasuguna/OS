#include <bits/stdc++.h> 
using namespace std; 
void MFT(int ms,int mp[],int n){
  int bs;
  cout<<"enter block size"<<endl;
  cin>>bs;
 int nob=ms/bs;
 int efmem=ms-nob*bs;
 int p=0,tif=0;
 cout<<"IN MFT"<<endl;
 cout<<"P=PROCESS"<<" "<<"MR=MEMORY REQUIRED"<<" "<<"AL=ALLOCATED OR NOT"<<" "
 <<"IF=INTERNAL FRAGMENTATION"<<endl;
 cout<<"P"<<" "<<"MR"<<" "<<" "<<"AL"<<" "<<"IF"<<endl;
  int i;
 for(i=0;i<n&&p<nob;i++){
   cout<<"P"<<i<<" "<<mp[i]<<" ";
   if(mp[i]>bs)
     cout<<"NO"<<" "<<"-"<<endl;
     else{
       cout<<"YES"<<" "<<bs-mp[i]<<endl;
       tif=tif+bs-mp[i];
       p++;

     }
     

   }
if(i<n)
 cout<<"Memory is occupied,Remaining Processes cannot be accomadated"<<endl;
 
 cout<<"Total Internal Fragmentation"<<tif<<endl;
 cout<<"Total external Fragmentation"<<efmem<<endl;

}
void MVT(int ms,int mp[],int n){
  cout<<"IN MVT"<<endl;
  cout<<"P"<<" "<<"Mal"<<endl;
  int i;
  for(i=0;i<n;i++){
    if(mp[i]<=ms){
      cout<<"P"<<i<<" "<<mp[i]<<endl;
      ms=ms-mp[i];

    }
    else {

    cout<<"process P"<<i<<"is blocked"<<endl;
  }


}
    cout<<"External Fragmentation:"<<ms<<endl;
}

int main(){
  int ms,n,bs;
  cout<<"enter size of memory"<<endl;
  cin>>ms;
  
  cout<<"enter no of processes"<<endl;
  cin>>n;
  int mp[n];
  cout<<"enter each process size"<<endl;
  for(int i=0;i<n;i++)
    cin>>mp[i];
    MFT(ms,mp,n);
    MVT(ms,mp,n);

}
