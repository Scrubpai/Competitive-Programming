import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		System.out.println("Ready");
		while (true) {
			String S = sc.nextLine();
			if (S.equals("  ")) {
				break;
			} else if (S.equals("bd") || S.equals("db")|| S.equals("pq")|| S.equals("qp")) {
				System.out.println("Mirrored pair");
			} else {
				System.out.println("Ordinary pair");
			}
		}
	}	
}