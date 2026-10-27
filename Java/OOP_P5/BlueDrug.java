package rpgGame_5;

public class BlueDrug extends Drug{
	private static final int LARGE_ADD = 100;
	private static final int MED_ADD = 60;
	private static final int SMALL_ADD = 30;

	public int addMagic;
	
	public BlueDrug(String size) {
		super(size);
		
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
}
