import java.util.*;
import java.io.*;
public class dmopc14c4p2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		
		int N = readInt(); int arr[] = new int[N];
		for (int i=0; i<N; i++) {
			String x = readLine();
			arr[i] = x.length();
		}
		int M = readInt(); int c[] = new int[M+1];
		for (int i=0; i<N; i++) {
			int idx = 1;
			for (int j=1; j<=M; j++) {
				if (c[j]<c[idx]) idx = j;
			}
			c[idx] += arr[i];
			System.out.println(idx);
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