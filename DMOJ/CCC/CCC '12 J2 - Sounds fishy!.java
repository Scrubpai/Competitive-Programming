import java.util.Scanner;

public class ccc12j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);		
		
		int Number1 = sc.nextInt();
		int Number2 = sc.nextInt();
		int Number3 = sc.nextInt();
		int Number4 = sc.nextInt();
		
		if (Number1<Number2 && Number2<Number3 && Number3<Number4) {
			System.out.println("Fish Rising");
		} else if (Number1>Number2 && Number2>Number3 && Number3>Number4) {
			System.out.println("Fish Diving");
		} else if (Number1==Number2 && Number2==Number3 && Number3==Number4) {
			System.out.println("Fish At Constant Depth");
		} else {
			System.out.println("No Fish");
		}
		
	}

}