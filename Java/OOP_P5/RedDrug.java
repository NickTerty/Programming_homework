package rpgGame_5;

public class RedDrug extends Drug{
	private static final int LARGE_ADD = 120;
	private static final int MED_ADD = 80;
	private static final int SMALL_ADD = 50;
	
	public int addLife;

	public RedDrug(String size) {
		super(size);
		
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
}
