import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
		if (b >= a && c >= b) System.out.println("Good job!");
		else System.out.println("Try again!");
	}	
}