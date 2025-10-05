package bitwise.operators.questions;

import java.util.Scanner;

public class BitwiseComplement {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter n : ");
        int n = sc.nextInt();

        int ans = bitwiseComplement(n);
        System.out.println("Bitwise Complement: " + ans);

        sc.close();
    }

    public static int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }

        int ans = 0;
        int i = 0;

        while (n != 0) {
            int bit = n & 1;
            if (bit == 0) {
                ans += (int) Math.pow(2, i);
            }
            n = n >> 1;
            i++;
        }

        return ans;
    }
}