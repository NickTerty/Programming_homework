package rpgGame_5;

import java.security.SecureRandom;

public class Game {
	public static final int WARRIOR_HP = 400;
	public static final int WARRIOR_MANA = 100;
	
	public static final int WITCH_HP = 280;
	public static final int WITCH_MANA = 200;
	
	public static final int PRIEST_HP = 340;
	public static final int PRIEST_MANA = 160;
	
	public static final int DRINK_RED_THRESHOLD = 100;
	public static final int DRINK_BLUE_THRESHOLD = 70;
	public static final int PROB = 10;
	
	public static enum DRUG_NAME{
		Large,
		Medium,
		Small;
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
	
	public static enum priestPlayers{
		guava,
		tsumuoshi,
		Rainbow_Peter
	}
	
	public static final int WARRIOR_CNT = warriorPlayers.values().length;
	public static final int WITCH_CNT = witchPlayers.values().length;
	public static final int PRIEST_CNT = priestPlayers.values().length;
	
	public static SecureRandom rand = new SecureRandom();
	
	public static void main(String[] args) {
		Role[] character = new Role[WARRIOR_CNT + WITCH_CNT + PRIEST_CNT];
		
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
		
		for(int i = 0 + (WITCH_CNT + WARRIOR_CNT); i < WITCH_CNT + WARRIOR_CNT + PRIEST_CNT; i++) {
			character[i] = new Priest(priestPlayers.values()[i - (WITCH_CNT + WARRIOR_CNT)].toString(), PRIEST_HP, PRIEST_MANA);
			System.out.println(character[i]);
		}
		
		System.out.println();
		
		int rand1 = 0, rand2 = 0;
		while(true) {
			int total = WARRIOR_CNT + WITCH_CNT + PRIEST_CNT;
			rand1 = rand.nextInt(total);
			rand2 = rand.nextInt(total);
			
			if(rand1 != rand2) {
				System.out.println(character[rand1].getName() + " hit " + character[rand2].getName() + " ---");
				
				if(character[rand1] instanceof Warrior) {
					((Warrior)character[rand1]).NewMoon(character[rand2]);
				}
				else if(character[rand1] instanceof Witch){
					((Witch)character[rand1]).SmallFire(character[rand2]);
				}
				else if(character[rand1] instanceof Priest) {
					((Priest)character[rand1]).Dark(character[rand2]);
				}
				
				if(character[rand1].getMagic() < DRINK_BLUE_THRESHOLD) {
					int prob = rand.nextInt(PROB);
					Drug drink;
					
					if(prob == 0) {
						drink = new BlueDrug(DRUG_NAME.Large.toString());
					}
					else if(prob >= 1 && prob < 4) {
						drink = new BlueDrug(DRUG_NAME.Medium.toString());
					}
					else if(prob >= 4 && prob < 8) {
						drink = new BlueDrug(DRUG_NAME.Small.toString());
					}
					else {
						drink = null;
					}
					
					if(drink != null) {
						character[rand1].Drink(drink);
					}
					else {
						System.out.println(character[rand1].getName() + " did not drink the blue drug!");
					}
				}
				
				if(character[rand2].getLife() < DRINK_RED_THRESHOLD) {
					int prob = rand.nextInt(PROB);
					Drug drink;
					
					if(prob == 0) {
						drink = new BlueDrug(DRUG_NAME.Large.toString());
					}
					else if(prob >= 1 && prob < 4) {
						drink = new BlueDrug(DRUG_NAME.Medium.toString());
					}
					else if(prob >= 4 && prob < 8) {
						drink = new BlueDrug(DRUG_NAME.Small.toString());
					}
					else {
						drink = null;
					}
					
					if(drink != null) {
						character[rand2].Drink(drink);
					}
					else {
						System.out.println(character[rand2].getName() + " did not drink the red drug!");
					}
				}
			}
		}
	}
}
