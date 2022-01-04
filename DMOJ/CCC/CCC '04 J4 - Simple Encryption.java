import java.util.*;
import java.io.*;
public class ccc04j4 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {

		String key = read();  String S = readLine().replaceAll(" ", "");
		for (int i=0; i<S.length(); i++) {
			char c = S.charAt(i); if (c<65 || c>90) {
				String x = S.substring(i, i+1);
				S = S.replace(x, "");
			}
		}		
		String ans = "";

		for (int i=0; i<S.length(); i++) {
			char c = S.charAt(i); if (c<65 || c>90) continue;

			c += key.charAt(i%key.length())-65;
			if (c>90) c-=26;

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
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}