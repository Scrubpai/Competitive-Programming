import java.util.Scanner;

public class ccc11j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int Antenna = sc.nextInt();
		int Eyes = sc.nextInt();
		
		if (Antenna>=3 & Eyes<=4) {
			System.out.println("TroyMartian");
		}
		
		if (Antenna<=6 & Eyes>=2) {
			System.out.println("VladSaturnian");
		}
		
		if (Antenna<=2 & Eyes<=3) {
			System.out.println("GraemeMercurian");
		}
		
	}

}