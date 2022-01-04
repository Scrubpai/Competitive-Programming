import java.util.Scanner;

public class ccc07j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int A = sc.nextInt(); //Baby bear's bowl - lightest
		int B = sc.nextInt(); //Mama bear's bowl - medium
		int C = sc.nextInt(); //Papa bear's bowl - heaviest
		
		if ((A<B && B<C) || (C<B && B<A)) {
			System.out.println(B);
		} else if ((B<A && A<C) || (C<A && A<B)) {
			System.out.println(A);
		} else if ((B<C && C<A) || (A<C && C<B)) {
			System.out.println(C);
		}
		
	}

}