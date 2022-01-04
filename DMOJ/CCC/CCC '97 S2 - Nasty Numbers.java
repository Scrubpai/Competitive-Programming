import java.util.*;
import java.io.*;
public class ccc97s2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {

		int n = readInt();
		for (int i=0; i<n; i++) {
			int x = readInt(); int a, b, c, d = 0; boolean flag = false;
			for (int j=1; j<=Math.sqrt(x) && !flag; j++) {
				if (x%j==0) { 
					a = j; b = x/j; 
					for (int k=1; k<=Math.sqrt(x); k++) {
						if (j!=k && x%k==0) { 
							c = k; d = x/k;
							if (Math.abs(b-a)==c+d || Math.abs(d-c)==b+a) flag = true;
						}
					}
				}
			}
			if (flag) System.out.println(x + " is nasty");
			else System.out.println(x + " is not nasty");
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