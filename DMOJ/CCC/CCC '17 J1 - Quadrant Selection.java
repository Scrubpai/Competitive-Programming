import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt(), y = sc.nextInt();
		if (x > 0 && y > 0) System.out.println(1);
		else if (x < 0 && y > 0) System.out.println(2);
		else if (x < 0 && y < 0) System.out.println(3);
		else System.out.println(4);
	}
}