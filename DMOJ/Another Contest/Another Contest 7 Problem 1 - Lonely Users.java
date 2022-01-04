import java.util.*;
import java.io.*;

public class main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for (int i=0; i<T; i++) {
			int N = sc.nextInt();
			if (N == 2) {
				System.out.println(N);
			} else {
				System.out.println(N-1);
			}
		}
	}
}