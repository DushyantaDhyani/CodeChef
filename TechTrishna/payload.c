#include<stdio.h>
int main()
{
          int Num;
          int Max;
          scanf("%d",&Num);
          scanf("%d",&Max);
          int arr_wt[Num];
          int arr_cost[Num];
          float avg[Num];
          int i,pos;
          float min;
          float ovmax=0.0f;
          float wt=0.0;
          float totcost=0.0;
          for(i=0;i<Num;i++)
          {
                            scanf("%d",&arr_wt[i]);
                            scanf("%d",&arr_cost[i]);
                            avg[i]=(1.0*arr_wt[i])/arr_cost[i];
          }
          ovmax=avg[0];
          for(i=1;i<Num;i++)
          if(avg[i]>ovmax)
          {
                          ovmax=avg[i];
          }
          ovmax++;
       
          while(wt<=(1.0*Max))
          {
                              min=avg[0];
                              pos=0;
                              for(i=1;i<Num;i++)
                              {
                                                if(avg[i]<min)
                                                {
                                                              min=avg[i];
                                                              pos=i;
                                                }
                                                
                              }
                              if(pos==0 && min==ovmax)
                              break;
                              if(arr_wt[pos]<=(Max-wt))
                              {
                                                      wt=wt+arr_wt[pos];
                                                      totcost+=arr_cost[pos];
                                                      avg[pos]=ovmax;
                              }
                              else
                              {
                                  totcost+=(Max-wt)/avg[pos];
                                  wt=wt+(Max-wt);
                                  avg[pos]=ovmax;             
                              }
          }
          printf("%.6f",totcost);
          return 0;
}
