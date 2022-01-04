import java.util.Scanner;

public class ccc04j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int X = sc.nextInt();
		int Y = sc.nextInt();
		
		for (int i=X; i<=Y; i+=60) {
			System.out.println("All positions change in year " + i);
		}
		
	}

}