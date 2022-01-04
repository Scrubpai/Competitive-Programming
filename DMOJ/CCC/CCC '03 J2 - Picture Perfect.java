import java.util.Scanner;

public class ccc03j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);

		while (true) {
			int C = sc.nextInt();
			if (C==0) {
				break;
			} else if (C!=0) {
				double N = Math.sqrt(C);
				int X = (int) (N);
				while(true) {
					if ((C%X) == 0) {
						int Perimeter = (X) + (X) + (C/X) + (C/X);
						System.out.println("Minimum perimeter is " + Perimeter + " with dimensions " + X + " x " + (C/X));
					    break;
					} else {
						X--;
					}
				}
			}
		}



	}

}