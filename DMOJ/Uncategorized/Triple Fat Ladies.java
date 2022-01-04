import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i=0; i<T; i++) {
			long k = sc.nextInt();
			while (true) {
				k++;
				if (k*k*k % 1000 == 888) {
					System.out.println(k);
					break;
				}
			}
		}
	}	
}