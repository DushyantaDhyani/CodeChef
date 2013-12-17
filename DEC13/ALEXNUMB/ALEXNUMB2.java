import java.io.*;
class Helper{
	private long size;
	private long result;
	public Helper(){
		size=0;
		result=0;
	}
	public Helper(long N){
		size=N;
	}
	public void getNum()throws IOException{
		BufferedReader I=new BufferedReader(new InputStreamReader(System.in));
		I.readLine();
	}
	public long getResult(){
		result=size*(size-1)/2;
		return result;
	}
}
class ALEXNUMB2{
	public static void main(String args[])throws IOException{
		BufferedReader I=new BufferedReader(new InputStreamReader(System.in));
		int T;
		long N;
		T=Integer.parseInt(I.readLine());
		while(T>0){
			N=Long.parseLong(I.readLine());
			Helper ob=new Helper(N);
			ob.getNum();
			System.out.println(ob.getResult());
			T--;
		}
	}
}
