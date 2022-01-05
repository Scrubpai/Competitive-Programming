import java.util.*;
import java.io.*;
public class gfssoc1j2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		
		int N = readInt(), x = 0, y = 0;
		for (int i=0; i<N; i++) {
			String S = readLine();
			if (S.equals("North")) {
				int m = readInt();
				y+=m;
			} else if (S.equals("South")) {
				int m = readInt();
				y-=m;
			} else if (S.equals("East")) {
				int m = readInt();
				x+=m;
			} else {
				int m = readInt();
				x-=m;
			}
		}
		
		System.out.println(x + " " + y);
	
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