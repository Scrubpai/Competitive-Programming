import java.util.Scanner;

public class ccc01j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
        int H = sc.nextInt();
		
		int i = 0, j = 0;
		
	    for (i=1;i<=H;i=i+2 ) {
	      for (j=0;j<i;j++ ) {
	    	  System.out.print("*");
	      }
	      
	      for (j=2*i;j<2*H;j++ ) {
	    	  System.out.print(" ");
	      }
	      for (j=0;j<i;j++ ) {
	    	  System.out.print("*");
	      }
	      System.out.println();
	    }
	    for (i=H-2;i>0;i=i-2 ){
	      for (j=0;j<i;j++ ) {
	    	  System.out.print("*");
	      }
	      for (j=2*i;j<2*H;j++ ){
	    	  System.out.print(" ");
	      }
	      for (j=0;j<i;j++ ) {
	    	  System.out.print("*");
	      }
	      System.out.println();
	}	    
	}
}