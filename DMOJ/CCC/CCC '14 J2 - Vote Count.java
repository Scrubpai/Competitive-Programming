import java.util.Scanner;

public class ccc14j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int V = sc.nextInt();
		String S = sc.next();
		
		String A = S.replace("A", "");
		String B = S.replace("B", "");
		
		int C = (S.length() - A.length());
		int D = (S.length() - B.length());
		
		if (C>D) {
			System.out.println("A");
		} else if (C<D) {
			System.out.println("B");
		} else {
			System.out.println("Tie");
		}
		
		
	}

}