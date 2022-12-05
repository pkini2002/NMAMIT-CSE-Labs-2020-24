abstract class Emp{
    abstract int salary();
}

class CEO extends Emp{
    int basic=30000;
    int da=20000;
    float incr= (float) 0.20;

    int salary(){
        double total;
        total=basic+da+(incr*da);
        return (int)total;
    }
}

class TeamLead extends Emp{
    int basic=20000;
    int da=10000;
    float incr= (float) 0.10;

    int salary(){
        double total;
        total=basic+da+(incr*da);
        return (int) total;
    }
}

class SE extends Emp{
    int basic=15000;
    int da=5000;
    float incr= (float) 0.10;

    int salary(){
        double total;
        total=basic+da+(incr*da);
        return (int)total;
    }
}

class Trainee extends Emp{
    int stipend=15000;
    int salary(){
        return stipend;
    }
}

public class employee {
    public static void main(String[] args){
        CEO c=new CEO();
        TeamLead T=new TeamLead();
        SE s=new SE();
        Trainee t=new Trainee();

        System.out.println("The salary of CEO is: "+c.salary());
        System.out.println("The salary of Team lead is: "+T.salary());
        System.out.println("The salary of SE is: "+s.salary());
        System.out.println("The salary of Trainee is: "+t.salary());
    }
}
