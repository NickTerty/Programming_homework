package rpgGame;
import java.security.SecureRandom;

public class Game {
	public static final int WARRIOR_HP = 400;
	public static final int WARRIOR_MANA = 100;
	
	public static final int WITCH_HP = 280;
	public static final int WITCH_MANA = 280;
	
	public static final int CHARACTER_CNT = 3;
	
	public static SecureRandom rand = new SecureRandom();
	
	public static void main(String[] args) {
		Warrior[] war = new Warrior[CHARACTER_CNT];
		Witch[] wit = new Witch[CHARACTER_CNT];
		
		war[0] = new Warrior("pdpd123", WARRIOR_HP, WARRIOR_MANA);
		war[1] = new Warrior("gordonmao", WARRIOR_HP, WARRIOR_MANA);
		war[2] = new Warrior("susfries", WARRIOR_HP, WARRIOR_MANA);
		
		wit[0] = new Witch("power002", WITCH_HP, WITCH_MANA);
		wit[1] = new Witch("luke920118", WITCH_HP, WITCH_MANA);
		wit[2] = new Witch("Richliu", WITCH_HP, WITCH_MANA);
		
		int rand1 = 0, rand2 = 0;
		while(true) {
			rand1 = rand.nextInt(CHARACTER_CNT);
			rand2 = rand.nextInt(CHARACTER_CNT);
			
			System.out.println(war[rand1].getName() + " hit " + wit[rand2].getName() + " ---");
			war[rand1].NewMoon(wit[rand2]);
			
			rand1 = rand.nextInt(CHARACTER_CNT);
			rand2 = rand.nextInt(CHARACTER_CNT);
			
			System.out.println(wit[rand1].getName() + " hit " + war[rand2].getName() + " ---");
			wit[rand1].SmallFire(war[rand2]);
		}
	}

}
