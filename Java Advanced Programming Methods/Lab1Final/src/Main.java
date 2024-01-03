import FirstPart.*;
import SecondPart.Repository.ReservationRepository;
import SecondPart.Service.ReservationRepositoryImpl;
import SecondPart.Utilities.UI;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        if (args.length < 1)
            return;
        int[] argsInt = new int[args.length];
        for (int i = 0; i < args.length; i++) {
            argsInt[i] = Integer.parseInt(args[i]);
        }

        FirstPart.Problem1 problem1 = new FirstPart.Problem1();
        FirstPart.Problem2 problem2 = new FirstPart.Problem2();
        FirstPart.Problem3 problem3 = new FirstPart.Problem3();
        //problem1.sortPrimes(argsInt);
        //System.out.println(problem2.printMaxDouble(args));
        //System.out.println(problem3.findGCD_final(argsInt));
        ReservationRepositoryImpl r1 = new ReservationRepositoryImpl();
        Scanner s1 = new Scanner(System.in);
        UI ui = new UI(r1, s1);
        ui.start();
    }
    }
