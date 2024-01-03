package Domain;

public class BP extends MedicalAnalysis{
    private int systolicValue;
    private int diastolicValue;

    public BP(String date, int systolicValue, int diastolicValue) {
        this.date = date;
        this.systolicValue = systolicValue;
        this.diastolicValue = diastolicValue;
    }

    public int getSystolicValue() {
        return systolicValue;
    }

    public int getDiastolicValue() {
        return diastolicValue;
    }

    @Override
    public boolean isResultOK() {
        return systolicValue >= 90 && systolicValue <= 119 && diastolicValue >= 60 && diastolicValue <= 79;
    }
    public String getDate(){
        return date;
    }
    @Override
    public String toString() {
        return "BP{" +
                "systolicValue=" + systolicValue +
                ", diastolicValue=" + diastolicValue +
                ", date='" + date + '\'' +
                '}';
    }
}
