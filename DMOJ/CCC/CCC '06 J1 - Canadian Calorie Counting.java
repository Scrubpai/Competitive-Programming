import java.util.Scanner;

public class ccc06j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int burger = sc.nextInt();
		int side = sc.nextInt();
		int drink = sc.nextInt();
		int dessert = sc.nextInt();
		
		int calorie;
		
		if (burger == 1) calorie = 461;
		else if (burger == 2) calorie = 431 ;
		else if (burger == 3) calorie = 420 ;
		else calorie = 0 ;

		if (side == 1) calorie = calorie + 100 ;
		else if (side == 2) calorie = calorie + 57 ;
		else if (side == 3) calorie = calorie + 70 ;
		else calorie = calorie + 0 ;

		if (drink == 1) calorie = calorie + 130 ;
		else if (drink == 2) calorie = calorie + 160 ;
		else if (drink == 3) calorie = calorie + 118 ;
		else calorie = calorie + 0 ;

		if (dessert == 1) calorie = calorie + 167 ;
		else if (dessert == 2) calorie = calorie + 266 ;
		else if (dessert == 3) calorie = calorie + 75 ;
		else calorie = calorie + 0 ;

		System.out.println("Your total Calorie count is " + calorie + ".") ;
		
	}

}