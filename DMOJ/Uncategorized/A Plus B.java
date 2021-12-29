import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for (int i=1; i<=N; i++) {
			int a = sc.nextInt(), b = sc.nextInt();
			System.out.println(a+b);
		}
	}	
}