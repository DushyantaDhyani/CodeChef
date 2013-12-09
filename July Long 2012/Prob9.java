package prob9;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Prob9 {

    public static void main(String[] args) throws IOException {
        int num;
        int i;
        int val;
        int index;
        String arr[];
        ArrayList<Integer> al = new ArrayList();
        ArrayList<Integer> temp = new ArrayList();
        BufferedReader I = new BufferedReader(new InputStreamReader(System.in));
        int getVal;
        num = Integer.parseInt(I.readLine());
        for (i = 1; i <= num; i++) {
            arr = (I.readLine()).split(" ");
            if (arr[0].equals("1")) {
                val = Integer.parseInt(arr[1]);
                temp.add(val);

            } else {
                Collections.sort(temp);
                
                getVal = al.size();
                if ((getVal / 3) == 0) {
                    System.out.println("No reviews yet");
                } else {
                    index = getVal - (getVal / 3);
                    System.out.println(al.get(index));
                }

            }


        }
    }
}
