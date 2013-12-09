import java.io.*;
class recipe
{
	public static void main(String args[])throws IOException
	{
			BufferedReader I=new BufferedReader(new InputStreamReader(System.in));
			int N=Integer.parseInt(I.readLine());
			String str="";
			String SI[]=new String[N];
			int prio[]=new int[N];
			int i=0;
			int k=0;
			int Q,len;
			int pos=0;
			String QI="";
			int pr;	
			int x;
			
			while(i<N)
			{
					str=I.readLine();
					x=str.indexOf(' ');
					SI[i]=str.substring(0,x);
					prio[i]=Integer.parseInt(str.substring(x+1));
					i++;
			}
			
			
			Q=Integer.parseInt(I.readLine());
			int output[]=new int[Q];
			int j=0;
			while(j<Q)
			{
					pr=-1*(int)Math.pow(10,9)-1;
					k=0;
					QI=I.readLine();
					len=QI.length();
					pos=-1;
					while(k<N)
					{
						if((SI[k].substring(0,len)).equals(QI))
						{
								if(prio[k]>pr)
								{
									pr=prio[k];
									pos=k;
								}
						}
						k++;
					}
					if(pos>=0)
					output[j]=pos;
					else
					output[j]=-1;
					j++;
			}
			i=0;
			while(i<Q)
			{
					if(output[i]>=0)
					System.out.println(SI[output[i]]);
					else
					System.out.println("NO");
					i++;
			}
	}
}