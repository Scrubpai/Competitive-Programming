import java.util.Scanner;

public class ccc02j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		String arr[] = new String[100000];
		String temps;
		char tempc;
		
		for(int i = 0; i < 100000;i++) {
			arr[i] = sc.nextLine();
			if(arr[i].equals("quit!")) {
				break;
			}else if(arr[i].length() > 4) {
				temps = arr[i].substring(arr[i].length()-2, arr[i].length()-0);
				if (temps.equals("or")) {
					temps = arr[i].substring(0, arr[i].length()-2);
					tempc = arr[i].charAt(arr[i].length()-3);
					if((tempc != 'a')&&(tempc != 'e')&&(tempc != 'i')&&(tempc != 'o')&&(tempc != 'u')&&(tempc != 'y')) {
					System.out.println(temps + "our");
					}
					else {
						System.out.println(arr[i]);
					}
				} else {
					System.out.println(arr[i]);
				}
			}else {
				System.out.println(arr[i]);
			}
			
		}
	}
}