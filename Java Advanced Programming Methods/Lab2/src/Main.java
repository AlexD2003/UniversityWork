import Domain.Identifiable;
import Repositories.MemoryRepository;
import Service.CarService;
import Service.ReservationService;
import Utilities.UI;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        MemoryRepository<Identifiable> repository=new MemoryRepository<>();
        Scanner scanner=new Scanner(System.in);
        CarService carService;
        carService = null;
        ReservationService reservationService;
        reservationService = null;
        UI ui=new UI(repository, carService, reservationService, scanner);
        ui.start();

    }
}
