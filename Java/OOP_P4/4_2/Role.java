package rpgGame_4_2;

public class Role {
	
	protected String name;
	protected int life;
	protected int magic;
	
	public Role() {
		this.name = null;
		this.life = 0;
		this.magic = 0;
	}
	
	public Role(String name, int life, int magic){
		this.name = name;
		this.life = life;
		this.magic = magic;
	}
	
	public String getName() {
		return this.name;
	}
	
	public int getLife() {
		return this.life;
	}
	
	public int getMagic() {
		return this.magic;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void setLife(int life) {
		this.life = life;
	}
	
	public void setMagic(int magic) {
		this.magic = magic;
	}
	
	public void Drink(Drug D) {
		if(D instanceof RedDrug R) {
			this.setLife(this.life + R.addLife);
			System.out.println(name + " drinks RED " + R.getSize() + "! +" + R.addLife + " life.");
		}
		else if(D instanceof BlueDrug B) {
			this.setMagic(this.magic + B.addMagic);
			System.out.println(name + " drinks BLUE " + B.getSize() + "! +" + B.addMagic + " Magic.");
		}
	}
	
}
