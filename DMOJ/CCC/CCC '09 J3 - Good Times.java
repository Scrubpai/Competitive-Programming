import java.util.*;
public class ccc09_j3_goodtimes {
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		fun(t, "Ottawa");
		fun(t-300, "Victoria");
		fun(t-200, "Edmonton");
		fun(t-100, "Winnipeg");
		fun(t, "Toronto");
		fun(t+100, "Halifax");
		fun(t+130, "St. John's");
	}
	public static void fun(int t, String city){
		if(t < 0) t += 2400;
		int minute = t % 100, hour = t / 100;
		if(minute >= 60) { hour += minute/60; minute %= 60; }
		if(hour >= 24) hour -= 24;
		t = hour*100 + minute;
		System.out.println(t+" in "+city);
	}
}