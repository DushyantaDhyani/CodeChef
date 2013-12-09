import java.io.*;
class CLMBSTRS{
	private static int getCount(int Num){
		String str=Integer.toBinaryString(Num);
		int len=str.length();
		int i=0;
		int ctr=0;
		while(i<len){
			if(str.charAt(i)=='1'){
				ctr++;
			}
			i++;
		}
		return ctr;
	}
	public static void main(String args[])throws IOException{
		BufferedReader I=new BufferedReader(new InputStreamReader(System.in));
		int T;
		int N,G;
		int K=2;
		int arr[]=new int[1000000];
		arr[0]=1;
		arr[1]=2;
		String str;
		int pos;
		T=Integer.parseInt(I.readLine());
		while(T>0){
			str=I.readLine();
			pos=str.indexOf(" ");
			N=Integer.parseInt(str.substring(0,pos));
			G=Integer.parseInt(str.substring(pos+1));
			if(N<=K){
				if(getCount(arr[N-1])==G){
					System.out.println("CORRECT");
				}
				else{
					System.out.println("INCORRECT");
				}
			}
			else{
				while(K<(N-1)){
					arr[K]=(arr[K-1]+arr[K-2])%1000000007;
					K++;
				}
				arr[N-1]=(arr[N-2]+arr[N-3])%1000000007;
				if(getCount(arr[N-1])==G){
					System.out.println("CORRECT");
				}
				else{
					System.out.println("INCORRECT");
				}
			}
			T--;
		}
		
	}
}