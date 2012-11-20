
import java.util.Arrays;
import java.util.concurrent.ConcurrentLinkedQueue;


/* Rechnerarchitektur und Betriebssysteme �bung 4

    jlottner 200412, ykilcher 201211
    
    Die Mensa bekommt vom Koch frische Gerichte, giesst dann ein wenig Fett darueber (1 Sekunde lang), die Professoren k�nnen sie abholen, falls es welche hat.
    
    Falls es nichts mehr hat werden die Profs aufgefordert zu warten.
    
    Falls es schon 10 Gerichte hat, wird dem Koch befohlen, sich schlafen zu legen. Er wird dann geweckt, wenn es noch weniger als 3 Portionen hat.
    
    
    Hier die n�tigen Funktionen einf�gen!
    Verwenden sie die vorgegebenen Ausgaben!
*/

class Mensa 
{
    private ConcurrentLinkedQueue<String> meals = new ConcurrentLinkedQueue<>();
    private volatile boolean isWaiting = false;
    
    public synchronized void put(String[] meal)
    {
        System.out.println ("(" + System.currentTimeMillis() + ") Mensa: Ah, der Nachschub ist da. Noch ein bisschen Fett darüber giessen...");
       
        /*waiting for a second before adding the meals*/
        try 
        {
            Thread.sleep(1000);
        } catch (InterruptedException ex) {}
        
        /*Add all meals to the linked queue*/
        meals.addAll(Arrays.asList(meal));
        
        System.out.println ("(" + System.currentTimeMillis()+") Mensa: Neue Gerichte bereit. Koennt alle kommen!");
       
        /*should there be someone waiting, then we should wake him up*/
        this.notify();
        
        /*too many meals, let's send the chef to bed*/
        if(meals.size() > 9)
        {
            System.out.println ("(" + System.currentTimeMillis() + ") Mensa: !Mach mal ne Pause, Koch!");
            try 
            {
                isWaiting = true;
                this.wait();
            } catch (InterruptedException ex) {isWaiting = false;}
        }
    }
    
    public synchronized String get(int id)
            throws InterruptedException
    {
        /*No food available, let's wait*/
        if(meals.isEmpty())
        {
            System.out.println ("(" + System.currentTimeMillis() + ") " +"Mensa: Nichts mehr da, Herr Prof " + id + ", sie muessen warten!");
                this.wait();
        }
        
        
        System.out.println ("(" + System.currentTimeMillis() + ") Mensa: Voila, einmal " + meals.peek() + " fuer Prof " + id + ".");
        System.out.println ("(" + System.currentTimeMillis() + ") Mensa: Noch " + (meals.size()-1) + " Gerichte uebrig.");
        
        /*if there are less than 3 meals left (<4 because we've not removed the meal yet) and a sleeping chef, then we should wake him up*/
        if(meals.size() < 4 && isWaiting)
        {
            System.out.println ("(" + System.currentTimeMillis() + ") Mensa: !Aufwachen!");
            notify();
        }
        
        /*nom nom nom*/
        return meals.poll();
    }    
}
