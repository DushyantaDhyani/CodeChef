#define absolute(x) (x>0?x:(-1*x))
#include<stdio.h>
#include<string.h>
int main(){
    int T;
    int N;
    int i,j;
    long long sum,Msum;
    int flag;
    scanf("%d",&T);
    while(T>0){
	    scanf("%d",&N);
	    long long Data[N];
	    long long MinL[N];
	    long long MinR[N];
	    long long MaxL[N];
	    long long MaxR[N];
	    i=0;
	    while(i<N){
		    scanf("%lld",&Data[i]);
		    MinL[i]=MinR[i]=MaxL[i]=MaxR[i]=0;
		    i++;
	    }
	    Msum=0;
	    i=0;
	    while(i<N){
		    sum=0;
		    j=i;
		    flag=0;
		    while(j<N && sum<=0){
			    sum+=Data[j];
			    if(sum<Msum){
				    Msum=sum;
				    flag=1;
			    }
			    MinL[j]=Msum;
			    if(!flag){
				    MinL[j]=Data[j];
				    if(j>=1){
					    if(MinL[j]>MinL[j-1]){
						    MinL[j]=MinL[j-1];
					    }
				    }
			    }
			    j++;
		    }
		    i=j;
	    }
    	    Msum=0;
	    i=N-1;	
	    while(i>=0){
		    sum=0;
		    j=i;
		    flag=0;
		    while(j>=0 && sum<=0){
			    sum+=Data[j];
			    if(sum<Msum){
				    Msum=sum;
				    flag=1;
			    }
			    MinR[j]=Msum;
			    if(!flag){
				    MinR[j]=Data[j];
				    if(j<(N-1)){
					    if(MinR[j]>MinR[j+1]){
						    MinR[j]=MinR[j+1];
					    }
				    }
    			    }
			    j--;			
    		    }
    		    i=j;
    	    }
    Msum=0;
    i=0;
    while(i<N){
    sum=0;
    j=i;
    flag=0;
    while(j<N && sum>=0){
    sum+=Data[j];
    if(sum>Msum){
    Msum=sum;
    flag=1;
    }
    MaxL[j]=Msum;
    if(!flag){
    MaxL[j]=Data[j];
    if(j>=1){
    if(MaxL[j]<MaxL[j-1]){
    MaxL[j]=MaxL[j-1];
    }
    }
    }
    j++;
    }
    i=j;
    }
    Msum=0;
    i=N-1;
    while(i>=0){
    sum=0;
    j=i;
    flag=0;
    while(j>=0 && sum>=0){
    sum+=Data[j];
    if(sum>Msum){
    Msum=sum;
    flag=1;
    }
    MaxR[j]=Msum;
    if(!flag){
    MaxR[j]=Data[j];
    if(j<(N-1)){
    if(MaxR[j]<MaxR[j+1]){
    MaxR[j]=MaxR[j+1];
    }
    }
    }
    j--;
    }
    i=j;
    }
    /*Printing The Values of The Different Arrays */
    /*
    i=0;
    while(i<N){
    printf("%lld %lld %lld %lld\n",MinL[i],MinR[i],MaxL[i],MaxR[i]);
    i++;
    }
    */
    long long sum1,temp;
    i=1;
    sum=absolute((MaxL[0]-MinR[1]));
    while(i<N-1){
    if((temp=(absolute((MaxL[i]-MinR[i+1]))))>sum){
    sum=temp;
    }
    i++;
    }
    i=1;
    sum1=absolute((MinL[0]-MaxR[1]));
    while(i<N-1){
    if((temp=(absolute((MinL[i]-MaxR[i+1]))))>sum1){
    sum1=temp;
    }
    i++;
    }
    sum>sum1?printf("%lld\n",sum):printf("%lld\n",sum1);
    T--;
    }
    return 0;
    } 
