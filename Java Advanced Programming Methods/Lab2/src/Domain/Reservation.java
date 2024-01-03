package Domain;

//reservation class with getters,setters and defined methods
public class Reservation implements Identifiable{
    private int id;
    private Car car;
    private String customerName;

    private String startDate;
    private String endDate;
    private static int reservationId=0;
    public Reservation(Car car, String customerName, String startDate, String endDate) {
        this.car = car;
        this.customerName = customerName;
        this.startDate = startDate;
        this.endDate = endDate;
        this.id=generateId();
    }


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
                "Reservation id:"+this.id+" "+car.toString2()+" " +", customerName='" + customerName + '\'' + ", startDate='" + startDate + '\'' + ", endDate='" + endDate + '\''+"\n"
                ;
    }

    public int generateId(){
        reservationId++;
        return reservationId;
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
