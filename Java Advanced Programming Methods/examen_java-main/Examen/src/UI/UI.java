package UI;

import Domain.BMI;
import Domain.BP;
import Domain.MedicalAnalysis;
import Repository.MedicalAnalysisRepo;
import Service.MedicalAnalysisService;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class UI {
    private MedicalAnalysisRepo repo;
    private MedicalAnalysisService service;
    private final Scanner scanner;


    public UI(MedicalAnalysisRepo repo, MedicalAnalysisService service, Scanner scanner) {
        this.repo = repo;
        this.service = service;
        this.scanner = scanner;
    }

    public void start(){
        while(true){
            System.out.println("1. Add medical analysis");
            System.out.println("2. Show all medical analysis");
            System.out.println("3.Show if the person is healthy or not");
            System.out.println("4. Exit");
            System.out.println("Your option: ");
            int option = scanner.nextInt();
            scanner.nextLine();
            if(option == 1){
                System.out.println("1. Add BP");
                System.out.println("2. Add BMI");
                System.out.println("Your option: ");
                int option2 = scanner.nextInt();
                scanner.nextLine();
                if(option2 == 1){
                    System.out.println("Date: ");
                    String date = scanner.nextLine();
                    System.out.println("Systolic: ");
                    int systolic = scanner.nextInt();
                    scanner.nextLine();
                    System.out.println("Diastolic: ");
                    int diastolic = scanner.nextInt();
                    scanner.nextLine();
                    BP bp1 = new BP(date,systolic,diastolic);
                    service.addMedicalAnalysis(bp1);
                }
                else if(option2 == 2){
                    System.out.println("Date: ");
                    String date = scanner.nextLine();
                    System.out.println("Value: ");
                    int value = scanner.nextInt();
                    scanner.nextLine();
                    BMI bmi1 = new BMI(date,value);
                    service.addMedicalAnalysis(bmi1);
                }
            }
            else if(option == 2){
                System.out.println(service.getAll());
            }
            else if(option == 3){
                System.out.println("Date: ");
                String date = scanner.nextLine();

                personIsHealthy(date);
                break;
            }
            else if(option == 4){
                break;
            }
        }
    }
    public void personIsHealthy(String date){
        Iterable<MedicalAnalysis> medicalAnalysisList = service.getAll();
        String currentMonth=subStringMonth(date,3,5);
    }
}
