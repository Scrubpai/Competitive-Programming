import java.util.Scanner;

public class ccc05j1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		int DaytimeMinutes = sc.nextInt();
		int EveningMinutes = sc.nextInt();
		int WeekendMinutes = sc.nextInt();
		
		int DaytimeCostPlanA = (DaytimeMinutes-100) * 25;
		int DaytimeCostPlanB = (DaytimeMinutes-250) * 45;
		
		int EveningCostPlanA = EveningMinutes * 15;
		int EveningCostPlanB = EveningMinutes * 35;
		
		int WeekendCostPlanA = WeekendMinutes * 20;
		int WeekendCostPlanB = WeekendMinutes * 25;
		
		int totalPlanA = 0;
		int totalPlanB = 0;
		
		if (DaytimeMinutes <=100) {
			totalPlanA = totalPlanA + 0;
			totalPlanB = totalPlanB + 0;
		} else if (DaytimeMinutes<=250) {
			totalPlanA = DaytimeCostPlanA;
			totalPlanB = totalPlanB + 0;
		} else {
			totalPlanA = DaytimeCostPlanA;
			totalPlanB = DaytimeCostPlanB;
		}
		
		int FinalTotalPlanA = totalPlanA + EveningCostPlanA + WeekendCostPlanA;
		int FinalTotalPlanB = totalPlanB + EveningCostPlanB + WeekendCostPlanB;
		
		System.out.println("Plan A costs " + FinalTotalPlanA/100.0);
		System.out.println("Plan B costs " + FinalTotalPlanB/100.0);
		
		if (FinalTotalPlanB < FinalTotalPlanA) {
			System.out.println("Plan B is cheapest.");
		} else if (FinalTotalPlanB > FinalTotalPlanA) {
			System.out.println("Plan A is cheapest.");
		} else if (FinalTotalPlanA == FinalTotalPlanB) {
			System.out.println("Plan A and B are the same price.");
		}
		
		
		
	}

}