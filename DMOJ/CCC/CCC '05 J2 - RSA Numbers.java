import java.util.Scanner;

public class ccc05j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();
		int B = sc.nextInt();

		
		int count2 = 0;
		for (int i=A; i<=B; i++) {
			int count = 0;
			for (int C=1; C<=i; C++) {
				if (i%C == 0) {
					count++;
				}
			}
			if (count==4) {
				count2++;
			}
		}
		System.out.println("The number of RSA numbers between "+A+ " and " + B + " is " + count2);

	}

}