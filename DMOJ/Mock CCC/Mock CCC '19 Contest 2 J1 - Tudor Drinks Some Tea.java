import java.util.Scanner;
public class nccc7j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int count = 0;
		
		for (int i=0; i<5; i++) {
			String S = sc.next();
			if (S.equals("P")) {
				count++;
			}
		}
		
		System.out.println(count);
		
	}

}