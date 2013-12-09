#include<stdio.h>
#include<string.h>
#include<math.h>
int arr1[30];
int arr2[30];
int check(int pos1,int pos2,int pos3,int pos4){
	if(arr2[pos1]==arr2[pos2] && arr2[pos2]==arr2[pos3]){
		return 0;
	}
	if(arr1[pos1]==arr1[pos2] && arr1[pos1]==arr1[pos3]){
		return 0;
	}
	double m1,m2;
	double x,y;
	double p,q,r,s;
	p=(arr1[pos1]+arr1[pos2])*1.0/2;
	q=(arr2[pos1]+arr2[pos2])*1.0/2;
	r=(arr1[pos2]+arr1[pos3])*1.0/2;
	s=(arr2[pos2]+arr2[pos3])*1.0/2;
	if(arr1[pos1]==arr1[pos2]){
		y=(arr2[pos1]+arr2[pos2])*1.0/2;
		if(arr2[pos2]==arr2[pos3]){
			x=(arr1[pos2]+arr1[pos3])*1.0/2;
		}
		else{
			m2=(arr2[pos2]-arr2[pos3])*1.0/(arr1[pos2]-arr1[pos3]);
			x=r-m2*1.0*(y-s);
		}
	}	
	else if(arr1[pos2]==arr1[pos3]){
		y=(arr2[pos2]+arr2[pos3])*1.0/2;	
		if(arr2[pos1]==arr2[pos2]){
			x=(arr1[pos1]+arr1[pos2])*1.0/2;
		}
		else{
			m1=(arr2[pos2]-arr2[pos1])*1.0/(arr1[pos2]-arr1[pos1]);
			x=p-m1*1.0*(y-q);
		}
	}
	else{
		m1=(arr2[pos2]-arr2[pos1])*1.0/(arr1[pos2]-arr1[pos1]);
		m2=(arr2[pos2]-arr2[pos3])*1.0/(arr1[pos2]-arr1[pos3]);
		x=((r*1.0/m2)-(p*1.0/m1)+s-q)*m1*m2/(m1-m2);
		y=-1.0/m1*x+p*1.0/m1+q;
	}
	float rad=sqrt(pow((x-arr1[pos1]),2)+pow((y-arr2[pos1]),2));
	float distance=sqrt(pow((x-arr1[pos4]),2)+pow((y-arr2[pos4]),2));
	if(distance<=rad){
		//printf("Returning 1 for %d %d %d %d for rad = %f and distance = %f and x=%f and y=%f\n",pos1,pos2,pos3,pos4,rad,distance,x,y);
		return 1;
	}
	return 0;
}
int main(){
	int T;
	int N;
	int i,j,k,l;
	int total;
	int count;
	scanf("%d",&T);
	while(T>0){
		count=0;
		total=0;
		scanf("%d",&N);
		total=N*(N-1)*(N-2)*(N-3)/6;
		memset(arr1,0,sizeof(arr1));
		memset(arr2,0,sizeof(arr2));
		i=0;
		while(i<N){
			scanf("%d %d",&arr1[i],&arr2[i]);
			i++;
		}
		i=0;
		while(i<(N-2)){
			j=i+1;
			while(j<(N-1)){
				k=j+1;
				while(k<(N)){
					l=0;
					while(l<N){
						if(!(l==i || l==j || l==k)){
							if(check(i,j,k,l)){
								count++;
							}
						}
						l++;
					}
					k++;
				}
				j++;
			}
			i++;
		}
		//printf("Count is %d\n",count);
		printf("%.6f\n",((1.0*count)/total));
		T--;
	}
	return 0;
}
