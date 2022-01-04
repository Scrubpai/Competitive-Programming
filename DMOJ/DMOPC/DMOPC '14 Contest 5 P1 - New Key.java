import java.util.*;
import java.io.*;
public class dmopc14c4p1 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		
		String S = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		String A = readLine(); String ans = "";
		
		for (int i=0; i<A.length(); i++) {
			int idx = S.indexOf(A.charAt(i)); idx+=9;
			ans += S.charAt(idx);
		}
		
		System.out.println(ans);
	
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