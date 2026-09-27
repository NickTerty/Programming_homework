package card;

public class PokerTest {
	public static int evaluateHand(Card[] hand, DeckOfCards deck) {
		// flush&Straight
		if(deck.hasFlush(hand) && deck.hasStraight(hand)) {
			return 8;
		}
		if(deck.hasFourOfAKind(hand)) {
			return 7;
		}
		if(deck.hasFullHouse(hand)) {
			return 6;
		}
		if(deck.hasFlush(hand)) {
			return 5;
		}
		if(deck.hasStraight(hand)) {
			return 4;
		}
		if(deck.hasThreeOfAKind(hand)) {
			return 3;
		}
		if(deck.hasTwoPair(hand)) {
			return 2;
		}
		if(deck.hasPair(hand)) {
			return 1;
		}
		return 0;
	}
	
	public static void printHand(Card[] hand, int handScore) {
		System.out.println("=== Card Type on Hand ===");
		switch(handScore) {
			case 8:
				System.out.println("Straight Flush");
				break;
			case 7:
				System.out.println("Four of a Kind");
				break;
			case 6:
				System.out.println("Full House");
				break;
			case 5:
				System.out.println("Flush");
				break;
			case 4:
				System.out.println("Straight");
				break;
			case 3:
				System.out.println("Three of a Kind");
				break;
			case 2:
				System.out.println("Two Pair");
				break;
			case 1:
				System.out.println("One Pair");
				break;
			default:
				System.out.println("High Card"); // wu long
				break;
		}
		System.out.println("=========================");
	}
	
	
	public static void main(String[] args){
        DeckOfCards myDeck = new DeckOfCards();
        myDeck.shuffle(); // place Cards in random order
        
        Card[] hand1 = myDeck.dealHand();
        Card[] hand2 = myDeck.dealHand();
        
        int hand1Score = evaluateHand(hand1, myDeck);
        int hand2Score = evaluateHand(hand2, myDeck);
        
        System.out.println("--- Players hand ---");
        System.out.println("=== Player 1 ===");
        for(Card card : hand1) {
        	System.out.println(card);
        }
        printHand(hand1, hand1Score);
        
        System.out.println("");
        
        System.out.println("=== Player 2 ===");
        for(Card card : hand2) {
        	System.out.println(card);
        }
        printHand(hand2, hand2Score);
        
        System.out.println("--------------------");
        
        // Compare        
        System.out.println("The Result is...");
        if(hand1Score > hand2Score) {
        	System.out.println("Player 1 wins!");
        }
        else if(hand1Score < hand2Score) {
        	System.out.println("Player 2 wins!");
        }
        else {
        	System.out.println("Tie! (Same card type)");
        }
    }
}
