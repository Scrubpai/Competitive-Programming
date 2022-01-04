import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String s1 = sc.next(), s2 = sc.next();
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (s1.charAt(i) == 'C' && s2.charAt(i) == 'C') ans++;
		}
		System.out.println(ans);
	}
}