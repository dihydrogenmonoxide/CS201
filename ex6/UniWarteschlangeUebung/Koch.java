/* Rechnerarchitektur und Betriebssysteme Ãbung 4

    jlottner 200412, ykilcher 201211
    
    Der Koch macht immer 4 Gerichte aufs mal alle [pensum] Millisekunden und gibt sie der Mensa.
    
    Hier gar nichts Ã¤ndern!
*/

class Koch extends Thread {
    private Mensa mensa;
    private int pensum;
    private String[] repertoire = {"Gemuesebratling", "Fleischvogel", "Irgendwas an brauner Sosse", "Dosenravioli", "trockener Reis", "Fotzelschnitte", "Glutamat mit Nitratsalz"};
    java.util.Random random;
    
    public Koch (Mensa mensa, int pensum) {
    this.mensa = mensa;
    this.pensum = pensum;
    this.random = new java.util.Random();
    start ();
    }
  
    public void run () {
        String[] gerichte;
        int r;
        
        System.out.println ("(" + System.currentTimeMillis() + ")" +" Koch: gestartet ");
        while (true) {
            System.out.println ("(" + System.currentTimeMillis() + ")" +" Koch: (Brutzel! Brutzel!) ");
            try {sleep (pensum);} catch (InterruptedException e) {}
            gerichte = new String[4];
            r = random.nextInt(repertoire.length);
            for (int i=0; i<gerichte.length; i++) gerichte[i] = new String(repertoire[r]);
            
            System.out.println ("(" + System.currentTimeMillis() + ")" +" Koch: " + gerichte[0] + " zubereitet: en Guete! ");
            mensa.put (gerichte);
        }
    }
}
