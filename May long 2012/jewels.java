import java.io.*;
class jewels
{
	public static void main(String args[])throws IOException
	{
			BufferedReader I=new BufferedReader(new InputStreamReader(System.in));
			int T=Integer.parseInt(I.readLine());
			int output[]=new int[T];
			String S,J;
			int i=0;
			int j=0;
			int k;
			String ch="";
			int ctr=0;
			while(i<T)
			{
				ctr=0;
				k=0;
				J=I.readLine();
				S=I.readLine();
				j=S.length();
				while(k<j)
				{
					ch=S.substring(k,k+1);
					if(J.contains(ch))
					ctr++;
					k++;
				}
				output[i]=ctr;
				i++;
			}
			i=0;
			while(i<T)
			{
				System.out.println(output[i]);
				i++;
			}
	}
	
}