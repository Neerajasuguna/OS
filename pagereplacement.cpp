#include <bits/stdc++.h> 
using namespace std; 

bool search(vector<int>&frame, int value){
	
	for(int i=0;i<frame.size();i++){
		if(frame[i] == value)
			return true;
	}
	return false;
}

int closestIndex(int pagerequest[], int n,vector<int>&frame , int index, int direction){
	int farthest=index,res=-1;
	if(direction==-1){
		for(int i=0;i<frame.size();i++){
      int j;
      for(j=index;j>=0;j--){
        if(frame[i]==pagerequest[j]){
          if(j<farthest){
            j=farthest;
            res=i;
          }
          break;
        }
      }
    }
	}
	else{
    for(int i=0;i<frame.size();i++ ){
      int j;
      for(j=index;j<n;j++){
             if(frame[i]==pagerequest[j]){
                       if(j>farthest){
                          farthest=j;
                          res=i;
                        }
                       break;
               } 
      }
    if(j==n)
    return i;
		
		
	}
  return (res==-1)?0:res;
}
}
int main(){
	int pagerequest[] = { 7, 0, 1, 2,0,3}; 
    int n = sizeof(pagerequest) / sizeof(pagerequest[0]); 
    int m = 4; 
    vector<int>frame;
    int opthit=0;
     for(int i=0;i<n;i++){
      
		      if(search(frame, pagerequest[i])) {
                opthit++;
                continue;
          }
          else if(frame.size()<m){
                frame.push_back(pagerequest[i]);
                }
         else{
            int j=closestIndex(pagerequest,n,frame,i+1,1);
           frame[j]=pagerequest[i];
      
    }
  }  
	cout<<"Optimal: "<<endl;
    cout<<"Page faults :"<<n-opthit<<endl;
    cout<<"Hits "<< opthit<<endl;

frame.clear();
int lruhit=0;
for(int i=0;i<n;i++){
		if(search(frame, pagerequest[i])) {
      lruhit++;
    continue;
    }
    else if(frame.size()<m){
      frame.push_back(pagerequest[i]);

    }
    else{
      int j=closestIndex(pagerequest,n,frame,i-1,-1);
      frame[j]=pagerequest[i];
      
    }
    }
     cout<<"LRU: \n"<<endl;
    cout<<"Page faults :"<<n-lruhit<<endl;
    cout<<"       Hits :"<<lruhit<<endl;
    cout<<"  Hit Ratio :"<<((lruhit)*100.0/n)<<endl;
  frame.clear();
    int fifohit=0;
	int index=-1;
    
	for(int i=0;i<n;i++){
		if(search(frame,pagerequest[i])) {
      fifohit++;
      continue;
    }
		else if(frame.size()<m){
      frame.push_back(pagerequest[i]);

    }
    else{
      
			frame[(++index)%m] = pagerequest[i];
	
		}
	}
	cout<<"FIFO:\n"<<endl;
    cout<<"Page faults : "<<n-fifohit<<endl;
    cout<<" Hits : "<<fifohit<<endl;
    cout<<" Hit Ratio:"<< ((fifohit)*100.0/n)<<endl;
}  
