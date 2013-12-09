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
			while(i<N)
			{
					str=I.readLine();
					SI[i]=str.substring(0,str.indexOf(' '));
					prio[i]=Integer.parseInt(str.substring(str.indexOf(' ')+1));
					i++;
			}
			Q=Integer.parseInt(I.readLine());
			String output[]=new String[Q];
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
						if(SI[k].substring(0,len).equals(QI))
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
					output[j]=SI[pos];
					j++;
			}
			i=0;
			while(i<Q)
			{
					System.out.println(SI[i]);
					i++;
			}
	}
}