package Domain;

public class BMI extends MedicalAnalysis{
    private double value;

    public BMI(String date, double value) {
        this.date = date;
        this.value = value;
    }

    public double getValue() {
        return value;
    }

    @Override
    public boolean isResultOK() {
        return value >= 18.5 && value <= 25;
    }

    @Override
    public String toString() {
        return "BMI{" +
                "value=" + value +
                ", date='" + date + '\'' +
                '}';
    }
}
