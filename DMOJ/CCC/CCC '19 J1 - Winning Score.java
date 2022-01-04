import java.util.Scanner;

public class ccc19j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int Apples3 = sc.nextInt();
		int Apples2 = sc.nextInt();
		int Apples1 = sc.nextInt();
		int Bananas3 = sc.nextInt();
		int Bananas2 = sc.nextInt();
		int Bananas1 = sc.nextInt();
		
		if ((Apples3*3 + Apples2*2 + Apples1) > (Bananas3*3 + Bananas2*2 + Bananas1)) {
			System.out.println("A");
		} else if ((Apples3*3 + Apples2*2 + Apples1) < (Bananas3*3 + Bananas2*2 + Bananas1)) {
			System.out.println("B");
		} else if ((Apples3*3 + Apples2*2 + Apples1) == (Bananas3*3 + Bananas2*2 + Bananas1)) {
			System.out.println("T");
		}
		
	}

}