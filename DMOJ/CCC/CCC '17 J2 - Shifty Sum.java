import java.util.Scanner;

public class ccc17j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int k = sc.nextInt();
		int sum = 0;;
		int originalN= N;
		
		for (int i=1; i<=k; i++) {
			N=N*10;
			sum = sum + N;
		}
		System.out.println(sum + originalN);
		
	}

}