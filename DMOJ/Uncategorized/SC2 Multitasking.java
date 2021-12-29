import java.util.Scanner;

public class ppwindsor18p3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int count4 = 0;
		for (int i=0; i<N; i++) {
			String S = sc.next();
			int count = 0;
			int count2 = 0;
			int count3 = 0;
			for (int j=0; j<S.length(); j++) {
				if (S.charAt(j) == 'q' || S.charAt(j) == 'w' || S.charAt(j) == 'e' || S.charAt(j) == 'r' || S.charAt(j) == 't' || S.charAt(j) == 'y' || S.charAt(j) == 'u' || S.charAt(j) == 'i' || S.charAt(j) == 'o' || S.charAt(j) == 'p') {
					count++;
					if (count==S.length()) {
						count4++;
					}
				} else if (S.charAt(j) == 'a' || S.charAt(j) == 's' || S.charAt(j) == 'd' || S.charAt(j) == 'f' || S.charAt(j) == 'g' || S.charAt(j) == 'h' || S.charAt(j) == 'j' || S.charAt(j) == 'k' || S.charAt(j) == 'l') {
					count2++;
					if (count2==S.length()) {
						count4++;
					}
				} else if (S.charAt(j) == 'z' || S.charAt(j) == 'x' || S.charAt(j) == 'c' || S.charAt(j) == 'v' || S.charAt(j) == 'b' || S.charAt(j) == 'n' || S.charAt(j) == 'm') {
					count3++;
					if (count3==S.length()) {
						count4++;
					}
				}
			}
		}
		
		System.out.println(count4);
		
	}

}