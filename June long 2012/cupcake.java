import java.io.*;
class cupcake
{
		public static void main(String args[])throws IOException
		{
				BufferedReader I=new BufferedReader(new InputStreamReader(System.in));
				int T;
				T=Integer.parseInt(I.readLine());
				int input[T];
				int i,j,k;
				int num,max;
				i=0;
				while(i<T)
				{
						input[i]=Integer.parseInt(I.readLine());
						i++;
				}
				max=findmax(input);
				boolean isprime[max+1];
				i=0;
				while(i<(max+1))
				{
						isprime[i]=true;
						i++;
				}
				isprime[0]=isprime[1]=false;
				int root=Math.sqrt(max);
					
				for(j=2;j<=root;j++)
				{
                        if(isprime[j])
                        {
                            for(k=j*j;k<=max;k=k+j)
                            isprime[k]=false;           
                        }
				}
				i=0;
				while(i<T)
				{
					num=input[i];
					if(checkSquare(num))
					System.out.println(0);
					else if(isprime[num])
					System.out.println((num-1));
					else
					eval(num);
					i++;
				}
		}
		public int findmax(int arr[])
		{
			int max=arr[0];
			int j=1;
			
			while(j<arr.length)
			{
				if(arr[j]>max)
				max=arr[j];
			}
			return max;
		}
		public int checkSquare(int num)
		{
			int s=Math.sqrt(num);
			if((s*s)==num)
			return 1;
			else
			return 0;
		}
		public void eval(int num)
		{
			 int i=2;
			int limit=num/2;
			int num1,num2,mindiff;
			while(i<=limit)
			{
                    if((num%i)==0)
                    {
                                 limit=num/i;
                                 break;
                    }
                    i++;
			}
			num1=i;
			num2=num/i;
			mindiff=num2-num1;
			if(mindiff==1)
			{
                   System.out.println(1);
                   return;
			}
			i++;
			while(i<limit)
			{
                   
                    if((num%i)==0)
                    {
                                 num1=i;
                                 num2=num/i;
                                 limit=num2;
                                 if((num2-num1)<mindiff)
                                 {
                                                        mindiff=num2-num1;
                                                        if(mindiff==1)
                                                        {
                                                                 System.out.println(1);
                                                                 return;
                                                        }
                                 }
                    }
                                      
                    i++;
			}	     
			System.out.println(mindiff);
		}

}