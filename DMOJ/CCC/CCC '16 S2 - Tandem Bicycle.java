import java.util.Arrays;
import java.util.Scanner;

public class ccc16s2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);

		int Q = sc.nextInt();
		int S = sc.nextInt();

		int[] DS = new int[S];
		int[] PS = new int[S];

		for (int i=0; i<DS.length; i++) {
			DS[i] = sc.nextInt();
		}

		for (int i=0; i<PS.length; i++) {
			PS[i] = sc.nextInt();
		}
		Arrays.sort(PS);
		Arrays.sort(DS);

		int sum = 0;
		if (Q==1) {
			for (int i=0; i<PS.length; i++) {
				if (DS[i]>PS[i]) {
					sum = sum + DS[i];
				} else {
					sum += PS[i];
				}
			}
		} else if (Q==2) {
			for (int i=0; i<PS.length; i++) {
				int bIndex = S-1-i;
				if (DS[i]>PS[bIndex]) {
					sum = sum + DS[i];
				} else {
					sum += PS[bIndex];
				}

			}
		}
		System.out.println(sum);
	}
}