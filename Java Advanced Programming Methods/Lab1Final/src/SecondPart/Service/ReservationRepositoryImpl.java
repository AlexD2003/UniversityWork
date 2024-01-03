package SecondPart.Service;

import SecondPart.Domain.Car;
import SecondPart.Domain.Reservation;
import SecondPart.Repository.ReservationRepository;

import java.util.ArrayList;
import java.util.List;

public class ReservationRepositoryImpl implements ReservationRepository {
    final private List<Reservation> reservations;
    public int returnIndex(Reservation reservation){
        int index=1;
        int indexfin=0;
        for(Reservation r:reservations){
            if(r.equals(reservation)) {
                indexfin=index;
            }
            index++;
            }
        return indexfin;
    }

    public ReservationRepositoryImpl(){ //constructor with 5 predefined values
        this.reservations=new ArrayList<>();
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
        this.reservations.add(r1);
        this.reservations.add(r2);
        this.reservations.add(r3);
        this.reservations.add(r4);
        this.reservations.add(r5);
    }
    @Override
    public void createReservation(Reservation reservation) { //method for create
        this.reservations.add(reservation);
    }

    @Override
    public void cancelReservation(int reservationId) { //method for deleting
            this.reservations.remove(reservationId);
    }
    @Override
    public Reservation returnReservationAtId(int reservationId){ //method for returning an element at index
        return this.reservations.get(reservationId);
    }
    @Override
    public List<Reservation> getAllReservations() { //return all data
        return this.reservations;
    }
    @Override
    public void updateReservationAtIndex(int index, Reservation r2){//update repo at index
        this.reservations.set(index,r2);
    }
}
