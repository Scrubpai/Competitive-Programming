import java.util.Scanner;

public class ccc11j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);

		int humidity = sc.nextInt();
		int time = sc.nextInt();

		for (int i=1; i<=time; i++) {
			if (-6*Math.pow(i, 4)+humidity*Math.pow(i, 3)+2*Math.pow(i, 2)+i <= 0) {
				System.out.println("The balloon first touches ground at hour:\n" +i);
				return;
			}
		}
		System.out.println("The balloon does not touch ground in the given time.");

	}
}