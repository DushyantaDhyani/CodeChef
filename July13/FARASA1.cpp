#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<cmath>
#include<map>
using namespace std;
int offset1,offset2,offset3;
long MaxSum;
vector< map<int, set < int > > > Data;
map<int, set <int> >::iterator it;
set<int>::iterator it1;
void setOffset(){
	int val=ceil(log10(MaxSum));
	offset1=val/3;
	offset2=val/3;
	offset3=val-(offset1+offset2);
}
void insert(long var){
	int val1,val2,val3;
	int pos1,pos2,pos3;
	pos1=((long)pow(10,(offset2+offset3)));
	pos2=((int)pow(10,(offset3)));
	val1=(int)(var/pos1);
	val2=(var%pos1)/pos2;
	val3=(var%pos1)%pos2;
	it=Data[val1].find(val2);
	if(it!=(Data[val1].end())){
		((*it).second).insert(val3);
	}
	else{
		set<int> Temp;
		Temp.insert(val3);
		(Data[val1])[val2]=Temp; 
	}
}
int main(){
	int N;
	int i;
	scanf("%d",&N);
	long Total=0;
	long arr1[N];
	long arr2[N];
	i=0;
	MaxSum=0;
	while(i<N){
		scanf("%ld",&arr1[i]);
		arr2[i]=arr1[i];
		MaxSum+=arr1[i];
		i++;
	}
	setOffset();
	Data.resize( ((int)pow(10,offset1)));
	int offset=1;
	insert(arr1[0]);
	while(offset!=(N)){
		printf("%d\n",offset);
		//insert(arr1[offset]);
		i=0;
		while(i<(N-offset)){
			arr2[i]+=arr1[i+offset];
			//insert(arr2[i]);
			i++;
		}
		offset++;
	}
	i=0;
	Total=0;
	while(i<Data.size()){
		it=Data[i].begin();
		while(it!=(Data[i].end())){
			Total+=((*it).second).size();
			it++;
		}
		i++;
	}
	/*
	i=0;
	int j;
	while(i<Data.size()){
		it=Data[i].begin();
		printf("Main Set %d\n",(i));
		while(it!=(Data[i].end())){
			printf("Subset %d\n",((*it).first));
			Total+=((*it).second).size();
			it1=((*it).second).begin();
			while(it1!=((*it).second).end()){
				printf("%d ",(*it1));
				it1++;
			}
			printf("\n");
			it++;
		}
		i++;
	}*/
	printf("%ld\n",(Total-1));
	return 0;
}

