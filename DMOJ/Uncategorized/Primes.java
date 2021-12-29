import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
 
	public static void main(String[] args) throws IOException {

		int N = readInt(), cnt = 0;
		for (int i=2; cnt<N; i++) {
			boolean flag = true;
			for (int j=2; j<i; j++) {
				if (i % j == 0) {
					flag = false;
					break;
				}
			}
			//if flag is true, then current number has no factors
			if (flag) {
				cnt++;
				System.out.println(i);
			}
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