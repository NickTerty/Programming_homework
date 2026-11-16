package atm;

public class Account {
	private double balance;
	
	public Account() {
		this.balance = 0;
	}
	public Account(double balence) {
		this.balance = balence;
	}
	
	public double getBalance(){
		return this.balance;
	}
	
	public void withdraw(double amount) throws InsufficientFundsException{
		if(amount <= 0) {
			throw new IllegalArgumentException("Amount must be greater than 0");
		}
		else if(amount > balance) {
			throw new InsufficientFundsException();
		}
		else {
			this.balance -= amount;
			System.out.println("Withdrawal successful!");
		}
	}
}
