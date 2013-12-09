import java.io.*;
import java.util.*;
class ALMOSTPR{
	private static boolean flag[];
	private static int MAX=1000000;
	private static ArrayList FLAG=new ArrayList();
	private static void setFlag(){
		flag=new boolean[MAX+1];
		int i,j;
			 i=0;
			 while(i<=MAX){
			 	flag[i]=true;
			 	i++;
			 }
			 long limit=(long)Math.sqrt(MAX);
			 i=2;
			 while(i<=limit){
			 	if(flag[i-1]){
			 	    FLAG.add(i);
			 		j=i;
			 		while(j*i<MAX){
			 			flag[j*i-1]=false;
			 			j++;
			 		}
			 	}
			 	i++;
			 }
			 while(i<(MAX)){
                if(flag[i-1]){
                    FLAG.add(i);
                }
                i++;
             }
	}
	public static void main(String args[])throws IOException{
		BufferedReader I=new BufferedReader(new InputStreamReader(System.in));
		setFlag();
		int T=Integer.parseInt(I.readLine());
		long P;
		long val;
		while(T>0){
			P=Long.parseLong(I.readLine());
			val=(long)Math.sqrt((long)P);
			if((val*val)==P){
				if(Collections.binarySearch(FLAG,val)>=0){
					System.out.println("YES");
				}
				else{
					System.out.println("NO");
				}
			}
			else{
					System.out.println("NO");
			}
			T--;
		}
	}
}