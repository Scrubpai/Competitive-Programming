import java.util.Scanner;
public class nccc7j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);

		String [] A = new String[7];

		int count = 0;

		for (int i=0; i<7; i++) {
			A[i] = sc.next();
			if (A[i].equals("J")) {
				if (i==0||!A[i-1].equals("J")) {
					count++;
				}
			}
		}

			System.out.println(count);

		}

	}