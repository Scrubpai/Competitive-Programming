import java.io.IOException;
import java.util.Scanner;

public class dmopc18c6p11 {

	public static void main(String[] args) throws IOException {
		
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		String S = sc.next();
		boolean DNA = true;
		boolean RNA = true;
		for (int i=0; i<S.length(); i++) {
			if (S.charAt(i)!='A' && S.charAt(i)!='C' && S.charAt(i)!='G' && S.charAt(i)!='T' && S.charAt(i)!='U') {
				DNA = false; 
				RNA = false;
			}
			
			if (S.charAt(i)=='T') RNA = false;
			if (S.charAt(i)=='U') DNA = false;
		}
		
		if (RNA && DNA) System.out.println("both");
		else if (RNA && !DNA) System.out.println("RNA");
		else if (!RNA && DNA) System.out.println("DNA");
		else System.out.println("neither");
		
	}
	
}