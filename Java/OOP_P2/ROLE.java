package rpgGame;

public class ROLE {
	protected String name;
	protected int life;
	protected int magic;
	
	public ROLE() {
		this.name = null;
		this.life = 0;
		this.magic = 0;
	}
	
	public ROLE(String name, int life, int magic){
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
	
}
