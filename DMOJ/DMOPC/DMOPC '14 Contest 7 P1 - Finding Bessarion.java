import java.util.*;
import java.io.*;
public class BufferReaderTemplate {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		
		int N = readInt(); String arr[] = new String[N]; int idx = 0;
		for (int i=0; i<N; i++) {
			arr[i] = readLine(); if (arr[i].equals("Bessarion")) idx = i;
		}
		if (N<=2) { System.out.println("N"); return; }
		if (idx==0 || idx==N-1) { System.out.println("N"); return; }
		else {
			if ((arr[idx-1].equals("Bayview") && arr[idx+1].equals("Leslie")) || (arr[idx-1].equals("Leslie") && arr[idx+1].equals("Bayview"))) System.out.println("Y");
			else System.out.println("N");
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