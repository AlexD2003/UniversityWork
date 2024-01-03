package Domain;

public class MedicalAnalysis {
    protected String date;

    boolean isResultOK() {
        return false;
    }

    public String getDate(){
        return date;
    }
    public String toString(){
        return date;
    }
}
