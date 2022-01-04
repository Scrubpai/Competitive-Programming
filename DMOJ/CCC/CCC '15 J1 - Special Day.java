import java.util.Scanner;

public class ccc15j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		byte Month = sc.nextByte();
		byte Day = sc.nextByte();
		
		if (Month==1 && Day>=1 && Day<=31) {
			System.out.println("Before");
		} else if (Month==2 && Day<18 && Day>=1) {
			System.out.println("Before");
		} else if (Month==2 && Day==18) {
			System.out.println("Special");
		} else if (Month==2 && Day>18 && Day<=31) {
			System.out.println("After");
		} else if (Month>2 && Month<=12 && Day>=1 && Day<=31) {
			System.out.println("After");
		}
		
	}

}