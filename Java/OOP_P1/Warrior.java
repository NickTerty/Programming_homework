package rpgGame;

public class Warrior {
	private static final int MANA_REDUCT = 10;
	private static final int WARRIOR_LOSE_HP = 25;
	private static final int WITCH_LOSE_HP = 40;

	private String name;
	private int life;
	private int magic;
	
	public Warrior() {
		this.name = null;
		this.life = 0;
		this.magic = 0;
	}
	
	public Warrior(String name, int life, int magic){
		this.name = name;
		this.life = life;
		this.magic = magic;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getName() {
		return this.name;
	}
	
	public void setLife(int life) {
		this.life = life;
	}
	
	public int getLife() {
		return this.life;
	}
	
	public void setMagic(int magic) {
		this.magic = magic;
	}
	
	public int getMagic() {
		return this.magic;
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
