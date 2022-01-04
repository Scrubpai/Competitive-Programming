import java.util.*;
import java.io.*;
public class main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		HashMap<Character, Character> hm = new HashMap<>();
		hm.put('0', 'O');
		hm.put('1', 'l');
		hm.put('3', 'E');
		hm.put('4', 'A');
		hm.put('5', 'S');
		hm.put('6', 'G');
		hm.put('8', 'B');
		hm.put('9', 'g');
		String str = next();
		for (int i=0; i<str.length(); i++) {
			if (hm.containsKey(str.charAt(i))) {
				System.out.print(hm.get(str.charAt(i)));
			} else {
				System.out.print(str.charAt(i));
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