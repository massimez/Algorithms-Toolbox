import java.util.Scanner;

public class Change {
    private static int getChange(int m) {
        //write your code here
        int coins[] = {10, 5, 1} ;
		int count = 0;
		for (int coin : coins) {
			count +=  Math.floorDiv(m,coin);
			m %= coin;
		}
        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        System.out.println(getChange(m));

    }
}

