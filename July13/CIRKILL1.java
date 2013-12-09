import java.io.*;
class Helper{
	private int arr1[];
	private int arr2[];
	private int size;
	private int i,j,k,l;
	String str[];
	public Helper(int n,BufferedReader I)throws IOException{
		size=n;
		arr1=new int[size];
		arr2=new int[size];
		i=0;
		while(i<size){
			str=(I.readLine()).split(" ");
			arr1[i]=Integer.parseInt(str[0]);
			arr2[i]=Integer.parseInt(str[1]);
			i++;
		}
	}
	private boolean check(int i1,int i2,int i3,int i4){
		double A1,A2,B1,B2,C1,C2;
		double p,q,r,s;
		double x,y;
		double det;
		double rad,distance;
		if((arr1[i1]==arr1[i2] && arr1[i2]==arr1[i3])|| (arr2[i1]==arr2[i2] && arr2[i2]==arr2[i3])){
			return false;
		}
		else{
			A1=arr2[i2]-arr2[i1];
			B1=arr1[i1]-arr1[i2];
			A2=arr2[i2]-arr2[i3];
			B2=arr1[i3]-arr1[i2];
			p=(arr1[i1]+arr1[i2])*1.0;
			q=(arr2[i1]+arr2[i2])*1.0;
			r=(arr1[i2]+arr1[i3])*1.0;
			s=(arr2[i2]+arr2[i3])*1.0;
			C1=A1*q-B1*p;
			C2=A2*s-B2*r;
			det=A1*B2-A2*B1;
			if(det==0){
				return false;
			}
			else{
				x=(A2*C1-A1*C2)*1.0;
				y=(B2*C1-B1*C2)*1.0;
			}
		}
		rad=Math.sqrt(Math.pow((x-2.0*det*arr1[i2]),2)+Math.pow((y-2.0*det*arr2[i2]),2));
		distance=Math.sqrt(Math.pow((x-2.0*det*arr1[i4]),2)+Math.pow((y-2.0*det*arr2[i4]),2));
		if(distance<=rad){
			//System.out.println("For "+rad+" "+distance+" "+i1+" "+i2+" "+i3+" "+i4);
			return true;
		}
		return false;
	}
	public int count(){
		int Count=0;
		i=0;
		while(i<(size-2)){
			j=i+1;
			while(j<(size-1)){
				k=j+1;
				while(k<size){
					l=0;
					while(l<size){
						if(!(l==i || l==j || l==k)){
							if(check(i,j,k,l)){
								Count++;
							}
						}
						l++;
					}
					k++;
				}
				j++;
			}
			i++;
		}
		return Count;
	}
}
class CIRKILL1{
	public static void main(String args[])throws IOException{
		Helper ob;
		BufferedReader I=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(I.readLine());
		int N;
		double Total;
		while(T>0){
			N=Integer.parseInt(I.readLine());
			ob=new Helper(N,I);
			Total=N*(N-1)*(N-2)*(N-3)*1.0/6;
			System.out.println(ob.count()*1.0/Total);
			T--;
		}
	}
}
