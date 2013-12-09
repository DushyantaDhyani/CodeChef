import java.io.*;
class InputGenerator{
	public static void main(String args[])throws IOException{
		FileWriter fr=new FileWriter("InputFile.txt");
		BufferedWriter br=new BufferedWriter(fr);
		int i=1;
		int N,G;
		while(i<=100000){
			N=(int)((Math.random()*1000000000)%1000000007);
			G=(int)(Math.random()*50);
			br.write(N+" "+G+"\n");
			i++;
		}
	}
}