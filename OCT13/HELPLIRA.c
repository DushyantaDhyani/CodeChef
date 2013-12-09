#include<stdio.h>
#include<float.h>
#include<math.h>
int main(){
	int N;
	scanf("%d",&N);
	int x1,x2,x3,y1,y2,y3,i;
	int index1,index2;
	double area1,area2,area;
	area1=DBL_MIN;
	area2=DBL_MAX;
	index2=index1=-1;
	i=1;
	while(i<=N){
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
		area=0.5* (x1*(y2-y3)+ x2*(y3-y1) + x3*(y1-y2));
		printf("Area %lf\n",area);
		if(area<0){
			area*=-1;
		}
		printf("Area %lf\n",area);
		if(area1 <= area){
			area1=area;
			index1=i;
		}
		if(area2 >= area){
			area2=area;
			index2=i;
		}
		i++;
	}
	printf("%d %d\n",index2,index1);
	return 0;
}
