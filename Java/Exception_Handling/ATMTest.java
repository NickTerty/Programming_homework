package atm;
import java.util.Scanner;
import java.util.InputMismatchException;

public class ATMTest {
	public static final double MONEY = 1000;
	public static Scanner scanner = new Scanner(System.in);
	
	public static void main(String[] args) {
		Account account = new Account(MONEY);
		
		do {
			try {
				System.out.println("Enter withdrawal amount (0 to exit):");
				if(!scanner.hasNextDouble()) {
					scanner.nextLine();
					throw new InputMismatchException("Please enter a number");
				}
				
				double withdraw = scanner.nextDouble();
				scanner.nextLine();
				if(withdraw == 0) {
					System.out.println("Thank you for using the ATM. Goodbye!");
					System.exit(0);
				}
				else {
					account.withdraw(withdraw);
				}
			}
			catch(InputMismatchException e) {
				System.err.printf("Error: %s%n", e.getMessage());
				// scanner.nextLine();
			}
			catch(IllegalArgumentException e) {
				System.err.printf("Error: %s%n", e.getMessage());
			}
			catch(InsufficientFundsException e) {
				System.err.printf("Error: %s Current balance: %.2f%n", e.getMessage(), account.getBalance());
			}
			finally {
				System.out.println("Current balance: " + account.getBalance());
				System.out.println();
			}
		}while(true);
	}

}
