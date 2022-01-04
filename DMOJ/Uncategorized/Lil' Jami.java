import java.util.*;
import java.io.*;
public class main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int N = readInt(), K = readInt();
		int psa[] = new int[N+1];
		for (int i=0; i<K; i++) {
			int k = readInt();
			psa[k+1]++;
		}
		for (int i=1; i<=N; i++) {
			//Construct the prefix sum array
			psa[i] = psa[i] + psa[i-1];
		}
		int Q = readInt();
		for (int i=0; i<Q; i++) {
			int a = readInt(), b = readInt();
			a++; b++;
			System.out.println(psa[b] - psa[a-1]);
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