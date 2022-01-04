import java.util.Scanner;

public class ccc13j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		String S = sc.next();
		
		S = S.replace("I", "");
		S = S.replace("O", "");
		S = S.replace("S", "");
		S = S.replace("H", "");
		S = S.replace("X", "");
		S = S.replace("Z", "");
		S = S.replace("N", "");
		
		if (S.length()==0) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
		
	}

}