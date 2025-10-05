package bitwise.operators;

import java.util.Scanner;

public class BinaryToDecimal {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter Binary: ");
        int n = sc.nextInt();

        int i = 0;
        int ans = 0;

        while (n != 0) {
            int bit = n % 10;
            if (bit == 1) {
                ans += (int) Math.pow(2, i);
            }
            n /= 10;
            i++;
        }

        System.out.println("Answer decimal: " + ans);

        sc.close();
    }
}