import java.util.Scanner;

public class ccc01j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int x = sc.nextInt();
		int m = sc.nextInt();
		
		
		//		m/(x*n) % == 1;
		
		for (int n=1; n<m; n++) {
			if ((x*n)%m == 1) {
				System.out.println(n);
				return;
			} 
		}
		System.out.println("No such integer exists.");
		
	}

}