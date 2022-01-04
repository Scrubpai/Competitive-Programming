import java.util.Scanner;

public class ccc08j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		double Weight = sc.nextDouble();
		double Height = sc.nextDouble();
		
		double BMI = Weight/(Height*Height);
		
		if (BMI>25) {
			System.out.println("Overweight");
		} else if (BMI>=18.5 && BMI<=25) {
			System.out.println("Normal weight");
		} else if (BMI<18.5) {
			System.out.println("Underweight");
		}
		
	}

}