import java.util.Scanner;

public class ccc03j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		//4 	top part how many stars in each column
				//3		how many spaces
				//2		bottom part how many asterisks

				//		*   *   *
				//		*   *   *
				//		*   *   *
				//		*   *   *
				//		*********
				//		    *
				//		    *

				int t = sc.nextInt(); //height of the tines
				int s = sc.nextInt(); //spacing between the tines
				int h = sc.nextInt(); //length of the handle

				//only output the first line
				//output 1 star
				for (int j=0; j<t; j++) {

					//output s spaces
					System.out.print("*");
					for (int i=0; i<s; i++) {
						System.out.print(" ");
					}
					//output 1 star
					System.out.print("*");

					//output s spaces
					//output 1 star
					for (int i=0; i<s; i++) {
						System.out.print(" ");
					}
					System.out.println("*");
				}


				for (int i=0; i<s*2+3; i++) {
					System.out.print("*");
				}
				System.out.println();

				//s+1 spaces, followed by 1 star

				for (int d=0; d<h; d++) {
					for (int i=0; i<(s+1); i++) {
						System.out.print(" ");
					}
					System.out.print("*");
					System.out.println();
				}
		
	}

}