import java.util.*;
import java.io.*;
public class ccc06j3 {
	public static void main(String[] args) throws IOException {

//		String abc = "abc";
//		String def = "def";
//		String ghi = "ghi";
//		String jkl = "jkl";
//		String mno = "mno";
//		String pqrs = "pqrs";
//		String tuv = "tuv";
//		String wxyz = "wxyz";
		String alphabet = "abcdefghijklmnopqrstuvwxyz";
		//				   01234567890123456789012345
		String S = read();
		
		int count = 0;
		int lo = 0;
		int hi = 0;
				
		while (!S.equals("halt")) {
			
			count = 0;
			
			for (int i=0; i<S.length(); i++) {
				
				if (i>0) {
					if (S.charAt(i)>=lo && S.charAt(i)<=hi) {
						count+=2;
					}
				}
				
				if (S.charAt(i)>='a' && S.charAt(i)<='c') {
					lo = 97;
					hi = 99;
					count+=(S.charAt(i)-'a'+1);
				} else if (S.charAt(i)>='d' && S.charAt(i)<='f') {
					lo = 100;
					hi = 102;
					count+=(S.charAt(i)-'d'+1);
				} else if (S.charAt(i)>='g' && S.charAt(i)<='i') {
					lo = 103;
					hi = 105;
					count+=(S.charAt(i)-'g'+1);
				} else if (S.charAt(i)>='j' && S.charAt(i)<='l') {
					lo = 106;
					hi = 108;
					count+=(S.charAt(i)-'j'+1);
				} else if (S.charAt(i)>='m' && S.charAt(i)<='o') {
					lo = 109;
					hi = 111;
					count+=(S.charAt(i)-'m'+1);
				} else if (S.charAt(i)>='p' && S.charAt(i)<='s') {
					lo = 112;
					hi = 115;
					count+=(S.charAt(i)-'p'+1);
				} else if (S.charAt(i)>='t' && S.charAt(i)<='v') {
					lo = 116;
					hi = 118;
					count+=(S.charAt(i)-'t'+1);
				} else if (S.charAt(i)>='w' && S.charAt(i)<='z') {
					lo = 119;
					hi = 122;
					count+=(S.charAt(i)-'w'+1);
				}
			}
			S = read();
			System.out.println(count);
		}
		
		exit();
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static String readLine() throws IOException {
		byte[] buf = new byte[10001]; // line length
		int cnt = 0, c;
		while ((c = Read()) != -1) {
			if (c == '\n')
				break;
			buf[cnt++] = (byte) c;
		}
		return new String(buf, 0, cnt);
	}
	public static String read() throws IOException{
		byte[] ret = new byte[1024];
        int idx = 0;
        byte c = Read();
        while (c <= ' ') {
            c = Read();
        }
        do {
            ret[idx++] = c;
            c = Read();
        } while (c != -1 && c != ' ' && c != '\n' && c != '\r');
        return new String(ret, 0, idx);
	}
	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (neg)
			return -ret;
		return ret;
	}

	public static long readLong() throws IOException {
		long ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
		if (neg)
			return -ret;
		return ret;
	}

	public static double readDouble() throws IOException {
		double ret = 0, div = 1;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();

		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (c == '.') {
			while ((c = Read()) >= '0' && c <= '9') {
				ret += (c - '0') / (div *= 10);
			}
		}

		if (neg)
			return -ret;
		return ret;
	}

	private static void fillBuffer() throws IOException {
		bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
		if (bytesRead == -1)
			buffer[0] = -1;
	}

	private static byte Read() throws IOException {
		if (bufferPointer == bytesRead)
			fillBuffer();
		return buffer[bufferPointer++];
	}

	public void close() throws IOException {
		if (din == null)
			return;
		din.close();
	}

	static void print(Object o) {
		pr.print(o);
	}

	static void println(Object o) {
		pr.println(o);
	}

	static void flush() {
		pr.flush();
	}

	static void println() {
		pr.println();
	}

	static void exit() throws IOException {
		din.close();
		pr.close();
		System.exit(0);
	}
}