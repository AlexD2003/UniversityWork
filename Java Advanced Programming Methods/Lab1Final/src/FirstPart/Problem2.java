package FirstPart;

import static java.lang.Long.MIN_VALUE;

public class Problem2 {
    public double printMaxDouble(String[] args){
        double[] doubleArray = new double[args.length];
        for(int i=0;i<args.length;i++){
            doubleArray[i]=Double.parseDouble(args[i]);
        }
        double min=MIN_VALUE;
        double newMax=0;
        for(int i=0;i<doubleArray.length;i++){
            if(doubleArray[i]>=min){
                newMax=doubleArray[i];
            }
        }
        return newMax;
    }
}
