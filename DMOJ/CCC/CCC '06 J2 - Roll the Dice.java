import java.util.Scanner;

public class ccc06j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int m = sc.nextInt();
		int n = sc.nextInt();
		
		int count = 0;
		for (int d1=1; d1<=m; d1++) {
			for (int d2=1; d2<=n; d2++) {
				if (d1+d2==10) {
					count++;
				}
			}
		}
		
		if (count==1) {
			System.out.println("There is 1 way to get the sum 10.");
		} else {
			System.out.println("There are "+count +" ways to get the sum 10.");
		}
		
	}

}