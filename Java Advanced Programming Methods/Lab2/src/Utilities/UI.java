package Utilities;

import Domain.Car;
import Domain.Identifiable;
import Domain.Reservation;
import Repositories.MemoryRepository;
import Service.CarService;
import Service.ReservationService;

import java.util.Scanner;

//basic UI layout with some exception handling
public class UI {
    private final MemoryRepository<Identifiable> repository;
    private final CarService carService;
    private final ReservationService reservationService;

    private final Scanner scanner;

    public UI(MemoryRepository<Identifiable> repository, CarService carService, ReservationService reservationService, Scanner scanner) {
        this.repository=repository;
        this.carService = carService;
        this.reservationService = reservationService;
        this.scanner = scanner;
    }

    public void start(){
        while(true){
            System.out.println("Car rental service:");
            System.out.println("0.Load with predefined values:");
            System.out.println("1.Create a car and add it:");
            System.out.println("2.Create a reservation and add it:");
            System.out.println("3.Print all cars:");
            System.out.println("4.Print all reservations:");
            System.out.println("5.Print everything:");
            System.out.println("6.Remove at id:");
            System.out.println("7.Update at id:");
            System.out.println("8.Get at id:");
            System.out.println("10.Exit:");
            System.out.println("Enter your choice:");
            int choice=scanner.nextInt();
            scanner.nextLine();
            switch (choice){
                case 0:
                    loadValues();
                    break;
                case 1:
                    createCar();
                    break;
                case 2:
                    createReservation();
                    break;
                case 3:
                    //printAllCars();
                    break;
                case 4:
                    //printAllReservations();
                    break;
                case 5:
                    printEverything();
                    break;
                case 6:
                    removeAtId();
                    break;
                case 7:
                    updateAtId();
                    break;
                case 8:
                    getAtId();
                    break;
                case 10:
                    System.out.println("bb");
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }

        }

    }
    public void createCar(){
        System.out.println("Car model:");
        String carModel=scanner.nextLine();
        System.out.println("Car year of production:");
        int year=scanner.nextInt();
        scanner.nextLine();
        if(year<=0){
            throw new IllegalArgumentException("Year out of range!");
        }
        Car car=new Car(carModel,year);
        carService.addCar(car);
    }
    public void createReservation(){
        System.out.println("Car model:");
        String carModel=scanner.nextLine();
        System.out.println("Car year of production:");
        int year=scanner.nextInt();
        scanner.nextLine();
        if(year<=0){
            throw new IllegalArgumentException("Year out of range!");
        }
        Car car=new Car(carModel,year);
        System.out.println("Customer name:");
        String customerName=scanner.nextLine();
        System.out.println("Start date:");
        String startDate=scanner.nextLine();
        System.out.println("End date:");
        String endDate=scanner.nextLine();
        Reservation reservation=new Reservation(car,customerName,startDate,endDate);
        repository.add(reservation);
    }

    public void removeAtId(){
        System.out.println("Desired Id:");
        int id= scanner.nextInt();
        scanner.nextLine();
        if(id>repository.getId() || id<0){
            throw new IllegalArgumentException("Id out of range!");
        }
        repository.deleteAtId(id);
        System.out.println("Removal successful");
    }
    public void printEverything(){
        System.out.println(repository.getAll());
    }
    public void updateAtId(){
        System.out.println("Desired Id:");
        int id=scanner.nextInt();
        scanner.nextLine();
        if(id>repository.getId() || id<0){
            throw new IllegalArgumentException("Id out of range!");
        }
        if(repository.getById(id) instanceof Car){
            int carId=repository.getById(id).getId();
            System.out.println("Car model:");
            String carModel=scanner.nextLine();
            System.out.println("Car year of production:");
            int year=scanner.nextInt();
            scanner.nextLine();
            Car car=new Car(carModel,year);
            car.setId(carId);
            repository.updateAtId(id,car);
        } else if (repository.getById(id) instanceof Reservation) {
            int reservationId=repository.getById(id).getId();
            System.out.println("Car model:");
            String carModel=scanner.nextLine();
            System.out.println("Car year of production:");
            int year=scanner.nextInt();
            scanner.nextLine();
            Car car=new Car(carModel,year);
            System.out.println("Customer name:");
            String customerName=scanner.nextLine();
            System.out.println("Start date:");
            String startDate=scanner.nextLine();
            System.out.println("End date:");
            String endDate=scanner.nextLine();
            Reservation reservation=new Reservation(car,customerName,startDate,endDate);
            reservation.setId(reservationId);
            repository.updateAtId(id,reservation);
        }
        System.out.println("Update successful!");
    }
    public void getAtId(){
        System.out.println("Desired id:");
        int id=scanner.nextInt();
        scanner.nextLine();
        if(id>repository.getId() || id<0){
            throw new IllegalArgumentException("Id out of range!");
        }
        System.out.println(repository.getById(id));
    }
    public void loadValues(){
        Car car1=new Car("Opel",1);
        Car car2=new Car("Audi",2);
        Car car3=new Car("Bmw",3);
        Car car4=new Car("Volkswagen",4);
        Car car5=new Car("Mazda",5);
        Reservation r1=new Reservation(car1,"Alex","Iunie 02","Iulie 04");
        Reservation r2=new Reservation(car2,"Irina","Iunie 02","Iulie 04");
        Reservation r3=new Reservation(car3,"Ioan","Iunie 02","Iulie 04");
        Reservation r4=new Reservation(car4,"Silviu","Iunie 02","Iulie 04");
        Reservation r5=new Reservation(car5,"Amanda","Iunie 02","Iulie 04");
        repository.add(car1);
        repository.add(car2);
        repository.add(car3);
        repository.add(car4);
        repository.add(car5);
        repository.add(r1);
        repository.add(r2);
        repository.add(r3);
        repository.add(r4);
        repository.add(r5);
    }

}

