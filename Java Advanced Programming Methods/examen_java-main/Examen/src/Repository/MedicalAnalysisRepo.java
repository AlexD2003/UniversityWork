package Repository;
import Domain.MedicalAnalysis;

import java.util.ArrayList;
import java.util.List;

public class MedicalAnalysisRepo {
    public List<MedicalAnalysis> medicalAnalysisList = new ArrayList<>();

    public void add(MedicalAnalysis medicalAnalysis){
        medicalAnalysisList.add(medicalAnalysis);
    }
    public void deleteAtId(int id){
        medicalAnalysisList.remove(id);
    }
    public void updateAtId(int id,MedicalAnalysis medicalAnalysis){
        medicalAnalysisList.set(id,medicalAnalysis);
    }
    public MedicalAnalysis getById(int id){
        return medicalAnalysisList.get(id);
    }
    public Iterable<MedicalAnalysis> getAll(){
        return medicalAnalysisList;
    }
    public MedicalAnalysisRepo() {
    }

}
