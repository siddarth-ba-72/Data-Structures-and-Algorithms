package bitwise.operators;

import java.util.Scanner;

public class DecimalToBinaryConversion {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter n : ");
        int n = sc.nextInt();

        int ans = 0;
        int i = 0;

        while (n != 0) {
            int bit = n & 1;
            ans = (int) ((bit * Math.pow(10, i)) + ans);
            n = n >> 1;
            i++;
        }

        System.out.println("Answer : " + ans);

        sc.close();
    }
}
