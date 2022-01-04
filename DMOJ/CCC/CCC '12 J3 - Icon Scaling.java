import java.util.Scanner;

public class ccc12j3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);

		String S1 = "*x*";
		String S2 = " xx";
		String S3 = "* *";
		int N = sc.nextInt();

		//***xxx***
		//read one char and output the char N times
		for (int k=0; k<N; k++) {
			//Below is one line code
			for (int i=0; i<S1.length(); i++) {
				//repeat char N times
				for (int j=0; j<N; j++) {
					//output one char
					System.out.print(S1.charAt(i));
				}
			}
			System.out.println();
		}

		for (int k=0; k<N; k++) {
			for (int i=0; i<S2.length(); i++) {
				for (int j=0; j<N; j++) {
					System.out.print(S2.charAt(i));
				}
			}
			System.out.println();

		}
		for (int k=0; k<N; k++) {
			for (int i=0; i<S3.length(); i++) {
				for (int j=0; j<N; j++) {
					System.out.print(S3.charAt(i));
				}
			}
			System.out.println();

		}
	}
}