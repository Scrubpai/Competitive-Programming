import java.util.*;
import java.io.*;
public class si17c1p9 {
	public static void main(String[] args) throws IOException {

		int r = readInt();
		int c = readInt();
		char arr[][] = new char[r+1][c+1];

		for (int i=0; i<r; i++) {
			String s = read();
			arr[i]=s.toCharArray();
		}

		int cnt = 0;
		int moveR[] = new int[9];
		moveR[0] = -1;
		moveR[1] = -1;
		moveR[2]= -1;
		moveR[3] = 0;
		moveR[4] = 0;
		moveR[5] = 1;
		moveR[6] = 1;
		moveR[7] = 1;
		int moveC[] = new int[9];
		moveC[0] = -1;
		moveC[1] = 0;
		moveC[2] = 1;
		moveC[3] = -1;
		moveC[4] = 1;
		moveC[5] = -1;
		moveC[6] = 0;
		moveC[7] = 1;

		for (int i=0; i<r; i++) {
			for (int j=0 ;j<c; j++) {
				int emptyspots = 0;
				int snakespots = 0;
				if (arr[i][j] == 'S') {
					continue;
				} else {
					for (int k=0; k<8; k++) {
						if (i+moveR[k]>=0 && i+moveR[k]<r && j+moveC[k]>=0 && j+moveC[k]<c && arr[i+moveR[k]][j+moveC[k]]=='S') {
							snakespots++;
						} else if (i+moveR[k]>=0 && i+moveR[k]<r && j+moveC[k]>=0 && j+moveC[k]<c && arr[i+moveR[k]][j+moveC[k]]!='S'){
							emptyspots++;
						}
					}
				}
				if (emptyspots>snakespots) cnt++;
			}
		}

		System.out.println(cnt);

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