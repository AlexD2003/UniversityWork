package FirstPart;

import static java.lang.Math.sqrt;

public class Problem1 {
    public boolean checkPrime(int x){
        if(x==1)
            return false;
        boolean check=false;
        for(int i=2;i<=sqrt(x)+1;i++){
            if(x%i==0)
                check=true;
        }
        if(check==false || x==2){
            return true;
        }
        else
            return false;
    }

    public void sortPrimes(int[] args){
        for(int i=0;i<args.length;i++){
            if(checkPrime(args[i]))
                System.out.println(args[i]);
        }

    }
}
