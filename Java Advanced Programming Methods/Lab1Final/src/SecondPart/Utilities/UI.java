package SecondPart.Utilities;

import SecondPart.Domain.Car;
import SecondPart.Domain.Reservation;
import SecondPart.Repository.ReservationRepository;
import SecondPart.Service.ReservationRepositoryImpl;

import javax.print.attribute.standard.PresentationDirection;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class UI { //ui layout with initializations
    private final ReservationRepositoryImpl reservationService;
    private final Scanner scanner;

    public UI(ReservationRepositoryImpl reservationService,Scanner scanner){
        this.reservationService=reservationService;
        this.scanner=scanner;
    }
    public void start(){
        while(true){
            System.out.println("Car rental service:");
            System.out.println("1.Create a reservation:");
            System.out.println("2.Cancel a reservation:");
            System.out.println("3.Print all reservations:");
            System.out.println("4.Update reservation at index:");
            System.out.println("5.Exit");

            System.out.println("Enter your choice:");
            int choice = scanner.nextInt();
            scanner.nextLine();
            switch (choice){
                case 1:
                    createReservation();
                    break;
                case 2:
                    cancelReservation();
                    break;
                case 3:
                    printAllReservations();
                    break;
                case 4:
                    updateAtIndex();
                    break;
                case 5:
                    System.out.println("Exiting!");
                    return;
                default:
                    System.out.println("Incorrect value or format entered!");

            }
        }
    }
    //methods for each selection in UI that utilize the functions prezent in service |
    //                                                                               ↓
    private void createReservation(){
        System.out.println("Enter car model:");
        String carModel=scanner.nextLine();
        System.out.println("Enter car year of production:");
        int yearOfProduction= scanner.nextInt();
        scanner.nextLine();
        Car c1=new Car(carModel,yearOfProduction);
        System.out.println("Enter your name:");
        String customerName=scanner.nextLine();
        System.out.println("Enter start date of rental:");
        String startDate=scanner.nextLine();
        System.out.println("Enter end date of rental:");
        String endDate=scanner.nextLine();
        Reservation r1=new Reservation(c1,customerName,startDate,endDate);
        this.reservationService.createReservation(r1);
        System.out.println("Reservation made successfully!");
    }
    private void cancelReservation(){
        System.out.println("Enter id of the reservation you wish to cancel:");
        int cancelId= scanner.nextInt();
        scanner.nextLine();
        this.reservationService.cancelReservation(cancelId);
        System.out.println("Cancellation made successfuly!");
    }
    private void printAllReservations(){
        List<Reservation> l1=this.reservationService.getAllReservations();
        for(Reservation r1:l1){
            System.out.println("Car id:"+reservationService.returnIndex(r1) +" "+r1.toString());
        }

    }
    private void updateAtIndex(){
        System.out.println("Id to update:");
        int index=scanner.nextInt();
        scanner.nextLine();
        Reservation reservationForUpdate=this.reservationService.returnReservationAtId(index-1);
        System.out.println("Want to change the car? 1-yes / 2-no");
        int choice1= scanner.nextInt();
        scanner.nextLine();
        if(choice1==1){
            System.out.println("Model:");
            String model1=scanner.nextLine();
            System.out.println("Year of production:");
            int year1=scanner.nextInt();
            scanner.nextLine();
            Car changedCar=new Car(model1,year1);
            reservationForUpdate.setCar(changedCar);
        }
            System.out.println("Customer name:");
            String customerName=scanner.nextLine();
            System.out.println("Start date:");
            String startDate=scanner.nextLine();
            System.out.println("End date:");
            String endDate=scanner.nextLine();
            reservationForUpdate.setCustomerName(customerName);
            reservationForUpdate.setStartDate(startDate);
            reservationForUpdate.setEndDate(endDate);
            this.reservationService.updateReservationAtIndex(index-1,reservationForUpdate);
            System.out.println("Change succesful!");



    }
}


