package Service;

import Domain.MedicalAnalysis;
import Repository.MedicalAnalysisRepo;

import java.util.List;

public class MedicalAnalysisService {
    public MedicalAnalysisRepo repo;

    public MedicalAnalysisService(MedicalAnalysisRepo repo) {
        this.repo = repo;
    }
    public void addMedicalAnalysis(MedicalAnalysis medicalAnalysis){
        repo.add(medicalAnalysis);
    }
    public void deleteAtId(int id){
        repo.deleteAtId(id);
    }
    public Iterable<MedicalAnalysis> getAll(){
        return repo.getAll();
    }
}
