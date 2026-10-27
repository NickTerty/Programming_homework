package rpgGame_4_1;

public class RedDrug {
	private static final int LARGE_ADD = 120;
	private static final int MED_ADD = 80;
	private static final int SMALL_ADD = 50;
	
	private String size;
	public int addLife;
	
	public RedDrug() {
		this.size = null;
		this.addLife = 0;
	}
	
	public RedDrug(String size) {
		this.size = size;
		if(size.equals("Large")) {
			this.addLife = LARGE_ADD;
		}
		else if(size.equals("Medium")) {
			this.addLife = MED_ADD;
		}
		else if(size.equals("Small")) {
			this.addLife = SMALL_ADD;
		}
		else {
			this.addLife = 0;
		}
	}
	
	public String getSize() {
		return this.size;
	}
	
	public void setSize(String size) {
		this.size = size;
	}
}
