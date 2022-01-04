import java.util.*;
import java.io.*;
public class ccc08j3 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	
	static class Pair {
		int x; int y;
		Pair (int x0, int y0) {
			x = x0; y = y0;
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		Map<Character, Pair> hm = new HashMap();
		hm.put('A', new Pair(1, 1)); hm.put('B', new Pair(1, 2)); hm.put('C', new Pair(1, 3)); hm.put('D', new Pair(1, 4));
		hm.put('E', new Pair(1, 5)); hm.put('F', new Pair(1, 6)); hm.put('G', new Pair(2, 1)); hm.put('H', new Pair(2, 2));
		hm.put('I', new Pair(2, 3)); hm.put('J', new Pair(2, 4)); hm.put('K', new Pair(2, 5)); hm.put('L', new Pair(2, 6));
		hm.put('M', new Pair(3, 1)); hm.put('N', new Pair(3, 2)); hm.put('O', new Pair(3, 3)); hm.put('P', new Pair(3, 4));
		hm.put('Q', new Pair(3, 5)); hm.put('R', new Pair(3, 6)); hm.put('S', new Pair(4, 1)); hm.put('T', new Pair(4, 2));
		hm.put('U', new Pair(4, 3)); hm.put('V', new Pair(4, 4)); hm.put('W', new Pair(4, 5)); hm.put('X', new Pair(4, 6));
		hm.put('Y', new Pair(5, 1)); hm.put('Z', new Pair(5, 2)); hm.put(' ', new Pair(5, 3)); hm.put('-', new Pair(5, 4));
		hm.put('.', new Pair(5, 5));
		
		String S = read(); int tot = 0; int curx = 1; int cury = 1;
		for (int i=0; i<S.length(); i++) {
			int a = hm.get(S.charAt(i)).x; int b = hm.get(S.charAt(i)).y;
			tot += Math.abs(b-cury) + Math.abs(a-curx);
			curx = a; cury = b;
		}
		
		tot += Math.abs(6-curx) + Math.abs(6-cury);
		
		System.out.println(tot-1);
	
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
	static String read() throws IOException {
		return br.readLine().trim();
	}
}