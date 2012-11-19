    /* Rechnerarchitektur und Betriebssysteme Übung 4

   jlottner 200412, ykilcher 201211

   Die Mensa bekommt vom Koch frische Gerichte, giesst dann ein wenig Fett darueber (1 Sekunde lang), die Professoren können sie abholen, falls es welche hat.

   Falls es nichts mehr hat werden die Profs aufgefordert zu warten.

   Falls es schon 10 Gerichte hat, wird dem Koch befohlen, sich schlafen zu legen. Er wird dann geweckt, wenn es noch weniger als 3 Portionen hat.


   Hier die nötigen Funktionen einfügen!
   Verwenden sie die vorgegebenen Ausgaben!
   */
import java.util.*;

class Mensa extends Thread{
    

    LinkedList<String> input = new LinkedList<String>();
    LinkedList<String> output = new LinkedList<String>();

    public Mensa(){

            start();

    }

    public synchronized void put(String[] meals){
        //alle eingegangen Gerichte kommen in input
        System.out.println ("(" + System.currentTimeMillis() + ") Mensa: Ah, der Nachschub ist da. Noch ein bisschen Fett darüber giessen..."); 
        for(String meal:meals){
            input.push(meal); 

            if(input.size()+output.size() >= 10){
                System.out.println ("(" + System.currentTimeMillis() + ") Mensa: !Mach mal ne Pause, Koch!");
            }
        }
        notify();
    }

    public void run(){
        System.out.println("Mensa started");
        while(true){
            try{this.wait();}catch (InterruptedException e) {};
            if( 0 < input.size()){
                
                String meal = input.pop();
                System.out.println("add Oil");
                //kippe öl darüber
                try {Thread.sleep (1000);} catch (InterruptedException e) {}
                output.push(meal);
                System.out.println ("(" + System.currentTimeMillis()+") Mensa: Neue Gerichte bereit. Koennt alle kommen!");
            }
        }
    }

    public  synchronized String get(int id){
        System.out.println ("(" + System.currentTimeMillis() + ") Mensa: Noch " + output.size() + " Gerichte uebrig.");
        if(0 < output.size()){
            System.out.println ("(" + System.currentTimeMillis() + ") Mensa: Voila, einmal " + output.peek() + " fuer Prof " + id + ".");
            return output.pop();
        }else{
            System.out.println ("(" + System.currentTimeMillis() + ") " +"Mensa: Nichts mehr da, Herr Prof " + id + ", sie muessen warten!");
            try{this.wait();}catch (InterruptedException e) {};
            System.out.println ("(" + System.currentTimeMillis() + ") Mensa: Voila, einmal " + output.peek() + " fuer Prof " + id + ".");

            System.out.println ("(" + System.currentTimeMillis() + ") Mensa: !Aufwachen!");
            return output.pop();

        }
    }

}
