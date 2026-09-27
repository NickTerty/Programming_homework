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
        
        // Give five decks
        Card[] hand = myDeck.dealHand();
        int handScore = evaluateHand(hand, myDeck);

        // print
        System.out.println("--- Your hand ---");
        for(Card card : hand) {
        	System.out.println(card);
        }
        System.out.println("-----------------");
        printHand(hand, handScore);
    }
}
