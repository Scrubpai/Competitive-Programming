import java.util.Scanner;

public class ccc15j22 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		String S = sc.nextLine();
		
		String Happy = S.replace(":-)", "");
		String Sad = S.replace(":-(", "");
		
		int happyCount = (S.length()-Happy.length())/3;
		int sadCount = (S.length()-Sad.length())/3;
		
		if (happyCount==0 && sadCount==0) {
			System.out.println("none");
		} else if (happyCount==sadCount) {
			System.out.println("unsure");
		} else if (happyCount>sadCount) {
			System.out.println("happy");
		} else {
			System.out.println("sad");
		}
		
	}

}