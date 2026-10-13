package rpgGame;

public class Warrior extends ROLE{
	private static final int MANA_REDUCT = 10;
	private static final int WARRIOR_LOSE_HP = 25;
	private static final int WITCH_LOSE_HP = 40;
	
	public Warrior() {		
	}
	
	public Warrior(String name, int life, int magic) {
		super(name, life, magic);
	}
	
	@Override
	public String toString() {
		return String.format("Warrior: %s ,HP: %d, Magic: %d.", this.getName(), this.getLife(), this.getMagic());
	}
	
	public void NewMoon(Warrior warrior) {
		if(this.magic >= MANA_REDUCT) {
			warrior.setLife(warrior.getLife() - WARRIOR_LOSE_HP);		
			this.magic -= MANA_REDUCT;
			
			if(warrior.getLife() < 0) {
				System.out.println(warrior.getName() + " was killed by " + this.getName());
				System.exit(0);
			}
		}
		else {
			System.out.println(this.getName() + " doesn't have enough magic!");
		}
	}
	
	public void NewMoon(Witch witch) {
		if(this.magic >= 10) {
			witch.setLife(witch.getLife() - WITCH_LOSE_HP);
			this.magic -= 10;
			
			if(witch.getLife() < 0) {
				System.out.println(witch.getName() + " was killed by " + this.getName());
				System.exit(0);
			}
		}
		else {
			System.out.println(this.getName() + " doesn't have enough magic!");
		}
	}
}
