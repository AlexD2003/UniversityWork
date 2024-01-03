import Domain.BMI;
import Domain.BP;
import UI.UI;
import Repository.MedicalAnalysisRepo;
import Service.MedicalAnalysisService;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        MedicalAnalysisRepo repo = new MedicalAnalysisRepo();
        MedicalAnalysisService service = new MedicalAnalysisService(repo);
        Scanner scanner= new Scanner(System.in);
        UI ui = new UI( repo, service, scanner);
        ui.start();



    }
}