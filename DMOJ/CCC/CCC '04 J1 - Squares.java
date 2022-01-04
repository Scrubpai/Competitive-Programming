import java.util.Scanner;

public class ccc04j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		int TileNumber = sc.nextInt();
		
		int y = (int) (Math.sqrt(TileNumber));
		
		System.out.println("The largest square has side length " + y + ".");

	}

}