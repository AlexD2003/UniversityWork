package Service;

import Domain.Car;
import Domain.Reservation;
import Repositories.CarRepository;
import Repositories.IRepository;

public class ReservationService {
    private IRepository<Reservation> repo;

    public ReservationService(IRepository<Reservation> repo) {
        this.repo = repo;
    }

    public void addReservation(Reservation reservation){
        repo.add(reservation);
    }
    private void removeReservationById(int id){
        repo.deleteAtId(id);
    }

    private void updateAtId(int id,Reservation reservation){
        repo.updateAtId(id,reservation);
    }

    Reservation returnReservationAtId(int id){
        return repo.getById(id);
    }

}

