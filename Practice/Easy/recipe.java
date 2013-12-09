import java.io.*;
public class recipe{
	public static void main(String args[])throws IOException{
		BufferedReader I=new BufferedReader(new InputStreamReader(System.in));
		int T;
		int j,k;
		String str;
		char ch1,ch2;
		long value;
		T=Integer.parseInt(I.readLine());
		while(T>0){
			str=I.readLine();
			k=str.length()-1;
			j=0;
			value=1;
			while(j<=k){
				ch1=str.charAt(j);
				ch2=str.charAt(k);
				if(ch1!=ch2){
					if(ch1!='?' || ch2!='?'){
						value=0;
						break;
					}
				}
				else{
					if(ch1=='?'){
						value=((value%10000009)*26)%10000009;
					}
				}
				j++;
				k--;	
			}
			T--;
		}
	}
	
}
