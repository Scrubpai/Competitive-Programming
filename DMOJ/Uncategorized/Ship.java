import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		ArrayList<Character> list = new ArrayList();
		list.add('B'); list.add('F'); list.add('T'); list.add('L'); list.add('C');
		for (int i=0; i<S.length(); i++) {
			if (list.contains(S.charAt(i))) list.remove(list.indexOf(S.charAt(i)));
		}
		if (list.isEmpty()) System.out.println("NO MISSING PARTS");
		else {
			for (int i=0; i<list.size(); i++) {
				System.out.println(list.get(i));
			}
		}
	}	
}