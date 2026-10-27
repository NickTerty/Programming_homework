package rpgGame_4_1;

import java.security.SecureRandom;

public class Game {
	public static final int WARRIOR_HP = 400;
	public static final int WARRIOR_MANA = 100;
	
	public static final int WITCH_HP = 280;
	public static final int WITCH_MANA = 200;
	
	public static final int DRINK_RED_THRESHOLD = 100;
	public static final int DRINK_BLUE_THRESHOLD = 70;
	public static final int PROB = 10;
	
	public static enum DRUG_NAME{
		Large("Large"),
		Medium("Medium"),
		Small("Small");
		
		private final String description;
		
		DRUG_NAME(String description) {
	        this.description = description;
	    }
		
		public String getDescription() {
	        return this.description;
	    }
	}
	
	public static enum warriorPlayers{
		pdpd123,
		gordonmao,
		susfries
	}
	
	public static enum witchPlayers{
		power002,
		luke920118,
		Richliu
	}
	
	public static final int WARRIOR_CNT = warriorPlayers.values().length;
	public static final int WITCH_CNT = witchPlayers.values().length;
	
	public static SecureRandom rand = new SecureRandom();
	
	public static void main(String[] args) {
		Role[] character = new Role[WARRIOR_CNT + WITCH_CNT];
		
		for(int i = 0; i < WARRIOR_CNT; i++) {
			character[i] = new Warrior(warriorPlayers.values()[i].toString(), WARRIOR_HP, WARRIOR_MANA);
			System.out.println(character[i]);
		}
		
		System.out.println();
		
		for(int i = 0 + WARRIOR_CNT; i < WITCH_CNT + WARRIOR_CNT; i++) {
			character[i] = new Witch(witchPlayers.values()[i - WARRIOR_CNT].toString(), WITCH_HP, WITCH_MANA);
			System.out.println(character[i]);
		}
		
		System.out.println();
		
		int rand1 = 0, rand2 = 0;
		while(true) {
			int total = WARRIOR_CNT + WITCH_CNT;
			rand1 = rand.nextInt(total);
			rand2 = rand.nextInt(total);
			
			if(rand1 != rand2) {
				System.out.println(character[rand1].getName() + " hit " + character[rand2].getName() + " ---");
				
				if(character[rand1] instanceof Warrior) {
					((Warrior)character[rand1]).NewMoon(character[rand2]);
					
					if(character[rand1].getMagic() < DRINK_BLUE_THRESHOLD) {
						int prob = rand.nextInt(PROB);
						BlueDrug blue;
						
						if(prob == 0) {
							DRUG_NAME name = DRUG_NAME.Large;
							blue = new BlueDrug(name.getDescription());
						}
						else if(prob >= 1 && prob < 4) {
							DRUG_NAME name = DRUG_NAME.Medium;
							blue = new BlueDrug(name.getDescription());
						}
						else if(prob >= 4 && prob < 8) {
							DRUG_NAME name = DRUG_NAME.Small;
							blue = new BlueDrug(name.getDescription());
						}
						else {
							blue = null;
						}
						
						if(blue != null) {
							character[rand1].DrinkBlue(blue);
						}
						else {
							System.out.println(character[rand1].getName() + " did not drink the blue drug!");
						}
					}
					
					if(character[rand2].getLife() < DRINK_RED_THRESHOLD) {
						int prob = rand.nextInt(PROB);
						RedDrug red;
						
						if(prob == 0) {
							DRUG_NAME name = DRUG_NAME.Large;
							red = new RedDrug(name.getDescription());
						}
						else if(prob >= 1 && prob < 4) {
							DRUG_NAME name = DRUG_NAME.Medium;
							red = new RedDrug(name.getDescription());
						}
						else if(prob >= 4 && prob < 8) {
							DRUG_NAME name = DRUG_NAME.Small;
							red = new RedDrug(name.getDescription());
						}
						else {
							red = null;
						}
						
						if(red != null) {
							character[rand2].DrinkRed(red);
						}
						else {
							System.out.println(character[rand2].getName() + " did not drink the red drug!");
						}
					}
				}
				else if(character[rand1] instanceof Witch){
					((Witch)character[rand1]).SmallFire(character[rand2]);
					
					if(character[rand1].getMagic() < DRINK_BLUE_THRESHOLD) {
						int prob = rand.nextInt(PROB);
						BlueDrug blue;
						
						if(prob == 0) {
							DRUG_NAME name = DRUG_NAME.Large;
							blue = new BlueDrug(name.getDescription());
						}
						else if(prob >= 1 && prob < 4) {
							DRUG_NAME name = DRUG_NAME.Medium;
							blue = new BlueDrug(name.getDescription());
						}
						else if(prob >= 4 && prob < 8) {
							DRUG_NAME name = DRUG_NAME.Small;
							blue = new BlueDrug(name.getDescription());
						}
						else {
							blue = null;
						}
						
						if(blue != null) {
							character[rand1].DrinkBlue(blue);
						}
						else {
							System.out.println(character[rand1].getName() + " did not drink the blue drug!");
						}
					}
					
					if(character[rand2].getLife() < DRINK_RED_THRESHOLD) {
						int prob = rand.nextInt(PROB);
						RedDrug red;
						
						if(prob == 0) {
							DRUG_NAME name = DRUG_NAME.Large;
							red = new RedDrug(name.getDescription());
						}
						else if(prob >= 1 && prob < 4) {
							DRUG_NAME name = DRUG_NAME.Medium;
							red = new RedDrug(name.getDescription());
						}
						else if(prob >= 4 && prob < 8) {
							DRUG_NAME name = DRUG_NAME.Small;
							red = new RedDrug(name.getDescription());
						}
						else {
							red = null;
						}
						
						if(red != null) {
							character[rand2].DrinkRed(red);
						}
						else {
							System.out.println(character[rand2].getName() + " did not drink the red drug!");
						}
					}
				}
			}
		}
	}
}
