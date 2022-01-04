import java.util.Scanner;

public class ccc19j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int L = sc.nextInt();
		
		for (int i=0; i<L; i++) {
			int amount = sc.nextInt();
			String character = sc.next();
			
			for (int j=0; j<amount; j++) {
				System.out.print(character);
			}
			System.out.println();
		}
		
	}

}