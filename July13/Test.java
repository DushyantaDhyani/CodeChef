class TopFox{
	public int possibleHandles(String familyName,String givenName){
		int len2=givenName.length();
		int len21=0;
		int len22;
		char sc;
		while(givenName.charAt(len21)==givenName.charAt(0)){
			len21++;
		}
		len22=len2-len21;
		int i=0;
		int len=familyName.length();
		int Total=0;
		boolean flag=false;
		char ch;
		sc=givenName.charAt(0);
		while(i<len){
			ch=familyName.charAt(i);
			if(ch==sc){
				if(flag){
					Total+=1+len22;
				}
				else{
					flag=true;
					Total+=1+len22;
				}
			}
			else{
				flag=false;
				Total+=len2;
			}
			i++;
		}
		return Total;
	}
}
class Test{
	public static void main(String args[]){
		TopFox ob=new TopFox();	
		System.out.println(ob.possibleHandles("ababababab","bababababa"));
	}
}
