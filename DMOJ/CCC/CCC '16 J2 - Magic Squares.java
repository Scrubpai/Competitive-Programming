import java.util.Scanner;

public class ccc16j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		double a = sc.nextDouble();
		double a1 = sc.nextDouble();
		double a2 = sc.nextDouble();
		double a3 = sc.nextDouble();
		double b = sc.nextDouble();
		double b1 = sc.nextDouble();
		double b2 = sc.nextDouble();
		double b3 = sc.nextDouble();
		double c = sc.nextDouble();
		double c1 = sc.nextDouble();
		double c2 = sc.nextDouble();
		double c3 = sc.nextDouble();
		double d = sc.nextDouble();
		double d1 = sc.nextDouble();
		double d2 = sc.nextDouble();
		double d3 = sc.nextDouble();
		
		int a4 = (int) ((int)a+a1+a2+a3);
		int b4 = (int) ((int)b+b1+b2+b3);
		int c4 = (int) ((int)c+c1+c2+c3);
		int d4 = (int) ((int)d+d1+d2+d3);
		
		int col =(int)((int)a1+b1+c1+d1);
		int col1 =(int)((int)a2+b2+c2+d2);
		int col2 =(int)((int)a3+b3+c3+d3);
		int col3 =(int)((int)a+b+c+d);
		
		if(a4==b4&&a4==c4&&a4==d4&&a4==col&&a4==col1&&a4==col2&&a4==col3) {
			System.out.println("magic");
		}
		else {
			System.out.println("not magic");}
		
	}

}