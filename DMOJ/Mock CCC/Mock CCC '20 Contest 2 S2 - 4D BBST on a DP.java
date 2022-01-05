import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
 
	public static void main(String[] args) throws IOException {
 
		int N = readInt();
		String str = next();
		LinkedList<Character> ans = new LinkedList<Character>();
		ans.add(str.charAt(0));
		for (int i=1; i<N; i++) {
			if (str.charAt(i) <= ans.getFirst()) ans.addFirst(str.charAt(i));
			else ans.addLast(str.charAt(i));
		}
		for (char c : ans) System.out.print(c);
 
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