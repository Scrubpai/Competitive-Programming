import java.util.*;
import java.io.*;
public class vmss7wc15c2p1 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		
		int N = readInt(); int arr[] = new int[N];
		for (int i=0; i<N; i++) arr[i] = readInt();
		
		if (N==1) {
			if (arr[0]<=41) { System.out.println(1); return; }
			else { System.out.println(0); return; }
		}
		
		int cnt = 0;
		for (int i=0; i<N; i++) {
			if (i==0) {
				if (arr[i]<=41 && arr[i+1]<=41) cnt++;
				continue;
			} else if (i==N-1) {
				if (arr[i]<=41 && arr[i-1]<=41) cnt++;
				continue;
			} else {
				if (arr[i]<=41 && arr[i-1]<=41 && arr[i+1]<=41) cnt++;
			}
		}
		System.out.println(cnt);
	
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