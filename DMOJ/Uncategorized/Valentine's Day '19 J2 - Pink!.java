import java.util.Scanner;

public class valentines19j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int count = sc.nextInt();
		int count2 = 0;
		
		for (int i=0; i<count; i++) {
			int red = sc.nextInt();
			int green = sc.nextInt();
			int blue = sc.nextInt();
			
			if ((red >= 240 & red <= 255) & (green >=0 & green<=200) & (blue >=95 & blue <=220)) {
				count2++;
			}
		}
		
		System.out.println(count2);
		
	}

}