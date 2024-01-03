package Repositories;

import Domain.Car;
import Domain.Identifiable;
import Domain.Reservation;

import java.util.List;

//interface of the repository that works with identifiable type objects,def of basic methods

public interface IRepository<T extends Identifiable> {
    void add(T item);
    T getById(int id);
    List<T> getAll();


    void updateAtId(int id,T updatedItem);
    void deleteAtId(int id);

}
