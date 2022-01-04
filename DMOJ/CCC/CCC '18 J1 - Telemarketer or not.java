import java.util.Scanner;

public class ccc18j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);

		int D1 = sc.nextInt();
		int D2 = sc.nextInt();
		int D3 = sc.nextInt();
		int D4 = sc.nextInt();

		if ((D1==9 || D1==8) && (D4==8 || D4==9) && D2==D3) {
			System.out.println("ignore");
		} else {
			System.out.println("answer");
		}
		
	}

}