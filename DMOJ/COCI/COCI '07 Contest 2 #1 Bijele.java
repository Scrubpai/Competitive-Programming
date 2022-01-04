import java.util.Scanner;

public class coci07c2p1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int king = sc.nextInt(); //1
		int queen = sc.nextInt(); //1
		int rook = sc.nextInt(); //2
		int bishop = sc.nextInt(); //2
		int knight = sc.nextInt(); //2
		int pawn = sc.nextInt(); //8
		
		int newking = 1-king;
		int newqueen = 1-queen;
		int newrook = 2 - rook;
		int newbishop = 2 - bishop;
		int newknight = 2 - knight;
		int newpawn = 8 - pawn;
		
		System.out.print(newking + " ");
		System.out.print(newqueen + " ");
		System.out.print(newrook + " ");
		System.out.print(newbishop + " ");
		System.out.print(newknight + " ");
		System.out.print(newpawn + " ");
		//1 0 0 0 0 1
				
	}

}