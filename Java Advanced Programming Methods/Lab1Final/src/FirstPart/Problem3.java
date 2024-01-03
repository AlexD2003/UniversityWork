package FirstPart;

public class Problem3 {
    public static int findGCD_final(int[] numbers) {
        if (numbers.length < 2) {
            throw new RuntimeException("Need 2 numbers at least!");
        }

        int gcd = numbers[0];
        for (int i = 1; i < numbers.length; i++) {
            gcd = findGCD(gcd, numbers[i]);
        }

        return gcd;
    }
    public static int findGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return findGCD(b, a % b);
    }
}