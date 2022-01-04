import java.util.*;
import java.io.*;
public class main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int desks[], N, M;
	static boolean chk(long T) {
		long tot = 0;
		for (int i=1; i<desks.length; i++) {
			tot += T/desks[i];
		}
		return tot >= M;
	}
	public static void main(String[] args) throws IOException {
		N = readInt(); M = readInt();
		desks = new int[N+1];
		for (int i=1; i<=N; i++) {
			desks[i] = readInt();
		}
		long lo = 1, hi = (long)1e18, ans = (long)1e18;
		while (lo <= hi) {
			long mid = (lo+hi)/2;
			if (chk(mid)) {
				hi = mid-1;
				ans = Math.min(ans, mid);
			}
			else lo = mid+1;
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