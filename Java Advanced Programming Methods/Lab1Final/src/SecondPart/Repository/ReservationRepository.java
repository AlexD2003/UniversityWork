package SecondPart.Repository;
import SecondPart.Domain.Reservation;
import java.util.List;
public interface ReservationRepository {
    int returnIndex(Reservation reservation);
    void createReservation(Reservation reservation);
    void cancelReservation(int reservationId);
    Reservation returnReservationAtId(int reservationId);

    List<Reservation> getAllReservations();

    void updateReservationAtIndex(int index, Reservation r2);
}
