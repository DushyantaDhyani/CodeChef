import java.io.*;
import java.util.*;
class GALACTIK{
	private static int arr[];
	private static int N,M;
	private static int j;
	static Map<Integer,Integer> Data;
	private static void union(int x,int y){
		x=find(x);
		y=find(y);
		if(x<y){
			arr[y]=x;
		}
		else{
			arr[x]=y;
		}
	}
	private static int find(int x){
		while(x!=arr[x]){
			x=arr[x];
		}
		return x;
	}
	private static void setStructure(BufferedReader I)throws IOException{
		int i=1;
		String arr[];
		int x,y;
		while(i<=M){
			arr=(I.readLine()).split(" ");
			x=Integer.parseInt(arr[0]);
			y=Integer.parseInt(arr[1]);
			if(x<y){
				union(x,y);
			}
			else{
				union(y,x);
			}
			i++;
		}
	}
	private static void setCost(BufferedReader I)throws IOException{
		int i=1;
		int Cost;
		int x;
		int temp;
		while(i<=N){
			Cost=Integer.parseInt(I.readLine());
			if(i==arr[i]){
				Data.put(i,Cost);
			}
			else{
				x=find(i);
				temp=Data.get(x);
				if(Cost>0 && temp>Cost){
					Data.put(x,Cost);
				}
			}
			i++;
		}
	}
	private static long getCost(){
		Iterator it=Data.entrySet().iterator();
		Iterator it1;
		int key1,key2,value1,value2;
		long Total=0;
		while(it.hasNext()){
			Map.Entry pairs=(Map.Entry)it.next();
			key1=(Integer)pairs.getKey();
			value1=(Integer)pairs.getValue();
			if(value1<0){
				return -1;
			}
			it1=it;
			if(it1.hasNext()){
				Map.Entry pairs2=(Map.Entry)it1.next();
				key2=(Integer)pairs2.getKey();
				value2=(Integer)pairs2.getValue();
				if(value2<0){
					return -1;
				}
				System.out.println(key1+" "+value1+" "+key2+" "+value2);
				if(value2<value1){
					Data.put(key1,value2);
				}
				Total+=value1+value2;
				Data.remove(key2);
			}
			else{
				break;
			}
		}
		return Total;
	}
	public static void main(String args[])throws IOException{
		BufferedReader I=new BufferedReader(new InputStreamReader(System.in));
		Data=new HashMap<Integer,Integer>();
		String arr1[]=(I.readLine()).split(" ");
		N=Integer.parseInt(arr1[0]);
		M=Integer.parseInt(arr1[1]);
		arr=new int[N+1];
		j=0;
		while(j<=N){
			arr[j]=j;
			j++;
		}
		setStructure(I);
		setCost(I);
		System.out.println(getCost());
	}
}
