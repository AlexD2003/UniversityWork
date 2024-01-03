package Repositories;

import Domain.Car;
import Domain.Identifiable;
import Domain.Reservation;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

//memory repository that represents both objects in a defined hashmap,storages items of type Identifiable
public class MemoryRepository<T extends Identifiable> implements IRepository {
    //hashmap def
    private Map<Integer, Identifiable> storage=new HashMap<>();
    //id
    static int id =0;

    @Override
    //def of add,get,set functions

    public void add(Identifiable item) {

        id++;
        storage.put(id,item);
    }
    public int getId(){return this.id;}
    @Override
    public Identifiable getById(int id) {
        return storage.get(id);
    }

    @Override
    public List getAll() {
        return List.copyOf(storage.values());
    }


    @Override
    public void updateAtId(int id, Identifiable updatedItem) {
        if(storage.containsKey(id)){
            storage.put(id,updatedItem);
        }
    }

    @Override
    public void deleteAtId(int id) {
        storage.remove(id);
    }


}
