import java.util.Scanner;

public class ccc16j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);	  
		  
		int count = 0;  //scoreboard
		
		for (int i=0; i<6; i++) {
			String S = sc.next();  //W L
			if (S.equals("W")) {
				count++;
			}
		}
		
		if (count==0) {
			System.out.println(-1);
		} else if (count==1||count==2) {
			System.out.println(3);
		} else if (count==3||count==4) {
			System.out.println(2);
		} else if (count==5||count==6) {
			System.out.println(1);
		}
		
	}

}