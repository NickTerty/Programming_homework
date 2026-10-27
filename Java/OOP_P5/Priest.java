package rpgGame_5;

public class Priest extends Role{
	private static final int MANA_REDUCT = 20;
	private static final int WARRIOR_LOSE_HP = 30;
	private static final int WITCH_LOSE_HP = 50;
	private static final int PRIEST_LOSE_HP = 40;
	
	public Priest(String name, int life, int magic) {
		super(name, life, magic);
	}
	
	@Override
	public String toString() {
		return String.format("Priest: %s ,HP: %d, Magic: %d.", this.getName(), this.getLife(), this.getMagic());
	}
	
	public void Dark(Role role) {
		if(role instanceof Warrior warrior) {
			if(this.magic >= MANA_REDUCT) {
				warrior.setLife(warrior.getLife() - WARRIOR_LOSE_HP);;			
				this.magic -= MANA_REDUCT;
				
				if(warrior.getLife() <= 0) {
					System.out.println(warrior.getName() + " was killed by " + this.getName());
					System.exit(0);
				}
			}
			else {
				System.out.println(this.getName() + " doesn't have enough magic!");
			}
		}
		else if(role instanceof Witch witch) {
			if(this.magic >= MANA_REDUCT) {
				witch.setLife(witch.getLife() - WITCH_LOSE_HP);
				this.magic -= MANA_REDUCT;
				
				if(witch.getLife() <= 0) {
					System.out.println(witch.getName() + " was killed by " + this.getName());
					System.exit(0);
				}
			}
			else {
				System.out.println(this.getName() + " doesn't have enough magic!");
			}
		}
		else if(role instanceof Priest priest) {
			if(this.magic >= MANA_REDUCT) {
				priest.setLife(priest.getLife() - PRIEST_LOSE_HP);
				this.magic -= MANA_REDUCT;
				
				if(priest.getLife() <= 0) {
					System.out.println(priest.getName() + " was killed by " + this.getName());
					System.exit(0);
				}
			}
			else {
				System.out.println(this.getName() + " doesn't have enough magic!");
			}
		}
		else {
			System.out.println("Invalid Skill :: Unknown Role");
		}
	}
}
