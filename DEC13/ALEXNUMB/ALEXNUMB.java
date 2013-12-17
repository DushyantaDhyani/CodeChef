import java.io.*;
class ALEXNUMB{
	public static void main(String args[])throws IOException{
		BufferedReader I=new BufferedReader(new InputStreamReader(System.in));
		int T,N;
		long num;
		int i;
		T=Integer.parseInt(I.readLine());
		while(T>0){
			N=Integer.parseInt(I.readLine());
			i=0;
			I.readLine();
			num=((long)N)*(N-1)/2;
			System.out.println(num);
			T--;
		}
	}
}
