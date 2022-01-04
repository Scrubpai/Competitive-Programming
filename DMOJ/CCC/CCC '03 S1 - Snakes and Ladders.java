import java.util.*;
import java.io.*;
public class ccc03s1 {
	public static void main(String[] args) throws IOException {

		int N = readInt();
		int pos = 1;

		while (N!=0) {
			pos+=N;
			if (pos>100) {
				pos-=N;
			}
			if (pos==9) {
				pos = 34;
				System.out.println("You are now on square 34");
				N = readInt();
				continue;
			} else if (pos==40) {
				pos=64;
				System.out.println("You are now on square 64");
				N = readInt();
				continue;
			} else if (pos==67) {
				pos=86;
				System.out.println("You are now on square 86");
				N = readInt();
				continue;
			} else if (pos==54) {
				pos=19;
				System.out.println("You are now on square 19");
				N = readInt();
				continue;
			} else if (pos==90) {
				pos=48;
				System.out.println("You are now on square 48");
				N = readInt();
				continue;
			} else if (pos==99) {
				pos=77;
				System.out.println("You are now on square 77");
				N = readInt();
				continue;
			} else if (pos==100) {
				System.out.println("You are now on square 100");
				System.out.println("You Win!");
				return;
			}
			System.out.println("You are now on square " + pos);
			N = readInt();
		}
		System.out.println("You Quit!");

		exit();
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static String readLine() throws IOException {
		byte[] buf = new byte[64]; // line length
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