package Service;

import Domain.Car;
import Repositories.CarRepository;
import Repositories.IRepository;

public class CarService {
    private IRepository<Car> repo;

    public CarService(IRepository<Car> repo) {
        this.repo = repo;
    }

    public void addCar(Car car){
        repo.add(car);
    }
    private void removeCarById(int id){
        repo.deleteAtId(id);
    }

    private void updateAtId(int id,Car car){
        repo.updateAtId(id,car);
    }

    Car returnCarAtId(int id){
        return repo.getById(id);
    }

    }

