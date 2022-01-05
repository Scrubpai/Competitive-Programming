import java.util.*;
import java.io.*;
public class vmss7wc15c1p1 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		
		String S = readLine();
		
		int A = Integer.parseInt(S.substring(0, 1)) + Integer.parseInt(S.substring(1, 2)) + Integer.parseInt(S.substring(2, 3));
		int B = Integer.parseInt(S.substring(4, 5)) + Integer.parseInt(S.substring(5, 6)) + Integer.parseInt(S.substring(6, 7));
		int C = Integer.parseInt(S.substring(8, 9)) + Integer.parseInt(S.substring(9, 10)) + Integer.parseInt(S.substring(10, 11)) + Integer.parseInt(S.substring(11, 12));
		if (A==B && B==C) System.out.println("Goony!");
		else System.out.println("Pick up the phone!");
	
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}