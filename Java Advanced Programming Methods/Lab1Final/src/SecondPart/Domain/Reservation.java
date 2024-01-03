package SecondPart.Domain;

public class Reservation {
    private Car car;

    public Reservation(Car car, String customerName, String startDate, String endDate) {
        this.car = car;
        this.customerName = customerName;
        this.startDate = startDate;
        this.endDate = endDate;
    }


    private String customerName;

    private String startDate;
    private String endDate;


    public Car getCar() {
        return car;
    }

    public void setCar(Car car) {
        this.car = car;
    }

    public String getCustomerName() {
        return customerName;
    }

    public void setCustomerName(String customerName) {
        this.customerName = customerName;
    }

    public String getStartDate() {
        return startDate;
    }

    public void setStartDate(String startDate) {
        this.startDate = startDate;
    }

    public String getEndDate() {
        return endDate;
    }

    public void setEndDate(String endDate) {
        this.endDate = endDate;
    }
    @Override
    public String toString() {
        return
                car.toString() +
                ", customerName='" + customerName + '\'' +
                ", startDate='" + startDate + '\'' +
                ", endDate='" + endDate + '\''
                ;
    }

}
