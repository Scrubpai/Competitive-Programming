import java.util.Scanner;

public class dmpg19b4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);

		String S = sc.nextLine();

		String arr[] = new String[43];

		arr[17] = "o....."; 	//start at 17 for ascii table --> A = 65, and 0 = 48. 65-48 = 17.
		arr[18] = "o.o...";
		arr[19] = "oo....";
		arr[20] = "oo.o..";
		arr[21] = "o..o..";
		arr[22] = "ooo...";
		arr[23] = "oooo..";
		arr[24] = "o.oo..";
		arr[25] = ".oo...";
		arr[26] = ".ooo..";
		arr[27] = "o...o.";
		arr[28] = "o.o.o.";
		arr[29] = "oo..o.";
		arr[30] = "oo.oo.";
		arr[31] = "o..oo.";
		arr[32] = "ooo.o.";
		arr[33] = "ooooo.";
		arr[34] = "o.ooo.";
		arr[35] = ".oo.o.";
		arr[36] = ".oooo.";
		arr[37] = "o...oo";
		arr[38] = "o.o.oo";
		arr[39] = ".ooo.o";
		arr[40] = "oo..oo";
		arr[41] = "oo.ooo";
		arr[42] = "o..ooo";


		String line1 = "", line2 = "", line3 = "";

		for (int i=0; i<S.length(); i++) {
			if(S.charAt(i)== ' ') {
				line1 += "..";
				line2 += "..";
				line3 += "..";
			} else {
				line1 += arr[S.charAt(i)-'0'].substring(0, 2);
				line2 += arr[S.charAt(i)-'0'].substring(2, 4);
				line3 += arr[S.charAt(i)-'0'].substring(4,6);}
		}

		System.out.println(line1);
		System.out.println(line2);
		System.out.println(line3);

	}

}