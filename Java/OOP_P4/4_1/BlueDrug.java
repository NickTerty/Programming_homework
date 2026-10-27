package rpgGame_4_1;

public class BlueDrug {
	private static final int LARGE_ADD = 100;
	private static final int MED_ADD = 60;
	private static final int SMALL_ADD = 30;
	
	private String size;
	public int addMagic;
	
	public BlueDrug() {
		this.size = null;
		this.addMagic = 0;
	}
	
	public BlueDrug(String size) {
		this.size = size;
		if(size.equals("Large")) {
			this.addMagic = LARGE_ADD;
		}
		else if(size.equals("Medium")) {
			this.addMagic = MED_ADD;
		}
		else if(size.equals("Small")) {
			this.addMagic = SMALL_ADD;
		}
		else {
			this.addMagic = 0;
		}
	}
	
	public String getSize() {
		return this.size;
	}
	
	public void setSize(String size) {
		this.size = size;
	}
}
