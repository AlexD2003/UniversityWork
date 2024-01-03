package SecondPart.Domain;

public class Car {
    private String model;
    private int yearOfProduction;

    public Car(String model,int yearOfProduction) {
        this.model = model;
        this.yearOfProduction=yearOfProduction;
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
        return
                "model of car='" + model + '\'' +
                ", yearOfProduction=" + yearOfProduction ;
    }
}

