import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt(); 
		ArrayList<Integer> arr = new ArrayList();
		while (T-- > 0) {
			int N = sc.nextInt();
			arr.clear();
			for (int i=0; i<N; i++) {
				arr.add(sc.nextInt());
			}
			Collections.sort(arr);
			System.out.println(arr.get(N-1));
		}
	}	
}