import java.util.Arrays;
import java.util.Scanner;

public class dmopc14c1p2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int length = sc.nextInt();
		int width = sc.nextInt();
		int tilelength = sc.nextInt();
		
		int a = length/tilelength;
		int b = width/tilelength;
		
		int c = a*b;
		
		System.out.println(c);
			
		
	}

}