package rpgGame;

public class Witch {
	private String name;
	private int life;
	private int magic;
	
	public Witch() {
		this.name = null;
		this.life = 0;
		this.magic = 0;
	}
	
	public Witch(String name, int life, int magic){
		this.name = name;
		this.life = life;
		this.magic = magic;
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
	
	public void SmallFire(Warrior warrior) {
		if(this.magic >= 25) {
			warrior.setLife(warrior.getLife() - 40);;			
			this.magic -= 25;
			
			if(warrior.getLife() < 0) {
				System.out.println(warrior.getName() + " was killed by " + this.getName());
				System.exit(0);
			}
		}
		else {
			System.out.println(this.getName() + " doesn't have enough magic!");
		}
	}
	
	public void SmallFire(Witch witch) {
		if(this.magic >= 25) {
			witch.setLife(witch.getLife() - 40);
			this.magic -= 25;
			
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