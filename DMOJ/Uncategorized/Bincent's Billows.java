import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
 
	public static void main(String[] args) throws IOException {

		int F = readInt();
		while (F-- > 0) {
			int N = readInt(), ans = 0;
			int a[] = new int[N], b[] = new int[N];
			for (int i=0; i<N; i++) a[i] = readInt();
			for (int i=0; i<N; i++) { b[i] = readInt(); ans += a[i]*b[i]; }
			System.out.println(ans);
		}
		
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