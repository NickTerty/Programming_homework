package oop6;

public class Drug {
	protected String size;
	
	public Drug() {
		this.size = null;
	}
	
	public Drug(String size) {
		this.size = size;
	}
	
	public String getSize() {
		return this.size;
	}
}
