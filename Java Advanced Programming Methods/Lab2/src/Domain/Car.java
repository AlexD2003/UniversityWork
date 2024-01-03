package Domain;


//car class with getters,setters and defined methods
public class Car implements Identifiable{
    private String model;
    private int yearOfProduction;
    private int id;
    private static int carId=0;

    public Car(String model,int yearOfProduction) {
        this.model = model;
        this.yearOfProduction=yearOfProduction;
        this.id=generateId();
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public int getYearOfProduction() {
        return yearOfProduction;
    }

    public void setYearOfProduction(int yearOfProduction) {
        this.yearOfProduction = yearOfProduction;
    }

    @Override
    public String toString() {
        return "Car id:"+this.id+" "+"model of car='" + model + '\'' + ", yearOfProduction=" + yearOfProduction+"\n";
    }
    public String toString2() {
        return "Car id:"+this.id+" "+"model of car='" + model + '\'' + ", yearOfProduction=" + yearOfProduction;
    }
    public int generateId(){
        carId++;
        return carId;
    }
    @Override
    public int getId() {
        return this.id;
    }

    @Override
    public void setId(int Id) {
        this.id=Id;
    }
}
