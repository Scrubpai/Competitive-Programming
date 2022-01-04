import java.util.*;
import java.io.*;
public class ccc12j4 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {

		int K = readInt(); String str = read(); String ans = "";
		for (int i=0; i<str.length(); i++) {
			char c = str.charAt(i); c-= (3*(i+1) + K); if (c<65) c+=26;
			ans+=c;
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
	static String read () throws IOException {
		return br.readLine().trim();
	}
}