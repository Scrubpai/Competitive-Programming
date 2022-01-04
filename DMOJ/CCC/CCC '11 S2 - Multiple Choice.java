import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException {
    	Scanner sc = new Scanner(System.in);
    	int N = sc.nextInt();
    	ArrayList<String> A1 = new ArrayList();
    	ArrayList<String> A2 = new ArrayList();
    	for (int i = 0; i < N; i++) {
    		String S = sc.next();
    		A1.add(S);
    	}
    	for (int i = 0; i < N; i++) {
    		String S = sc.next();
    		A2.add(S);
    	}
    	int ans = 0;
    	for (int i = 0; i < N; i++) {
    		if (A1.get(i).equals(A2.get(i))) ans++;
    	}
    	System.out.println(ans);
    }
}