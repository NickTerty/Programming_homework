package rpgGame;
import java.security.SecureRandom;

public class Game {
	public static final int WARRIOR_HP = 400;
	public static final int WARRIOR_MANA = 100;
	
	public static final int WITCH_HP = 280;
	public static final int WITCH_MANA = 200;
	
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
		Warrior[] war = new Warrior[WARRIOR_CNT];
		Witch[] wit = new Witch[WITCH_CNT];
		
		for(int i = 0; i < WARRIOR_CNT; i++) {
			war[i] = new Warrior(warriorPlayers.values()[i].toString(), WARRIOR_HP, WARRIOR_MANA);
			System.out.println(war[i]);
		}
		
		System.out.println();
		
		for(int i = 0; i < WITCH_CNT; i++) {
			wit[i] = new Witch(witchPlayers.values()[i].toString(), WITCH_HP, WITCH_MANA);
			System.out.println(wit[i]);
		}
		
		System.out.println();
		
		int rand1 = 0, rand2 = 0;
		while(true) {
			rand1 = rand.nextInt(WARRIOR_CNT);
			rand2 = rand.nextInt(WITCH_CNT);
			
			System.out.println(war[rand1].getName() + " hit " + wit[rand2].getName() + " ---");
			war[rand1].NewMoon(wit[rand2]);
			
			rand1 = rand.nextInt(WITCH_CNT);
			rand2 = rand.nextInt(WARRIOR_CNT);
			
			System.out.println(wit[rand1].getName() + " hit " + war[rand2].getName() + " ---");
			wit[rand1].SmallFire(war[rand2]);
		}
	}

}
