import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), ren = sc.nextInt();
		boolean flag = true;
		for (int i=1; i<N; i++) {
			int P = sc.nextInt();
			if (P >= ren) flag = false;
		}
		if (flag) System.out.println("YES");
		else System.out.println("NO");
	}	
}