import java.util.*;
import java.io.*;

public class main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int lmt = sc.nextInt();
		int spd = sc.nextInt();
		int over = spd - lmt;
		
		if (over >= 1 && over <= 20) {
			System.out.println("You are speeding and your fine is $" + 100 + ".");
		} else if (over >= 21 && over <= 30) {
			System.out.println("You are speeding and your fine is $" + 270 + ".");
		} else if (over >= 31) {
			System.out.println("You are speeding and your fine is $" + 500 + ".");
		} else {
			System.out.println("Congratulations, you are within the speed limit!");
		}
	}
}