import java.util.*;
import java.io.*;
public class vmss7wc15c5p1 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	
	static class Test {
		int score, total; double weight;
		Test(int score0, int total0, double weight0) {
			score = score0; total = total0; weight = weight0;
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		String S = readLine(); Test arr[] = new Test[4]; int idx = -1; double W = -1;
		for (int i=0; i<4; i++) {
			int s = readInt(), t = readInt(); double w = readDouble(); 
			arr[i] = new Test(s, t, w);
			if (w>W) { idx = i; W = w; }
		}
		
		if (S.equals("trees!")) arr[idx].score = arr[idx].total;
		else arr[idx].score=0;
			
		double tot = 0;
		for (int i=0; i<4; i++) {
			double w = (double)arr[i].weight; 
			double x = (double) arr[i].score; double y = (double) arr[i].total; x/=y; x*=100; x*=w;
			tot +=x; 
		}
		
		System.out.printf("%.0f", tot);
		System.out.println();
		
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